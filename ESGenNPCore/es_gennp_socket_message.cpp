#include "es_gennp_socket_message.h"

ESGenNPSocketMessage::ESGenNPSocketMessage()
{
}

ESGenNPSocketMessage::~ESGenNPSocketMessage()
{
}

bool ESGenNPSocketMessage::Connect(int protocol, uint64_t ipAddress, uint16_t port)
{

    if(!m_pController)
        return false;

    bool bRet = m_pController->Create(protocol);
    if(false == bRet)
        return false;

    bRet = m_pController->Connect(ipAddress, port);
    if(false == bRet)
    {
        //TBD add m_pController->Destroy
        return false;
    }

    return true;
}
