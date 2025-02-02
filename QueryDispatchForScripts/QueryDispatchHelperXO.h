// QueryDispatchHelperXO.h : Declaration of the CQueryDispatchHelperXO

#pragma once
#include "resource.h"       // main symbols



#include "QueryDispatchForScripts_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CQueryDispatchHelperXO

class ATL_NO_VTABLE CQueryDispatchHelperXO :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CQueryDispatchHelperXO, &CLSID_QueryDispatchHelperXO>,
	public ISupportErrorInfo,
	public IDispatchImpl<IQueryDispatchHelper, &IID_IQueryDispatchHelper, &LIBID_QueryDispatchForScriptsLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IProvideClassInfoImpl<&CLSID_QueryDispatchHelperXO>
{
public:
	CQueryDispatchHelperXO()
	{
	}

	~CQueryDispatchHelperXO()
	{
		::MessageBox(0, L"CQueryDispatchHelperXO dtor", L"", MB_SERVICE_NOTIFICATION);
	}

DECLARE_REGISTRY_RESOURCEID(106)


BEGIN_COM_MAP(CQueryDispatchHelperXO)
	COM_INTERFACE_ENTRY(IQueryDispatchHelper)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
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



	STDMETHOD(QueryDispatch)(IDispatch* I, BSTR IIDStr, IDispatch** ret);
};

OBJECT_ENTRY_AUTO(__uuidof(QueryDispatchHelperXO), CQueryDispatchHelperXO)
