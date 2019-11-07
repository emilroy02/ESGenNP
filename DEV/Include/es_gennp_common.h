#ifndef ES_GENNP_COMMON_H
#define ES_GENNP_COMMON_H

#if defined _WIN32

/* Get rid of the "security" warnings for the standard C++ library functions */
#ifndef _CRT_SECURE_NO_WARNINGS
  #define _CRT_SECURE_NO_WARNINGS
#endif
#ifndef _SCL_SECURE_NO_WARNINGS
  #define _SCL_SECURE_NO_WARNINGS
#endif

#define WIN32_LEAN_AND_MEAN

#ifndef _WIN32_WINNT
  #define _WIN32_WINNT 0x0501
#endif
#include <windows.h>

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
#ifdef __cplusplus
template<class T> void ES_UNUSED (const T&) { }
#else
#define ES_UNUSED(x) (void)(x)
#endif

//#include <mutex>
//#include <thread>
//#include <memory>
//#include <string>

//#include "es_gennp_util_os.h"

#endif // ES_GENNP_COMMON_H
