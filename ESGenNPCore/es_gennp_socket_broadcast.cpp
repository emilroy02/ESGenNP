#include "es_gennp_socket_broadcast.h"

ESGenNPSocketBroadcast::ESGenNPSocketBroadcast()
{
}

ESGenNPSocketBroadcast::~ESGenNPSocketBroadcast()
{
}

bool ESGenNPSocketBroadcast::CreateBind(uint32_t ipAddress, uint16_t port)
{
    bool bRet = m_pController->Create(17);//TBD should be custom value
    if(false == bRet)
        return false;

    bRet = m_pController->Bind(ipAddress, port);
    if(false == bRet)
        return false;

    //TBD create custom value for option and value parameters
    //#define SO_BROADCAST    0x0020
    //#define SOL_SOCKET      0xffff
    uint32_t broadCast = 1;
    bRet = m_pController->SetSocketOpt(0xFFFF, 0x0020,(const char *)&broadCast, sizeof(broadCast));
    if(false == bRet)
        return false;

    return true;
}
