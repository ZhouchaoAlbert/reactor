#include"socket_handler.h"
#include <sys/types.h>
#include <sys/socket.h>

socket_handler::socket_handler(int socket_fd)
{
    _socket_fd   =  socket_fd;
}

socket_handler::~socket_handler()
{

}

int socket_handler::get_instance()
{
    return  _socket_fd;
}

void socket_handler::event_read()
{
    //读取客服端发来的数据

}

void socket_handler::event_write()
{

}

void socket_handler::event_error()
{

}