#ifndef ES_GENNP_EVENT_SOURCE_H
#define ES_GENNP_EVENT_SOURCE_H

#include "es_gennp_common.h"
#include "es_gennp_wrap.h"

#include "es_gennp_event.h"
#include "es_gennp_event_error.h"

#include <map>
#include <memory>

class ESGenNPEventSource
{
public:
    ESGenNPEventSource();
    virtual ~ESGenNPEventSource() = 0; //only for polymorphic access

    ESGC_ERROR RegisterEvent(ESGC_EVENT_TYPE type,std::shared_ptr<ESGenNPEvent> &event);
    ESGC_ERROR UnregisterEvent(ESGC_EVENT_TYPE type,std::shared_ptr<ESGenNPEvent> &event);

    void OnEventRegisterError(ESGC_EVENT_TYPE type);

protected:
    void AddSupportedEvent(const std::shared_ptr<ESGenNPEvent> &event);
    void AddSharedEvent(); //TBD only error event for now, add parameter later to support other shared events
    bool TriggerErrorEvent(const std::string &msg);

private:
    typedef std::map<ESGC_EVENT_TYPE, std::shared_ptr<ESGenNPEvent>>EventMapType;
    EventMapType m_EventMap;

    std::shared_ptr<ESGenNPEventError> m_EventError;
};


#endif // ES_GENNP_EVENT_SOURCE_H
