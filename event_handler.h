#ifndef __EVENT_HANDLER_H__
#define __EVENT_HANDLER_H__

class event_handler
{
public:
    event_handler(){}
    virtual ~event_handler(){};
public:
    virtual int get_instance() = 0;
    virtual void event_read()  = 0;
    virtual void event_write() = 0;
    virtual void event_error() = 0;
}

#endif