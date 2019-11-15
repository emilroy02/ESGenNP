#include "es_gennp_core_init.h"
#include "es_gennp_config_init_branding.h"
#include "es_gennp_service.h"
#include "es_gennp_service_direct.h"
#include "es_gennp_util_os.h"

static ESAtomicLong nifty_counter = 0;
static ESGenNPConfigInitBranding *branding_config_init = NULL;
static ESGenNPServiceDirect *direct_service = NULL;

ESGenNPCoreInit::ESGenNPCoreInit ()
{
    if (1 == ESGenNPUtilOS::AtomicIncrement(&nifty_counter))
    {
        branding_config_init = ESGenNPConfigInitBranding::GetInstance();
    }
}

ESGenNPCoreInit::~ESGenNPCoreInit ()
{
    if (0 == ESGenNPUtilOS::AtomicDecrement(&nifty_counter))
    {
        if (branding_config_init)
        {
            branding_config_init->PrepareForShutdown();
            delete branding_config_init;
        }

        if(direct_service)
            delete direct_service;
    }
}

bool ESGenNPCoreInit::ValidateCoreConfig(const ESCoreConfig &config)
{
    if (!config.pFNCreateBranding)
        return false;

    return true;
}

ESGenNPService *ESGenNPCoreInit::ConfigureCore(const ESCoreConfig &config)
{
    static ESGenNPService *pService = NULL;
    static ESAtomicLong counter = 0;

    if(ESGenNPUtilOS::AtomicIncrement(&counter) != 1) //return same instance on multiple configure
        return pService;

    if(NULL == branding_config_init)
        return NULL;

    if(false == ESGenNPCoreInit::ValidateCoreConfig(config))
        return NULL;

    std::shared_ptr<ESGenNPBranding> brand = config.pFNCreateBranding();
    std::shared_ptr<ESGenNPLibrary> library = config.pFNCreateLibrary();

    direct_service = new ESGenNPServiceDirect(library);
    pService = dynamic_cast<ESGenNPService*> (direct_service);


    branding_config_init->StartupConfig(brand);


    return pService;
}

