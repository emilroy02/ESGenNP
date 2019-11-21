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

    virtual ESGC_ERROR ESGCRegisterEvent(ESGC_EVENTSRC_HANDLE hEventSrc, ESGC_EVENT_TYPE type, ESGC_EVENT_HANDLE *phEventOut)=0;
    virtual ESGC_ERROR ESGCEventGetData(ESGC_EVENT_HANDLE hEvent, void *pBuffer, size_t *piSize, uint64_t iTimeout)=0;

    virtual ESGC_ERROR ESGCClientCreate(ESGC_CLIENT_HANDLE *phClientOut) = 0;
    virtual ESGC_ERROR ESGCClientConnect(ESGC_CLIENT_HANDLE hClient, const std::string &ipAddress, const uint16_t port)=0;
    virtual ESGC_ERROR ESGCServerCreate(ESGC_SERVER_HANDLE *phServerOut) = 0;
    virtual ESGC_ERROR ESGCServerStart(ESGC_SERVER_HANDLE hServer)=0;
    virtual ESGC_ERROR ESGCServerStop(ESGC_SERVER_HANDLE hServer)=0;
};

#endif // ES_GENNP_SERVICE_H
