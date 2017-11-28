#ifndef __SOCKET_HANDLER_H__
#define __SOCKET_HANDLER_H__
#include"event_handler.h"


class socket_handler : public event_handler
{
public:
    socket_handler(int socket_fd);
    ~socket_handler();

public:
    virtual int get_instance();
    virtual void event_read();
    virtual void event_write();
    virtual void event_error();

private:
    int _socket_fd;
};



#endif