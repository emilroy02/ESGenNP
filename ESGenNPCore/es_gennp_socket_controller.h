#ifndef ES_GENNP_SOCKET_CONTROLLER_H
#define ES_GENNP_SOCKET_CONTROLLER_H

#include "es_gennp_common.h"

class ESGenNPSocketController
{
public:
    virtual ~ESGenNPSocketController()=0;

    virtual bool Create(int32_t protocol)=0;
    virtual bool Connect(uint64_t ipAddress, uint16_t port)=0;
    virtual void Destroy()=0;
    virtual bool Bind(uint64_t ipAddress, uint16_t port)=0;
    virtual bool SetSocketOpt(int32_t level, int32_t optName, const char *optValue, int32_t optLen)=0;
    virtual bool GetSocketOpt(int32_t level, int32_t optName, const char *optValue, int32_t optLen)=0;

    virtual bool Send(uint8_t *pData, size_t dataSize)=0;
    virtual bool SendTo(uint8_t *pData, size_t dataSize, uint32_t ipAddress, uint16_t port)=0;
};

inline ESGenNPSocketController::~ESGenNPSocketController(){}
#endif // ES_GENNP_SOCKET_CONTROLLER_H
