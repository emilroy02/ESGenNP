#ifndef ES_GENNP_MODULE_SERVER_H
#define ES_GENNP_MODULE_SERVER_H

#include "es_gennp_common.h"
#include "es_gennp_module.h"

class ESGenNPModuleServer: public ESGenNPModule
{
public:
    ESGenNPModuleServer();
    virtual ~ESGenNPModuleServer();

public:
    virtual std::string GetID () const;

};

#endif // ES_GENNP_MODULE_SERVER_H
