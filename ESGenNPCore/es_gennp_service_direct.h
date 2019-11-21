#ifndef ES_GENNP_SERVICE_DIRECT_H
#define ES_GENNP_SERVICE_DIRECT_H

#include "es_gennp_service.h"
#include "es_gennp_library.h"

#include <memory>

class ESGenNPServiceDirect: public ESGenNPService
{
public:
    ESGenNPServiceDirect(const std::shared_ptr<ESGenNPLibrary> &library);
    virtual ~ESGenNPServiceDirect();

    ESGC_ERROR ESGCInit();
    ESGC_ERROR ESGCClose();
    ESGC_ERROR ESGCClientCreate(ESGC_CLIENT_HANDLE *phClientOut);
    ESGC_ERROR ESGCClientConnect(ESGC_CLIENT_HANDLE hClient, const std::string &ipAddress, const uint16_t port);
    ESGC_ERROR ESGCServerCreate(ESGC_SERVER_HANDLE *phServerOut);
    ESGC_ERROR ESGCServerStart(ESGC_SERVER_HANDLE hServer);
    ESGC_ERROR ESGCServerStop(ESGC_SERVER_HANDLE hServer);


private:
    std::shared_ptr<ESGenNPLibrary> m_Library;
};

#endif // ES_GENNP_SERVICE_DIRECT_H
