#ifndef ES_GENNP_LIBRARY_H
#define ES_GENNP_LIBRARY_H

#include "es_gennp_common.h"
#include "es_gennp_handle.h"
#include "es_gennp_module_client.h"
#include "es_gennp_wrap.h"

#include <map>
#include <mutex>

class ESGenNPLibrary
{
public:
    ESGenNPLibrary();
    virtual ~ESGenNPLibrary();

public:
    ESGC_ERROR Initialize();
    ESGC_ERROR Uninitialize();
    bool IsInitialized();

    //ESGC_ERROR CreateClient(std::shared_ptr<ESGenNPModuleClient> &clientOut);

    ESGC_ERROR OpenHandle(const std::shared_ptr<ESGenNPHandle> &hInstance, ESGENNP_HANDLE *hPointerOut);
    template<typename T> ESGC_ERROR CloseHandle (ESGENNP_HANDLE hHandle);
    template<typename T> ESGC_ERROR GetHandle (ESGENNP_HANDLE hHandle, std::shared_ptr<T> &hInstanceOut);

private:
    bool m_bInitialized;
    mutable std::mutex m_Mutex;

    typedef std::map<ESGENNP_HANDLE, std::shared_ptr<ESGenNPHandle>> HandlePoolType;
    HandlePoolType m_HandleMap;

private:
    ESGenNPLibrary (const ESGenNPLibrary&);
    ESGenNPLibrary& operator=(const ESGenNPLibrary&);
};

#endif // ES_GENNP_LIBRARY_H
