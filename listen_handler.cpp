#include"listen_handler.h"
#include <sys/types.h>
#include <sys/socket.h>

#include"reactor.h"
#include"socket_handler.h"
#include"event.h"

listen_handler::listen_handler(int listen_fd)
{
    _listen_fd =  listen_fd;
}

listen_handler::~listen_handler()
{
    close(_listen_fd);
}

int listen_handler::get_instance()
{
    return _listen_fd;
}

void listen_handler::event_read()
{
    //当客户端连接时会触发到这里
    int socket_fd = accept(_listen_fd,NULL,NULL);
    
    socket_handler* _socket_handler = new socket_handler(socket_fd);
    assert(_socket_handler);
    reactor _reactor = reactor::instance();
    _reactor.register(_socket_handler,E_READ_EVENT);
}

void listen_handler::event_write()
{

}

void listen_handler::event_error()
{

}