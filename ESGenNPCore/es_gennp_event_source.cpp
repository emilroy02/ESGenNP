#include "es_gennp_event_source.h"

ESGenNPEventSource::ESGenNPEventSource():
    m_EventError(NULL)
{
}

ESGenNPEventSource::~ESGenNPEventSource()
{
}

ESGC_ERROR ESGenNPEventSource::RegisterEvent(ESGC_EVENT_TYPE type,std::shared_ptr<ESGenNPEvent> &eventOut)
{
    std::lock_guard<std::recursive_mutex> lock(GetLock());

    const EventMapType::iterator it_event = m_EventMap.find (type);
    if(it_event == m_EventMap.end())
        return ESGC_ERR_NOT_IMPLEMENTED;

    ESGC_ERROR ret = DoRegisterEvent(type);
    if(ESGC_ERR_SUCCESS != ret)
        return ret;

    eventOut = it_event->second;
    return ESGC_ERR_SUCCESS;
}

ESGC_ERROR ESGenNPEventSource::UnregisterEvent(ESGC_EVENT_TYPE type,std::shared_ptr<ESGenNPEvent> &eventOut)
{
    std::lock_guard<std::recursive_mutex> lock(GetLock());

    const EventMapType::iterator it_event = m_EventMap.find (type);
    if(it_event == m_EventMap.end())
        return ESGC_ERR_NOT_IMPLEMENTED;

    eventOut = it_event->second;

    ESGC_ERROR ret = DoUnregisterEvent(type);
    if(ESGC_ERR_SUCCESS != ret)
        return ret;

    return ESGC_ERR_SUCCESS;
}

void ESGenNPEventSource::OnRegisterEventError(ESGC_EVENT_TYPE type)
{
}

ESGC_ERROR ESGenNPEventSource::DoRegisterEvent (ESGC_EVENT_TYPE type)
{
    return ESGC_ERR_SUCCESS;
}

ESGC_ERROR ESGenNPEventSource::DoUnregisterEvent (ESGC_EVENT_TYPE type)
{
    return ESGC_ERR_SUCCESS;
}

void ESGenNPEventSource::AddSupportedEvent(const std::shared_ptr<ESGenNPEvent> &event)
{
    ESGC_EVENT_TYPE type = event->GetEventType();
    m_EventMap.insert(std::pair<ESGC_EVENT_TYPE, std::shared_ptr<ESGenNPEvent>>(type, event));
}

void ESGenNPEventSource::AddErrorEvent()
{
    if(NULL == m_EventError)
        return;

    m_EventError = std::make_shared<ESGenNPEventError>();
    m_EventError->Init();
    AddSupportedEvent(m_EventError);
}
