// SimpleObjectXO2.h : Declaration of the CSimpleObjectXO2
/* NOTE: classe pas utilisée, générée pour avoir du code généré automatiquement (.idl, ...) */

#pragma once
#include "resource.h"       // main symbols



#include "MultipleDispatchATL_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CSimpleObjectXO2

class ATL_NO_VTABLE CSimpleObjectXO2 :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CSimpleObjectXO2, &CLSID_SimpleObjectXO2>,
	public ISupportErrorInfo,
	public IDispatchImpl<ISimpleObject2, &IID_ISimpleObject2, &LIBID_MultipleDispatchATLLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CSimpleObjectXO2()
	{
	}

DECLARE_REGISTRY_RESOURCEID(107)


BEGIN_COM_MAP(CSimpleObjectXO2)
	COM_INTERFACE_ENTRY(ISimpleObject2)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:



	STDMETHOD(Method2)(int n, int* ret);
};

//OBJECT_ENTRY_AUTO(__uuidof(SimpleObjectXO2), CSimpleObjectXO2)
