// dllmain.h : Declaration of module class.

class CQueryDispatchForScriptsModule : public ATL::CAtlDllModuleT< CQueryDispatchForScriptsModule >
{
public :
	DECLARE_LIBID(LIBID_QueryDispatchForScriptsLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_QUERYDISPATCHFORSCRIPTS, "{23747e63-7faa-4dbf-91e1-453f191e7525}")
};

extern class CQueryDispatchForScriptsModule _AtlModule;
