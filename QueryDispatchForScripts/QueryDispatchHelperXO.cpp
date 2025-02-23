// QueryDispatchHelperXO.cpp : Implementation of CQueryDispatchHelperXO

#include "pch.h"
#include "QueryDispatchHelperXO.h"

#include "AutoReleaseTypeAttr.h"

#include <comdef.h>

#include <regex>
#include <string>
#include <map>

// CQueryDispatchHelperXO

STDMETHODIMP CQueryDispatchHelperXO::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* const arr[] = 
	{
		&IID_IQueryDispatchHelper
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}


static bool IsValidGUID(const std::wstring& guid) 
{
	std::wregex guidRegex(LR"(\{?[0-9a-fA-F]{8}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{12}\}?)", std::regex::icase);
	return std::regex_match(guid, guidRegex);
}

static HRESULT FindInterfaceByName(IUnknown* pUnknown, const _bstr_t& interfaceName, IID& iid)
{
	if (!pUnknown)
		return E_POINTER;

	// Get IProvideClassInfo
	IProvideClassInfo* pClassInfo = NULL;
	HRESULT hr = pUnknown->QueryInterface(IID_IProvideClassInfo, (void**)&pClassInfo);
	if (FAILED(hr))
		return hr;
	IProvideClassInfoPtr classInfo;
	classInfo.Attach(pClassInfo); // for automatic release
	//return E_FAIL;

	// Get ITypeInfo
	ITypeInfo* pTypeInfo = NULL;
	hr = pClassInfo->GetClassInfo(&pTypeInfo);
	if (FAILED(hr))
		return hr;
	ITypeInfoPtr typeInfo;
	typeInfo.Attach(pTypeInfo); // for automatic release

	// Get TYPEATTR
	TYPEATTR* pTypeAttr = nullptr;
	hr = pTypeInfo->GetTypeAttr(&pTypeAttr);
	if (FAILED(hr))
		return hr;
	AutoReleaseTypeAttr ARTypeAttr(pTypeInfo, pTypeAttr);

	bool found = false;
	for (UINT i = 0; i < pTypeAttr->cImplTypes && !found; i++)
	{
		HREFTYPE hRefType;
		if (SUCCEEDED(pTypeInfo->GetRefTypeOfImplType(i, &hRefType)))
		{
			ITypeInfo* pRefTypeInfo = NULL;
			if (SUCCEEDED(pTypeInfo->GetRefTypeInfo(hRefType, &pRefTypeInfo)))
			{
				ITypeInfoPtr refTypeInfo;
				refTypeInfo.Attach(pRefTypeInfo); // for automatic release
				TYPEATTR* pRefTypeAttr = NULL;
				if (SUCCEEDED(pRefTypeInfo->GetTypeAttr(&pRefTypeAttr)))
				{
					_bstr_t bstr_tName;
					if (SUCCEEDED(pRefTypeInfo->GetDocumentation(MEMBERID_NIL, bstr_tName.GetAddress(), NULL, NULL, NULL)))
					{
						if (_wcsicmp(bstr_tName, interfaceName) == 0)
						{
							// Found matching interface name, copy IID
							iid = pRefTypeAttr->guid;
							found = true;
						}
					}
					AutoReleaseTypeAttr ARTypeAttr(pRefTypeInfo, pRefTypeAttr);
				}
			}
		}
	}
	return found ? S_OK : E_FAIL;
}

static HRESULT GetIDispatchMethods(IDispatch* pDisp,
	std::map<long, std::wstring>& methodsMap)
{
	HRESULT hr = S_OK;

	CComPtr<IDispatch> spDisp(pDisp);
	if (!spDisp)
		return E_INVALIDARG;

	CComPtr<ITypeInfo> spTypeInfo;
	hr = spDisp->GetTypeInfo(0, 0, &spTypeInfo);
	if (SUCCEEDED(hr) && spTypeInfo)
	{
		TYPEATTR* pTatt = nullptr;
		hr = spTypeInfo->GetTypeAttr(&pTatt);
		if (SUCCEEDED(hr) && pTatt)
		{
			FUNCDESC* fd = nullptr;
			for (int i = 0; i < pTatt->cFuncs; ++i)
			{
				hr = spTypeInfo->GetFuncDesc(i, &fd);
				if (SUCCEEDED(hr) && fd)
				{
					CComBSTR funcName;
					spTypeInfo->GetDocumentation(fd->memid, &funcName, nullptr, nullptr, nullptr);
					if (funcName.Length() > 0)
					{
						methodsMap[fd->memid] = funcName;
					}

					spTypeInfo->ReleaseFuncDesc(fd);
				}
			}

			spTypeInfo->ReleaseTypeAttr(pTatt);
		}
	}

	return hr;
}

STDMETHODIMP CQueryDispatchHelperXO::QueryDispatch(IDispatch* I, BSTR IIDStr, IDispatch** ret)
{
	if (!I
		|| !IIDStr
		|| !ret)
		return E_POINTER;

	//for (int i = 0; i < 1001; i++)
	//{
	//	std::map<long, std::wstring> methodsMap;
	//	GetIDispatchMethods(I, methodsMap);
	//}
	//return E_FAIL;

	IID iid;
	HRESULT hr = S_OK;

	_bstr_t iid_bstr_t = IIDStr;
	if (!IsValidGUID((wchar_t*)iid_bstr_t))
	{
		// des leaks de BSTR (au moins) semblent avoir lieu, bien que les TYPEATTR* soient désormais releasés correctement (hopefully) dans FindInterfaceByName().
		//for (int i=0; i<1000000; i++)
		hr = FindInterfaceByName(I, IIDStr, iid); 
	}
	else
	{
		int len = iid_bstr_t.length();
		if (len > 0)
		{
			if (IIDStr[0] != '{'
				&& IIDStr[len - 1] != '}')
				iid_bstr_t = L"{" + iid_bstr_t + "}";
		}
		hr = IIDFromString(iid_bstr_t, &iid);
		if (FAILED(hr))
			return hr;
	}
	IUnknown* iu = NULL;
	hr = I->QueryInterface(iid, (void**) &iu);
	if (FAILED(hr))
		return hr;
	
	hr = iu->QueryInterface(iid, (void**)ret);
	iu->Release(); // DO NOT forget to release the IUnknown (iu) since we are using raw interfaces and not smart pointers here !
	if (FAILED(hr))
		return hr;

	return S_OK;
}
