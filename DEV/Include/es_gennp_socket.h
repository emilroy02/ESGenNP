#ifndef ES_GENNP_SOCKET_H
#define ES_GENNP_SOCKET_H

#include <memory>

#include "es_gennp_common.h"
#include "es_gennp_socket_controller.h"

#ifdef _WIN32
#include "es_gennp_socket_controller_win.h"
#endif

/*This is an abstract class that just select the needed controller depending on platform*/
class ESGenNPSocket
{
public:
    ESGenNPSocket():m_pController(NULL)
    {
#ifdef _WIN32
        m_pController = std::make_shared<ESGenNPSocketControllerWin>();
#endif
    }

    virtual ~ESGenNPSocket()=0;

protected:
    std::shared_ptr<ESGenNPSocketController> m_pController;
};

inline ESGenNPSocket::~ESGenNPSocket(){}

#endif // ES_GENNP_SOCKET_H
