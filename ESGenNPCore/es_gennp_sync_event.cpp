#include "es_gennp_sync_event.h"
#include "es_gennp_runnable_socket.h"

template<typename T>ESGenNPSyncEvent<T>::ESGenNPSyncEvent()
{
    m_EventSetFuture = m_EventSetPromise.get_future();
    m_EventCompletedFuture = m_EventCompletedPromise.get_future();
}

template<typename T> ESGenNPSyncEvent<T>::~ESGenNPSyncEvent()
{
}

template<typename T> void ESGenNPSyncEvent<T>::SetValue(T& value)
{
    m_EventSetPromise.set_value(value);
}

template<typename T> void ESGenNPSyncEvent<T>::SetCompleted(const bool value)
{
    m_EventCompletedPromise.set_value(value);
}

template<typename T> bool ESGenNPSyncEvent<T>::WaitForEventSetCompleted()
{
    bool bRet = false;
    m_EventCompletedFuture.wait();
    bRet = m_EventCompletedFuture.get();
    m_EventSetPromise = std::promise<T>();
    m_EventSetFuture = m_EventSetPromise.get_future();
    m_EventCompletedPromise = std::promise<bool>();
    m_EventCompletedFuture = m_EventCompletedPromise.get_future();
    return bRet;
}

template<typename T> bool ESGenNPSyncEvent<T>::WaitForEventSet(T &value, uint64_t timeOut)
{
    std::future_status status = m_EventSetFuture.wait_for(std::chrono::milliseconds(timeOut));
    if(status == std::future_status::ready)
    {
        value = m_EventSetFuture.get();
        return true;
    }

    return false;
}

template class ESGenNPSyncEvent<ESSocketCreateParam>;
template class ESGenNPSyncEvent<ESSocketConnectBindParam>;

