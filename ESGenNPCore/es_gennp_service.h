#ifndef ES_GENNP_SERVICE_H
#define ES_GENNP_SERVICE_H

#include "es_gennp_common.h"
#include "es_gennp_wrap.h"

class ESGenNPService
{
public:
    virtual ~ESGenNPService(){}

    virtual ESGC_ERROR ESGCInit() = 0;
    virtual ESGC_ERROR ESGCClose() = 0;
};

#endif // ES_GENNP_SERVICE_H
