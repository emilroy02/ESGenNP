#include "es_gennp_event.h"

ESGenNPEvent::ESGenNPEvent():
    ESGenNPHandle()
{
}

ESGenNPEvent::~ESGenNPEvent()
{
}

template<typename T>ESGenNPEventImpl<T>::ESGenNPEventImpl():
    ESGenNPEvent(),
    m_bAborted(false)
{
}

template<typename T> ESGenNPEventImpl<T>::~ESGenNPEventImpl()
{
}

template<typename T>ESGC_ERROR ESGenNPEventImpl<T>::GetData(void *pBuffer, size_t *pSize, uint64_t timeout)
{
    std::unique_lock<std::mutex> lock(m_Mutex);

    bool bRet = m_bAborted;
    if(true == bRet)
        return ESGC_ERR_ABORT;

    if(m_QueueNotEmpty.wait_for(lock, std::chrono::milliseconds(timeout)) == std::cv_status::timeout) //TBD do different on infinite timeout
        return ESGC_ERR_TIMEOUT;

    const T &eventData = m_EventDataQueue.front();
    if(pBuffer != NULL)
    {
        ESGC_ERROR ret = DoGetData(eventData, pBuffer, pSize);
        if (ESGC_ERR_SUCCESS != ret)
            return ret;
    }

    m_EventDataQueue.pop_front();
    return ESGC_ERR_SUCCESS;
}

template<typename T>ESGC_ERROR ESGenNPEventImpl<T>::Kill()
{
    std::lock_guard<std::mutex> lock(m_Mutex);
    m_bAborted = true;
    return ESGC_ERR_SUCCESS;
}

template<typename T> std::string ESGenNPEventImpl<T>::GetID () const
{
    return "TEMP_EVENT_ID";
}

template<typename T>bool ESGenNPEventImpl<T>::AddEventData(const T &eventData)
{
    //TBD check first if event is opened/registered???
    std::lock_guard<std::mutex> lock(m_Mutex);
    m_EventDataQueue.push_back(eventData);
    m_QueueNotEmpty.notify_all();
    return true;
}

ESGenNPEventError::ESGenNPEventError():
    ESGenNPEventImpl<ESErrorEventData>()
{
}

ESGenNPEventError::~ESGenNPEventError()
{
}

bool ESGenNPEventError::AddErrorEvent(const std::string &msg)
{
    ESErrorEventData eventData(msg);
    return AddEventData(eventData);
}

ESGC_ERROR ESGenNPEventError::DoGetData(const ESErrorEventData &evt_data, void *buffer, size_t *psize)
{
    return ESGC_ERR_NOT_IMPLEMENTED;
}

template class ESGenNPEventImpl<ESErrorEventData>;



