// dllmain.h : Declaration of module class.

class CMultipleDispatchATLModule : public ATL::CAtlDllModuleT< CMultipleDispatchATLModule >
{
public :
	DECLARE_LIBID(LIBID_MultipleDispatchATLLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_MULTIPLEDISPATCHATL, "{8deb85d1-cbbc-4cda-bfed-6e348e79df19}")
};

extern class CMultipleDispatchATLModule _AtlModule;
