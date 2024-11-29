

/* this ALWAYS GENERATED file contains the RPC client stubs */


 /* File created by MIDL compiler version 8.01.0626 */
/* at Tue Jan 19 06:44:07 2038
 */
/* Compiler settings for controller.idl:
    Oicf, W3, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0626 
    protocol : all , ms_ext, app_config, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if defined(_M_AMD64)


#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/

#include <string.h>

#include "rpc_controller_h.h"

#define TYPE_FORMAT_STRING_SIZE   17                                
#define PROC_FORMAT_STRING_SIZE   49                                
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _controller_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } controller_MIDL_TYPE_FORMAT_STRING;

typedef struct _controller_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } controller_MIDL_PROC_FORMAT_STRING;

typedef struct _controller_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } controller_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};

static const RPC_SYNTAX_IDENTIFIER  _NDR64_RpcTransferSyntax = 
{{0x71710533,0xbeba,0x4937,{0x83,0x19,0xb5,0xdb,0xef,0x9c,0xcc,0x36}},{1,0}};

#if defined(_CONTROL_FLOW_GUARD_XFG)
#define XFG_TRAMPOLINES(ObjectType)\
static unsigned long ObjectType ## _UserSize_XFG(unsigned long * pFlags, unsigned long Offset, void * pObject)\
{\
return  ObjectType ## _UserSize(pFlags, Offset, pObject);\
}\
static unsigned char * ObjectType ## _UserMarshal_XFG(unsigned long * pFlags, unsigned char * pBuffer, void * pObject)\
{\
return ObjectType ## _UserMarshal(pFlags, pBuffer, pObject);\
}\
static unsigned char * ObjectType ## _UserUnmarshal_XFG(unsigned long * pFlags, unsigned char * pBuffer, void * pObject)\
{\
return ObjectType ## _UserUnmarshal(pFlags, pBuffer, pObject);\
}\
static void ObjectType ## _UserFree_XFG(unsigned long * pFlags, void * pObject)\
{\
ObjectType ## _UserFree(pFlags, pObject);\
}
#define XFG_TRAMPOLINES64(ObjectType)\
static unsigned long ObjectType ## _UserSize64_XFG(unsigned long * pFlags, unsigned long Offset, void * pObject)\
{\
return  ObjectType ## _UserSize64(pFlags, Offset, pObject);\
}\
static unsigned char * ObjectType ## _UserMarshal64_XFG(unsigned long * pFlags, unsigned char * pBuffer, void * pObject)\
{\
return ObjectType ## _UserMarshal64(pFlags, pBuffer, pObject);\
}\
static unsigned char * ObjectType ## _UserUnmarshal64_XFG(unsigned long * pFlags, unsigned char * pBuffer, void * pObject)\
{\
return ObjectType ## _UserUnmarshal64(pFlags, pBuffer, pObject);\
}\
static void ObjectType ## _UserFree64_XFG(unsigned long * pFlags, void * pObject)\
{\
ObjectType ## _UserFree64(pFlags, pObject);\
}
#define XFG_BIND_TRAMPOLINES(HandleType, ObjectType)\
static void* ObjectType ## _bind_XFG(HandleType pObject)\
{\
return ObjectType ## _bind((ObjectType) pObject);\
}\
static void ObjectType ## _unbind_XFG(HandleType pObject, handle_t ServerHandle)\
{\
ObjectType ## _unbind((ObjectType) pObject, ServerHandle);\
}
#define XFG_TRAMPOLINE_FPTR(Function) Function ## _XFG
#else
#define XFG_TRAMPOLINES(ObjectType)
#define XFG_TRAMPOLINES64(ObjectType)
#define XFG_BIND_TRAMPOLINES(HandleType, ObjectType)
#define XFG_TRAMPOLINE_FPTR(Function) Function
#endif



extern const controller_MIDL_TYPE_FORMAT_STRING controller__MIDL_TypeFormatString;
extern const controller_MIDL_PROC_FORMAT_STRING controller__MIDL_ProcFormatString;
extern const controller_MIDL_EXPR_FORMAT_STRING controller__MIDL_ExprFormatString;

#define GENERIC_BINDING_TABLE_SIZE   0            


/* Standard interface: Controller, ver. 1.0,
   GUID={0xE4A0BCF4,0x7F16,0x4EB7,{0x8B,0x8B,0x4F,0x5B,0x31,0xD2,0x75,0xF6}} */

 extern const MIDL_STUBLESS_PROXY_INFO Controller_ProxyInfo;
handle_t hController;


