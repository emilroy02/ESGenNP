#ifndef ES_GENNP_EVENT_ERROR_H
#define ES_GENNP_EVENT_ERROR_H

#include "es_gennp_common.h"
#include "es_gennp_event.h"

typedef struct ESErrorEventData_
{
    std::string errorMessage;
    ESErrorEventData_(const std::string &errorMessage):errorMessage(errorMessage){}
} ESErrorEventData;

class ESGenNPEventError:public ESGenNPEvent
{
public:
    ESGenNPEventError();
    virtual~ESGenNPEventError();

public:
    bool ErrorEventAdd (const std::string &msg);

protected:
    virtual ESGC_ERROR DoGetData(const ESErrorEventData &evt_data, void *buffer, size_t *psize);
};

#endif // ES_GENNP_EVENT_ERROR_H