#ifndef ES_GENNP_SERVICE_DIRECT_H
#define ES_GENNP_SERVICE_DIRECT_H

#include "es_gennp_service.h"

class ESGenNPServiceDirect: public ESGenNPService
{
public:
    ESGenNPServiceDirect();
    virtual ~ESGenNPServiceDirect();

    ESGC_ERROR ESGCInit();
    ESGC_ERROR ESGCClose();
};

#endif // ES_GENNP_SERVICE_DIRECT_H
