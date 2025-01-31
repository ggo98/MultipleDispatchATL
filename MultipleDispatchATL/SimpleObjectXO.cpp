// SimpleObjectXO.cpp : Implementation of CSimpleObjectXO

#include "pch.h"
#include "SimpleObjectXO.h"

// CSimpleObjectXO

STDMETHODIMP CSimpleObjectXO::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* const arr[] = 
	{
		&IID_ISimpleObject,
		&IID_ISimpleObject2,
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}


STDMETHODIMP CSimpleObjectXO::Method1(BSTR str, BSTR* ret)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	_bstr_t bstrt = str;
	bstrt = L"Hello " + bstrt;
	*ret = bstrt.Detach();

	return S_OK;
}

STDMETHODIMP CSimpleObjectXO::Method2(int n, int* ret)
{
	*ret = n + 2;

	return S_OK;
}
