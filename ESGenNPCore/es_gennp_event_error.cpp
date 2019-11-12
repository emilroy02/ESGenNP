#include "es_gennp_event_error.h"

ESGenNPEventError::ESGenNPEventError()
{

}

ESGenNPEventError::~ESGenNPEventError()
{
}

bool ESGenNPEventError::ErrorEventAdd(const std::string &msg)
{
    ESErrorEventData eventData(msg);
    return EventDataAdd(eventData);
}

ESGC_ERROR ESGenNPEventError::DoGetData(const ESErrorEventData &evt_data, void *buffer, size_t *psize)
{

}
