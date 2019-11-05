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
        ESGC_ERR_TIMEOUT             = -1008
    };
    typedef int32_t ESGC_ERROR;

#   define ESGC_API ESGC_IMPORT_EXPORT ESGC_ERROR ESGC_CALLTYPE

    ESGC_API ESGCInit              ( void );
    ESGC_API ESGCClose             ( void );

/* typedefs for dynamic loading */
#   define ESGC_API_P(function) typedef ESGC_ERROR( ESGC_CALLTYPE *function )
    ESGC_API_P(PESGCInit               )( void );
    ESGC_API_P(PESGCClose              )( void );

#ifdef __cplusplus
  } /* end of namespace ESGenNP */
} /* end of extern "C" */
#endif

#endif // ES_GENNP_H
