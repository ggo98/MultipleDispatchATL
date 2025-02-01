// QueryDispatchHelperXO.cpp : Implementation of CQueryDispatchHelperXO

#include "pch.h"
#include "QueryDispatchHelperXO.h"

#include <comdef.h>

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


STDMETHODIMP CQueryDispatchHelperXO::QueryDispatch(IDispatch* I, BSTR IIDStr, IDispatch** ret)
{
	_bstr_t iid_bstr_t = IIDStr;
	int len = iid_bstr_t.length();
	if (len > 0)
	{
		if (IIDStr[0] != '{'
			&& IIDStr[len-1] != '}')
			iid_bstr_t = L"{" + iid_bstr_t + "}";
	}
	IID iid;
	HRESULT hr = IIDFromString(iid_bstr_t, &iid);
	if (FAILED(hr))
		return hr;
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
