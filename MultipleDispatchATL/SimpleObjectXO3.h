//// SimpleObjectXO3.h : Declaration of the CSimpleObjectXO3
//
//#pragma once
//#include "resource.h"       // main symbols
//
//
//
//#include "MultipleDispatchATL_i.h"
//
//
//
//#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
//#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
//#endif
//
//using namespace ATL;
//
//
//// CSimpleObjectXO3
//
//class ATL_NO_VTABLE CSimpleObjectXO3 :
//	public CComObjectRootEx<CComSingleThreadModel>,
//	public CComCoClass<CSimpleObjectXO3, &CLSID_SimpleObjectXO3>,
//	public IDispatchImpl<ISomeOtherInterface, &IID_ISomeOtherInterface, &LIBID_MultipleDispatchATLLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
//{
//public:
//	CSimpleObjectXO3()
//	{
//	}
//
//DECLARE_REGISTRY_RESOURCEID(108)
//
//
//BEGIN_COM_MAP(CSimpleObjectXO3)
//	COM_INTERFACE_ENTRY(ISomeOtherInterface)
//	COM_INTERFACE_ENTRY(IDispatch)
//END_COM_MAP()
//
//
//
//	DECLARE_PROTECT_FINAL_CONSTRUCT()
//
//	HRESULT FinalConstruct()
//	{
//		return S_OK;
//	}
//
//	void FinalRelease()
//	{
//	}
//
//public:
//
//
//
//	STDMETHOD(SomeOtherMethod)();
//};
//
////OBJECT_ENTRY_AUTO(__uuidof(SimpleObjectXO3), CSimpleObjectXO3)
