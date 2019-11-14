#include "es_gennp_event_error.h"

ESGenNPEventError::ESGenNPEventError()
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
