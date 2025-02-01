// SimpleObjectXO.h : Declaration of the CSimpleObjectXO

#pragma once
#include "resource.h"       // main symbols



#include "MultipleDispatchATL_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CSimpleObjectXO

class ATL_NO_VTABLE CSimpleObjectXO :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CSimpleObjectXO, &CLSID_SimpleObjectXO>,
	public ISupportErrorInfo,
	//public IDispatchImpl<ISimpleObject, &IID_ISimpleObject, &LIBID_MultipleDispatchATLLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	// add-2nd-interface
	public IDispatchImpl<ISimpleObject2, &IID_ISimpleObject2, &LIBID_MultipleDispatchATLLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	// add-3rd-interface
	public IDispatchImpl<ISomeOtherInterface, &IID_ISomeOtherInterface, &LIBID_MultipleDispatchATLLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CSimpleObjectXO()
	{
	}

DECLARE_REGISTRY_RESOURCEID(106)


BEGIN_COM_MAP(CSimpleObjectXO)
	COM_INTERFACE_ENTRY(ISimpleObject)

	//COM_INTERFACE_ENTRY(IDispatch)
	// add-2nd-interface
	COM_INTERFACE_ENTRY(ISimpleObject2)
	COM_INTERFACE_ENTRY2(IDispatch, ISimpleObject2)

	// add-3rd-interface
	COM_INTERFACE_ENTRY(ISomeOtherInterface)
	COM_INTERFACE_ENTRY2(IDispatch, ISomeOtherInterface)

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



	STDMETHOD(Method1)(BSTR str, BSTR* ret);

	// add-2nd-interface
	STDMETHOD(Method2)(int n, int* ret);

	// add-3rd-interface
	STDMETHOD(SomeOtherMethod)(void);
};

OBJECT_ENTRY_AUTO(__uuidof(SimpleObjectXO), CSimpleObjectXO)
