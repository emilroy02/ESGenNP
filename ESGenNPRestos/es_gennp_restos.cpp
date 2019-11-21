#include "es_gennp_common.h"

#define ESGC_EXPORTS
#include "es_gennp.h"

#include "es_gennp_core_init.h"
#include "es_gennp_config_init.h"
#include "es_gennp_service.h"
#include "es_gennp_branding_restos.h"
#include "es_gennp_library_restos.h"

static ESGenNPService *pService = NULL;

static std::shared_ptr<ESGenNPBranding> CreateBrandingRestos()
{
    return std::make_shared<ESGenNPBrandingRestos>();
}

static std::shared_ptr<ESGenNPLibrary> CreateLibraryRestos()
{
    return std::make_shared<ESGenNPLibraryRestos>();
}

class ESGenNPCoreConfigurator
{
public:
    ESGenNPCoreConfigurator ()
    {
        ESCoreConfig cfg;
        cfg.pFNCreateBranding = CreateBrandingRestos;
        cfg.pFNCreateLibrary = CreateLibraryRestos;
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

    ESGC_API ESGCClientCreate( ESGC_CLIENT_HANDLE *phClientOut)
    {
        COMMON_PRECONDITION
        return pService->ESGCClientCreate(phClientOut);
    }

    ESGC_API ESGCClientConnect(ESGC_CLIENT_HANDLE hClient, const std::string &ipAddress, const uint16_t port)
    {
        COMMON_PRECONDITION
        return pService->ESGCClientConnect(hClient, ipAddress, port);
    }

    ESGC_API ESGCServerCreate( ESGC_SERVER_HANDLE *phServerOut)
    {
        COMMON_PRECONDITION
        return pService->ESGCServerCreate(phServerOut);
    }

    ESGC_API ESGCServerStart(ESGC_SERVER_HANDLE hServer)
    {
        COMMON_PRECONDITION
        return pService->ESGCServerStart(hServer);
    }

    ESGC_API ESGCServerStop(ESGC_SERVER_HANDLE hServer)
    {
        COMMON_PRECONDITION
        return pService->ESGCServerStop(hServer);
    }
  }
}
