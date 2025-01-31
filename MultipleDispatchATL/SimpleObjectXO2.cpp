// SimpleObjectXO2.cpp : Implementation of CSimpleObjectXO2

#include "pch.h"
#include "SimpleObjectXO2.h"


// CSimpleObjectXO2

STDMETHODIMP CSimpleObjectXO2::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* const arr[] = 
	{
		&IID_ISimpleObject2
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}


STDMETHODIMP CSimpleObjectXO2::Method2(int n, int* ret)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your dispatch handler code here

	return S_OK;
}
