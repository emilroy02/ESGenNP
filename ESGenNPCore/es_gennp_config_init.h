#ifndef ES_GENNP_CONFIG_H
#define ES_GENNP_CONFIG_H

#include "es_gennp_common.h"
#include "es_gennp_branding.h"

#include <memory>

struct ESCoreConfig
{
    std::shared_ptr<ESGenNPBranding> (*pFNCreateBranding) ();
};

class ESGenNPConfigInit
{
public:
    ESGenNPConfigInit (){}
    virtual ~ESGenNPConfigInit() = 0;

    virtual void StartupConfig(const std::shared_ptr<ESGenNPBranding> &brand)
    {
        /* No-op by default */
    }

    virtual void PrepareForShutdown ()
    {
        /* No-op by default */
    }
};

inline ESGenNPConfigInit::~ESGenNPConfigInit () {}

#endif // ES_GENNP_CONFIG_H
