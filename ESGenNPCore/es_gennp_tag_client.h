#ifndef ES_GENNP_TAG_CLIENT_H
#define ES_GENNP_TAG_CLIENT_H

#include "es_gennp_common.h"
#include <string>

class ESGenNPTagClient
{
public:
    virtual ~ESGenNPTagClient() = 0;

public:
    virtual std::string GetGUID() const = 0;
    virtual std::string GetName() const = 0;
    virtual std::string GetDisplayName() const = 0;
    virtual std::string GetIpAddress() const = 0;
    virtual uint16_t GetPort() const =0;
};

inline ESGenNPTagClient::~ESGenNPTagClient(){}
#endif // ES_GENNP_TAG_CLIENT_H
