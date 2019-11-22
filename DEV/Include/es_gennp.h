#ifndef ES_GENNP_H
#define ES_GENNP_H

#if defined _WIN32

#if defined(_MSC_VER) && _MSC_VER >= 1600
  #include <stdint.h>
#else
  /* stdint.h not available, define the needed types */
  typedef char int8_t;
  typedef unsigned char uint8_t;
  typedef short int16_t;
  typedef unsigned short uint16_t;
  typedef __int32 int32_t;
  typedef unsigned __int32 uint32_t;
  typedef __int64 int64_t;
  typedef unsigned __int64 uint64_t;

  #define INT32_MAX  _I32_MAX
  #define INT64_MAX  _I64_MAX
  #define UINT32_MAX _UI32_MAX
  #define UINT64_MAX _UI64_MAX
#endif /* _MSC_VER >= 1600 */
#else

#define __STDC_LIMIT_MACROS
#include <stdint.h>

/* includes e.g. NULL */
#include <stddef.h>

#endif

typedef float             float32_t;
typedef double            float64_t;

#include <stddef.h>
#include <string>

/* Function declaration modifiers */
#if defined (_MSC_VER)
#   ifdef ESGC_EXPORTS
#       define ESGC_IMPORT_EXPORT __declspec(dllexport)
#   elif ESGC_DYNAMIC_LOAD
#       define ESGC_IMPORT_EXPORT
#   else
#       define ESGC_IMPORT_EXPORT
#   endif
#   if defined (_M_IX86) || defined (__i386__)
#       define ESGC_CALLTYPE __stdcall
#   else
#       define ESGC_CALLTYPE /* default */
#   endif
#elif defined (__GNUC__) && (__GNUC__ >= 4) && (defined (__linux__) || defined (__APPLE__))
#  define ESGC_EXPORTS __attribute__((visibility("default")))
#  if defined (__i386__)
#    define ESGC_CALLTYPE __attribute__((stdcall))
#  else
#    define ESGC_CALLTYPE /* default */
#  endif
#else
#  error Unknown platform, file needs adaption
#endif

#ifdef __cplusplus
#   ifndef EXTERN_C
#   define EXTERN_C extern "C"
#   endif
#else
#   define EXTERN_C
#endif

#ifdef __cplusplus
extern "C" {
  namespace ESGenNP {
#endif

    /* Errors */
    enum ESGC_ERROR_LIST
    {
        ESGC_ERR_SUCCESS             = 0,
        ESGC_ERR_ERROR               = -1001,
        ESGC_ERR_NOT_INITIALIZED     = -1002,
        ESGC_ERR_NOT_IMPLEMENTED     = -1003,
        ESGC_ERR_RESOURCE_IN_USE     = -1004,
        ESGC_ERR_ACCESS_DENIED       = -1005,
        ESGC_ERR_INVALID_HANDLE      = -1006,
        ESGC_ERR_INVALID_PARAMETER   = -1007,
        ESGC_ERR_ABORT               = -1008,
        ESGC_ERR_TIMEOUT             = -1009,
        ESGC_ERR_BUFFER_TOO_SMALL    = -1010,
        ESGC_ERR_TBD                 = -2000
    };
    typedef int32_t ESGC_ERROR;

    enum ESGC_EVENT_TYPE_LIST
    {
        ESGC_EVENT_ERROR                      = 0,     /* Notification on module errors. */
        ESGC_EVENT_CLIENT_SERVER_DISCOVERED   = 1,     /* Notification on client module when server is discovered. */
        ESGC_EVENT_SERVER_CLIENT_CONNECTED    = 2,     /* Notification on server module when client is connected. */
        ESGC_EVENT_PACKET_RECEIVED            = 3,     /* Notification on client/server module when packet is received*/
        ESGC_EVENT_CUSTOM_ID                  = 10000
    };
    typedef int32_t ESGC_EVENT_TYPE;

    typedef void* ESGC_CLIENT_HANDLE;
    typedef void* ESGC_SERVER_HANDLE;

    typedef void* ESGC_EVENTSRC_HANDLE;    /* a EVENTSRC_HANDLE can be one of the following*/
                                            /* ESGC_CLIENT_HANDLE, ESGC_CLIENT_HANDLE*/
    typedef void* ESGC_EVENT_HANDLE;

#   define ESGC_API ESGC_IMPORT_EXPORT ESGC_ERROR ESGC_CALLTYPE

    ESGC_API ESGCInit              ( void );
    ESGC_API ESGCClose             ( void );

    ESGC_API ESGCClientCreate      (ESGC_CLIENT_HANDLE *phClientOut);//TBD might need to pass some uid/info like port, etc
    ESGC_API ESGCClientConnect     (ESGC_CLIENT_HANDLE hClient, const std::string &ipAddress, const uint16_t port);

    ESGC_API ESGCServerCreate      (ESGC_SERVER_HANDLE *phServerOut);
//    ESGC_API ESGCServerGetInfo     (ESGC_SERVER_HANDLE hServer);
    ESGC_API ESGCServerStart       (ESGC_SERVER_HANDLE hServer); //TBD might need to pass some uid/info like port, etc
    ESGC_API ESGCServerStop        (ESGC_SERVER_HANDLE hServer);

    ESGC_API ESGCRegisterEvent     (ESGC_EVENTSRC_HANDLE hEventSrc, ESGC_EVENT_TYPE type, ESGC_EVENT_HANDLE *phEventOut);
    ESGC_API ESGCEventGetData      (ESGC_EVENT_HANDLE hEvent, void *pBuffer, size_t *piSize, uint64_t iTimeout);
//    ESGC_API ESGCUnregisterEvent   ( void );

//    ESGC_API ESGCEventGetData      ( void );
//    ESGC_API ESGCEventFlush        ( void );
//    ESGC_API ESGCEventKill         ( void );

////#define ES_CLIENT 1
//#ifdef ES_CLIENT
//    ESGC_API ESClientGetInfo            ( void );
//    ESGC_API ESClientGetNumServers      ( void );
//    ESGC_API ESClientUpdateServerList   ( void ); //Blocking for now
//    ESGC_API ESClientGetServerInfo      ( void );
//    ESGC_API ESClientConnectToServer    ( void );
//#else
//    ESGC_API ESServerGetInfo            ( void );
//    ESGC_API ESServerStart              ( void );
//    ESGC_API ESServerAcceptClient       ( void );
//    ESGC_API ESServerStop               ( void );
//#endif

//Commented for now
///* typedefs for dynamic loading */
//#   define ESGC_API_P(function) typedef ESGC_ERROR( ESGC_CALLTYPE *function )
//    ESGC_API_P(PESGCInit               )( void );
//    ESGC_API_P(PESGCClose              )( void );
//    ESGC_API_P(PESGCCreateClient       )( ESGC_CLIENT_HANDLE* );

#ifdef __cplusplus
  } /* end of namespace ESGenNP */
} /* end of extern "C" */
#endif

#endif // ES_GENNP_H
