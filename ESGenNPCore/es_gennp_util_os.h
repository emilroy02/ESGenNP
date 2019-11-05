#ifndef ES_GENNP_UTIL_OS_H
#define ES_GENNP_UTIL_OS_H

#include "es_gennp_common.h"

#if defined(_WIN32)
  /* Windows interlocked functions expect volatile, 32-bit aligned variable. */
  typedef __declspec(align(4)) volatile long ESAtomicLong;
#else
  typedef long ESAtomicLong;
#endif

class ESGenNPUtilOS
{
public:
    inline static uint64_t QueryCounterMS(){
        #ifdef _MSC_VER
          static LARGE_INTEGER frequency;
          if (frequency.QuadPart == 0)
            ::QueryPerformanceFrequency(&frequency);

          LARGE_INTEGER now;
          ::QueryPerformanceCounter(&now);
          return (uint64_t)((now.QuadPart) * 1000LL / frequency.QuadPart);
        #else
          struct timespec now;
          clock_gettime(CLOCK_MONOTONIC, &now);
          return now.tv_sec + now.tv_nsec / 1000000.0;
        #endif
    }

    inline static long AtomicIncrement(ESAtomicLong *pValue) {
        #if defined(WIN32)
            return _InterlockedIncrement(pValue);
        #else
            return __sync_add_and_fetch(&value, 1);
        #endif
    }

    inline static long AtomicDecrement(ESAtomicLong *pValue) {
        #if defined(WIN32)
            return _InterlockedDecrement(pValue);
        #else
            return __sync_sub_and_fetch(&value, 1);
        #endif
    }
};

#endif // ES_GENNP_UTIL_OS_H