static const RPC_CLIENT_INTERFACE Controller___RpcClientInterface =
    {
    sizeof(RPC_CLIENT_INTERFACE),
    {{0xE4A0BCF4,0x7F16,0x4EB7,{0x8B,0x8B,0x4F,0x5B,0x31,0xD2,0x75,0xF6}},{1,0}},
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    0,
    0,
    0,
    0,
    &Controller_ProxyInfo,
    0x02000000
    };
RPC_IF_HANDLE Controller_v1_0_c_ifspec = (RPC_IF_HANDLE)& Controller___RpcClientInterface;

extern const MIDL_STUB_DESC Controller_StubDesc;

static RPC_BINDING_HANDLE Controller__MIDL_AutoBindHandle;


boolean RpcControllerHealthCheck( 
    /* [in] */ handle_t pluginHandle,
    /* [in] */ int pluginID,
    /* [range][in] */ unsigned char *port)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall3(
                  ( PMIDL_STUBLESS_PROXY_INFO  )&Controller_ProxyInfo,
                  0,
                  0,
                  pluginHandle,
                  pluginID,
                  port);
    return ( boolean  )_RetVal.Simple;
    
}


#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const controller_MIDL_PROC_FORMAT_STRING controller__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure RpcControllerHealthCheck */

			0x0,		/* 0 */
			0x48,		/* Old Flags:  */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x0 ),	/* 0 */
/*  8 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 10 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 12 */	NdrFcShort( 0x0 ),	/* X64 Stack size/offset = 0 */
/* 14 */	NdrFcShort( 0x21 ),	/* 33 */
/* 16 */	NdrFcShort( 0x5 ),	/* 5 */
/* 18 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 20 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */
/* 26 */	NdrFcShort( 0x0 ),	/* 0 */
/* 28 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pluginID */

/* 30 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 32 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 34 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter port */

/* 36 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 38 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 40 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */

/* 42 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 44 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 46 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

			0x0
        }
    };

static const controller_MIDL_TYPE_FORMAT_STRING controller__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x0,	/* FC_RP */
/*  4 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6) */
/*  6 */	0xb7,		/* FC_RANGE */
			0x2,		/* 2 */
/*  8 */	NdrFcLong( 0x3 ),	/* 3 */
/* 12 */	NdrFcLong( 0x6 ),	/* 6 */

			0x0
        }
    };

static const unsigned short Controller_FormatStringOffsetTable[] =
    {
    0
    };



#endif /* defined(_M_AMD64)*/



/* this ALWAYS GENERATED file contains the RPC client stubs */


 /* File created by MIDL compiler version 8.01.0626 */
/* at Tue Jan 19 06:44:07 2038
 */
/* Compiler settings for controller.idl:
    Oicf, W3, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0626 
    protocol : all , ms_ext, app_config, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if defined(_M_AMD64)




#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif


#include "ndr64types.h"
#include "pshpack8.h"


typedef 
NDR64_FORMAT_CHAR
__midl_frag6_t;
extern const __midl_frag6_t __midl_frag6;

typedef 
struct _NDR64_RANGE_FORMAT
__midl_frag5_t;
extern const __midl_frag5_t __midl_frag5;

typedef 
struct _NDR64_POINTER_FORMAT
__midl_frag4_t;
extern const __midl_frag4_t __midl_frag4;

typedef 
NDR64_FORMAT_CHAR
__midl_frag3_t;
extern const __midl_frag3_t __midl_frag3;

typedef 
struct 
{
    struct _NDR64_PROC_FORMAT frag1;
    struct _NDR64_BIND_AND_NOTIFY_EXTENSION frag2;
    struct _NDR64_PARAM_FORMAT frag3;
    struct _NDR64_PARAM_FORMAT frag4;
    struct _NDR64_PARAM_FORMAT frag5;
}
__midl_frag2_t;
extern const __midl_frag2_t __midl_frag2;

typedef 
NDR64_FORMAT_UINT32
__midl_frag1_t;
extern const __midl_frag1_t __midl_frag1;

static const __midl_frag6_t __midl_frag6 =
0x2    /* FC64_INT8 */;

static const __midl_frag5_t __midl_frag5 =
{ 
/* char */
    0xa4,    /* FC64_RANGE */
    0x10,    /* FC64_CHAR */
    (NDR64_UINT16) 0 /* 0x0 */,
    (NDR64_INT64) 3 /* 0x3 */,
    (NDR64_INT64) 6 /* 0x6 */
};

