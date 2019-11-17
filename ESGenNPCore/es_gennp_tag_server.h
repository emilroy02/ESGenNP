#ifndef ES_GENNP_TAG_SERVER_H
#define ES_GENNP_TAG_SERVER_H

#include "es_gennp_common.h"
#include <string>

class ESGenNPTagServer
{
public:
    virtual ~ESGenNPTagServer() = 0;

public:
    virtual std::string GetGUID() const = 0;
    virtual std::string GetName() const = 0;
    virtual std::string GetDisplayName() const = 0;
    virtual std::string GetIpAddress() const = 0;
    virtual uint16_t GetPort() const =0;

    virtual bool IsTCP() const =0;
};

inline ESGenNPTagServer::~ESGenNPTagServer(){}

#endif // ESGENNPTAGSERVER_H
