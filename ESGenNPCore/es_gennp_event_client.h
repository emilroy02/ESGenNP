#ifndef ES_GENNP_EVENT_CLIENT_H
#define ES_GENNP_EVENT_CLIENT_H

#include "es_gennp_common.h"
#include "es_gennp_event.h"

#include <vector>

typedef std::vector<uint8_t> ESClientEventData;
class ESGenNPEventClient:public ESGenNPEvent<ESClientEventData>
{
public:
    ESGenNPEventClient();
    virtual~ESGenNPEventClient();

public:
    bool AddClientEvent(const uint8_t *pEventPacket, size_t eventPacketSize);

protected:
    virtual bool ValidateEventPacket(const uint8_t *pEventPacket, size_t eventPacketSize) const = 0;

private:
    virtual ESGC_ERROR DoGetData(const ESClientEventData &eventData, void *pBuffer, size_t *pSize);
};
#endif // ES_GENNP_EVENT_CLIENT_H
