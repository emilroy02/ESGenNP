#ifndef ES_GENNP_CLIENT_H
#define ES_GENNP_CLIENT_H

#include "es_gennp_common.h"

class ESGenNPClient
{
public:
    ESGenNPClient();

    bool ServerDiscoveryStart();
    void ServerDiscoveryStop();

    bool ServerConnect(int serverID);
    void ServerDisconnect();

    void ServerSend(int data);

protected:
    virtual void OnServerDiscovered(int serverID);
    virtual void OnServerDisconnected();
    virtual void OnDataReceived(int data);

};

#endif // ES_GENNP_CLIENT_H
