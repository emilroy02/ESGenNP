#include "es_gennp_common.h"

#define ESGC_EXPORTS
#include "es_gennp.h"

#include "es_gennp_core_init.h"
#include "es_gennp_config_init.h"
#include "es_gennp_service.h"
#include "es_gennp_branding_restos.h"

static ESGenNPService *pService = NULL;

static std::shared_ptr<ESGenNPBranding> CreateBrandingRestos()
{
    return std::make_shared<ESGenNPBrandingRestos>();
}

class ESGenNPCoreConfigurator
{
public:
    ESGenNPCoreConfigurator ()
    {
        ESCoreConfig cfg;
        cfg.pFNCreateBranding = CreateBrandingRestos;
        pService = ESGenNPCoreInit::ConfigureCore(cfg);
    }

    ~ESGenNPCoreConfigurator (){}
};

static ESGenNPCoreConfigurator configurator;

extern "C" {
namespace ESGenNP {

    #define COMMON_PRECONDITION if (!pService) { return ESGC_ERR_NOT_INITIALIZED;}

    ESGC_API ESGCInit( void )
    {
        COMMON_PRECONDITION
        return pService->ESGCInit();
    }

    ESGC_API ESGCClose( void )
    {
        COMMON_PRECONDITION
        return pService->ESGCClose();
    }
  }
}
