#include "es_gennp_event_client.h"

ESGenNPEventClient::ESGenNPEventClient()
{
}

ESGenNPEventClient::~ESGenNPEventClient()
{
}

bool ESGenNPEventClient::AddClientEvent(const uint8_t *pEventPacket, size_t eventPacketSize)
{
    return false;
}

ESGC_ERROR ESGenNPEventClient::DoGetData(const ESClientEventData &eventData, void *pBuffer, size_t *pSize)
{
    return ESGC_ERR_NOT_IMPLEMENTED;
}
