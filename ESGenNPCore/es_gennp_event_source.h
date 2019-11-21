#ifndef ES_GENNP_EVENT_SOURCE_H
#define ES_GENNP_EVENT_SOURCE_H

#include "es_gennp_common.h"
#include "es_gennp_wrap.h"

#include "es_gennp_event.h"
//#include "es_gennp_event_error.h"

#include <map>
#include <memory>

class ESGenNPEventSource
{
public:
    ESGenNPEventSource();
    virtual ~ESGenNPEventSource() = 0;

    ESGC_ERROR RegisterEvent(ESGC_EVENT_TYPE type,std::shared_ptr<ESGenNPEvent> &eventOut);
    ESGC_ERROR UnregisterEvent(ESGC_EVENT_TYPE type,std::shared_ptr<ESGenNPEvent> &eventOut);

    void OnRegisterEventError(ESGC_EVENT_TYPE type);

protected:
    void AddSupportedEvent(const std::shared_ptr<ESGenNPEvent> &event);
    void AddErrorEvent(); //TBD only error event for now, add parameter later to support other shared events
    bool TriggerErrorEvent(const std::string &msg);

    virtual ESGC_ERROR DoRegisterEvent (ESGC_EVENT_TYPE type);
    virtual ESGC_ERROR DoUnregisterEvent (ESGC_EVENT_TYPE type);
    virtual std::recursive_mutex &GetLock()=0;

private:
    typedef std::map<ESGC_EVENT_TYPE, std::shared_ptr<ESGenNPEvent>>EventMapType;
    EventMapType m_EventMap;

    std::shared_ptr<ESGenNPEventError> m_EventError;
};


#endif // ES_GENNP_EVENT_SOURCE_H
