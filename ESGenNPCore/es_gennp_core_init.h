#ifndef ES_GENNP_CORE_INIT_H
#define ES_GENNP_CORE_INIT_H

#include "es_gennp_common.h"
#include "es_gennp_config_init.h"

class ESGenNPService;

class ESGenNPCoreInit
{
public:
    ESGenNPCoreInit ();
    ~ESGenNPCoreInit ();

    static bool ValidateCoreConfig(const ESCoreConfig &config);
    static ESGenNPService *ConfigureCore(const ESCoreConfig &config);
};

static ESGenNPCoreInit core_init;



#endif // ES_GENNP_CORE_INIT_H
