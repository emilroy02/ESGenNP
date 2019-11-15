#include "es_gennp_library.h"

ESGenNPLibrary::ESGenNPLibrary():
    m_bInitialized(false)
{
}

ESGenNPLibrary::~ESGenNPLibrary()
{
}

ESGC_ERROR ESGenNPLibrary::Initialize()
{
    std::lock_guard<std::mutex> lock(m_Mutex);

    //TBD get branding test period there
    //TBD add user specific initialization

    if(true == m_bInitialized)
        return ESGC_ERR_RESOURCE_IN_USE;

    m_HandleMap.clear();
    m_bInitialized = true;
    return ESGC_ERR_NOT_IMPLEMENTED;
}

ESGC_ERROR ESGenNPLibrary::Uninitialize()
{
    std::lock_guard<std::mutex> lock(m_Mutex);

    if(false == m_bInitialized)
        return ESGC_ERR_NOT_INITIALIZED;

    m_bInitialized = false;
    return ESGC_ERR_NOT_IMPLEMENTED;
}

bool ESGenNPLibrary::IsInitialized()
{
    std::lock_guard<std::mutex> lock(m_Mutex);
    return m_bInitialized;
}

//ESGC_ERROR ESGenNPLibrary::CreateClient(std::shared_ptr<ESGenNPModuleClient> &clientOut)
//{
//    std::lock_guard<std::mutex> lock(m_Mutex);
//    if(false == m_bInitialized)
//        return ESGC_ERR_NOT_INITIALIZED;

//    //no validation for now
//    clientOut = std::make_shared<ESGenNPModuleClient>();
//    return OpenHandle(clientOut, )
//}

ESGC_ERROR ESGenNPLibrary::OpenHandle(const std::shared_ptr<ESGenNPHandle> &hInstance, ESGENNP_HANDLE *hPointerOut)
{
    std::lock_guard<std::mutex> lock(m_Mutex);
    if(false == m_bInitialized)
        return ESGC_ERR_NOT_INITIALIZED;

    if(NULL == hPointerOut)
        return ESGC_ERR_INVALID_PARAMETER;

    ESGENNP_HANDLE hHandle = PointerToHandle(hInstance);
    if(m_HandleMap.find (hHandle) != m_HandleMap.end ())
        return ESGC_ERR_RESOURCE_IN_USE;

    ESGC_ERROR retError = hInstance->Open();
    if (ESGC_ERR_SUCCESS != retError)
        return retError;

    m_HandleMap[hHandle] = hInstance;
    *hPointerOut = hHandle;

    return ESGC_ERR_SUCCESS;
}

template<typename T> ESGC_ERROR ESGenNPLibrary::CloseHandle(ESGENNP_HANDLE hHandle)
{
    std::lock_guard<std::mutex> lock(m_Mutex);

    if(false == m_bInitialized)
        return ESGC_ERR_NOT_INITIALIZED;

    HandlePoolType::iterator itHandle = m_HandleMap.find(hHandle);
    if(itHandle == m_HandleMap.end())
        return ESGC_ERR_INVALID_HANDLE;

    if(NULL == dynamic_cast<T>(itHandle->second.ptr))
        return ESGC_ERR_INVALID_HANDLE;

    //TBD remove all children recursively

    itHandle->second.ptr->Close();
    m_HandleMap.erase(itHandle);

    return ESGC_ERR_SUCCESS;
}

template<typename T> ESGC_ERROR ESGenNPLibrary::GetHandle (ESGENNP_HANDLE hHandle, std::shared_ptr<T> &hInstanceOut)
{
    std::lock_guard<std::mutex> lock(m_Mutex);

    if(false == m_bInitialized)
        return ESGC_ERR_NOT_INITIALIZED;

    HandlePoolType::iterator itHandle = m_HandleMap.find(hHandle);
    if(itHandle == m_HandleMap.end())
        return ESGC_ERR_INVALID_HANDLE;

    hInstanceOut = dynamic_cast<T>(itHandle->second.ptr);
    return ESGC_ERR_SUCCESS;
}
