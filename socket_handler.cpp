#include"socket_handler.h"
#include <sys/types.h>
#include <sys/socket.h>

socket_handler::socket_handler(int socket_fd)
{
    _socket_fd   =  socket_fd;
    _buf = new char[1024];
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
   if ( 0 < read(_socket_fd, buf, 1024 ))
    {
        //打印
        write(_socket_fd, buf, strlen(buf));
    }
}

void socket_handler::event_write()
{

}

void socket_handler::event_error()
{

}