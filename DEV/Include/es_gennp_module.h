#ifndef ES_GENNP_MODULE_H
#define ES_GENNP_MODULE_H

#include "es_gennp_common.h"
#include "es_gennp_handle.h"
#include "es_gennp_event_source.h"

#include <memory>
#include <mutex>

class ESGenNPModule: public ESGenNPHandle, public ESGenNPEventSource
{
public:
    ESGenNPModule();
    virtual ~ESGenNPModule() = 0;

protected:
    virtual std::recursive_mutex &GetLock();
};

#endif // ES_GENNP_MODULE_H
