

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0628 */
/* at Mon Jan 18 19:14:07 2038
 */
/* Compiler settings for QueryDispatchForScripts.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0628 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __QueryDispatchForScripts_i_h__
#define __QueryDispatchForScripts_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if defined(_CONTROL_FLOW_GUARD_XFG)
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef __IQueryDispatchHelper_FWD_DEFINED__
#define __IQueryDispatchHelper_FWD_DEFINED__
typedef interface IQueryDispatchHelper IQueryDispatchHelper;

#endif 	/* __IQueryDispatchHelper_FWD_DEFINED__ */


#ifndef __QueryDispatchHelperXO_FWD_DEFINED__
#define __QueryDispatchHelperXO_FWD_DEFINED__

#ifdef __cplusplus
typedef class QueryDispatchHelperXO QueryDispatchHelperXO;
#else
typedef struct QueryDispatchHelperXO QueryDispatchHelperXO;
#endif /* __cplusplus */

#endif 	/* __QueryDispatchHelperXO_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IQueryDispatchHelper_INTERFACE_DEFINED__
#define __IQueryDispatchHelper_INTERFACE_DEFINED__

/* interface IQueryDispatchHelper */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IQueryDispatchHelper;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("cb1e0039-d4a3-43a8-84ed-1d8760caff58")
    IQueryDispatchHelper : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE QueryDispatch( 
            /* [in] */ IDispatch *I,
            /* [in] */ BSTR IIDStr,
            /* [retval][out] */ IDispatch **ret) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IQueryDispatchHelperVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IQueryDispatchHelper * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IQueryDispatchHelper * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IQueryDispatchHelper * This);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfoCount)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IQueryDispatchHelper * This,
            /* [out] */ UINT *pctinfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetTypeInfo)
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IQueryDispatchHelper * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        DECLSPEC_XFGVIRT(IDispatch, GetIDsOfNames)
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IQueryDispatchHelper * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        DECLSPEC_XFGVIRT(IDispatch, Invoke)
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IQueryDispatchHelper * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        DECLSPEC_XFGVIRT(IQueryDispatchHelper, QueryDispatch)
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *QueryDispatch )( 
            IQueryDispatchHelper * This,
            /* [in] */ IDispatch *I,
            /* [in] */ BSTR IIDStr,
            /* [retval][out] */ IDispatch **ret);
        
        END_INTERFACE
    } IQueryDispatchHelperVtbl;

    interface IQueryDispatchHelper
    {
        CONST_VTBL struct IQueryDispatchHelperVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IQueryDispatchHelper_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IQueryDispatchHelper_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IQueryDispatchHelper_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IQueryDispatchHelper_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IQueryDispatchHelper_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IQueryDispatchHelper_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IQueryDispatchHelper_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IQueryDispatchHelper_QueryDispatch(This,I,IIDStr,ret)	\
    ( (This)->lpVtbl -> QueryDispatch(This,I,IIDStr,ret) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IQueryDispatchHelper_INTERFACE_DEFINED__ */



#ifndef __QueryDispatchForScriptsLib_LIBRARY_DEFINED__
#define __QueryDispatchForScriptsLib_LIBRARY_DEFINED__

/* library QueryDispatchForScriptsLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_QueryDispatchForScriptsLib;

EXTERN_C const CLSID CLSID_QueryDispatchHelperXO;

#ifdef __cplusplus

class DECLSPEC_UUID("fa10125b-887b-424f-a69b-37d0df6e22f9")
QueryDispatchHelperXO;
#endif
#endif /* __QueryDispatchForScriptsLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