static const __midl_frag4_t __midl_frag4 =
{ 
/* *char */
    0x20,    /* FC64_RP */
    (NDR64_UINT8) 0 /* 0x0 */,
    (NDR64_UINT16) 0 /* 0x0 */,
    &__midl_frag5
};

static const __midl_frag3_t __midl_frag3 =
0x5    /* FC64_INT32 */;

static const __midl_frag2_t __midl_frag2 =
{ 
/* RpcControllerHealthCheck */
    { 
    /* RpcControllerHealthCheck */      /* procedure RpcControllerHealthCheck */
        (NDR64_UINT32) 17301568 /* 0x1080040 */,    /* explicit handle */ /* IsIntrepreted, HasReturn, HasExtensions */
        (NDR64_UINT32) 32 /* 0x20 */ ,  /* Stack size */
        (NDR64_UINT32) 37 /* 0x25 */,
        (NDR64_UINT32) 5 /* 0x5 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 0 /* 0x0 */,
        (NDR64_UINT16) 3 /* 0x3 */,
        (NDR64_UINT16) 8 /* 0x8 */
    },
    { 
    /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
        { 
        /* struct _NDR64_BIND_AND_NOTIFY_EXTENSION */
            0x72,    /* FC64_BIND_PRIMITIVE */
            (NDR64_UINT8) 0 /* 0x0 */,
            0 /* 0x0 */,   /* Stack offset */
            (NDR64_UINT8) 0 /* 0x0 */,
            (NDR64_UINT8) 0 /* 0x0 */
        },
        (NDR64_UINT16) 0 /* 0x0 */      /* Notify index */
    },
    { 
    /* pluginID */      /* parameter pluginID */
        &__midl_frag3,
        { 
        /* pluginID */
            0,
            0,
            0,
            1,
            0,
            0,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [in], Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        8 /* 0x8 */,   /* Stack offset */
    },
    { 
    /* port */      /* parameter port */
        &__midl_frag5,
        { 
        /* port */
            0,
            1,
            0,
            1,
            0,
            0,
            0,
            0,
            1,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* MustFree, [in], SimpleRef */
        (NDR64_UINT16) 0 /* 0x0 */,
        16 /* 0x10 */,   /* Stack offset */
    },
    { 
    /* boolean */      /* parameter boolean */
        &__midl_frag6,
        { 
        /* boolean */
            0,
            0,
            0,
            0,
            1,
            1,
            1,
            1,
            0,
            0,
            0,
            0,
            0,
            (NDR64_UINT16) 0 /* 0x0 */,
            0
        },    /* [out], IsReturn, Basetype, ByValue */
        (NDR64_UINT16) 0 /* 0x0 */,
        24 /* 0x18 */,   /* Stack offset */
    }
};

static const __midl_frag1_t __midl_frag1 =
(NDR64_UINT32) 0 /* 0x0 */;


#include "poppack.h"


static const FormatInfoRef Controller_Ndr64ProcTable[] =
    {
    &__midl_frag2
    };


static const MIDL_STUB_DESC Controller_StubDesc = 
    {
    (void *)& Controller___RpcClientInterface,
    MIDL_user_allocate,
    MIDL_user_free,
    &hController,
    0,
    0,
    0,
    0,
    controller__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x60001, /* Ndr library version */
    0,
    0x8010272, /* MIDL Version 8.1.626 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x2000001, /* MIDL flag */
    0, /* cs routines */
    (void *)& Controller_ProxyInfo,   /* proxy/server info */
    0
    };

static const MIDL_SYNTAX_INFO Controller_SyntaxInfo [  2 ] = 
    {
    {
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    0,
    controller__MIDL_ProcFormatString.Format,
    Controller_FormatStringOffsetTable,
    controller__MIDL_TypeFormatString.Format,
    0,
    0,
    0
    }
    ,{
    {{0x71710533,0xbeba,0x4937,{0x83,0x19,0xb5,0xdb,0xef,0x9c,0xcc,0x36}},{1,0}},
    0,
    0 ,
    (unsigned short *) Controller_Ndr64ProcTable,
    0,
    0,
    0,
    0
    }
    };

static const MIDL_STUBLESS_PROXY_INFO Controller_ProxyInfo =
    {
    &Controller_StubDesc,
    controller__MIDL_ProcFormatString.Format,
    Controller_FormatStringOffsetTable,
    (RPC_SYNTAX_IDENTIFIER*)&_RpcTransferSyntax,
    2,
    (MIDL_SYNTAX_INFO*)Controller_SyntaxInfo
    
    };

#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* defined(_M_AMD64)*/

