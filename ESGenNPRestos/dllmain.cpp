#include "es_gennp_common.h"

#if defined(_WIN32)
BOOL APIENTRY DllMain( HMODULE /*hModule*/,
                       DWORD  reason,
                       LPVOID /*lpReserved*/ )
{
  switch (reason)
  {
      case DLL_PROCESS_DETACH:
        break;
      case DLL_THREAD_DETACH:
        break;
  }
  return TRUE;
}
#endif /* defined (_WIN32) */
