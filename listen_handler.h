#ifndef __LISTEN_HANDLE_H__
#define __LISTEN_HANDLE_H__
#include"event_handler.h"
class listen_handler : public event_handler
{
public:
    listen_handler(int listen_fd);
    ~listen_handler();
    virtual int get_instance();
    virtual void event_read();
    virtual void event_write();
    virtual void event_error();
private:
    int _listen_fd;
};


#endif