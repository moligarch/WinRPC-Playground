

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0626 */
/* at Tue Jan 19 06:44:07 2038
 */
/* Compiler settings for plugin.idl:
    Oicf, W3, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0626 
    protocol : all , ms_ext, app_config, c_ext, robust
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


#ifndef __rpc_plugin_h_h__
#define __rpc_plugin_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if _CONTROL_FLOW_GUARD_XFG
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __Plugin_INTERFACE_DEFINED__
#define __Plugin_INTERFACE_DEFINED__

/* interface Plugin */
/* [explicit_handle][version][uuid] */ 

int RpcStart( 
    /* [in] */ handle_t IDL_handle);

int RpcShutdown( 
    /* [in] */ handle_t IDL_handle);

boolean RpcPluginHealthCheck( 
    /* [in] */ handle_t IDL_handle);

void RpcCommandPlugin( 
    /* [in] */ handle_t IDL_handle,
    /* [in] */ int command,
    /* [string][out][in] */ unsigned char *result);



extern RPC_IF_HANDLE Plugin_v1_0_c_ifspec;
extern RPC_IF_HANDLE Plugin_v1_0_s_ifspec;
#endif /* __Plugin_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


