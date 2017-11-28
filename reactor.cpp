#include"reactor.h"



reactor::reactor()
{
    _reactor_impl = new reactor_impl();
    assert(_reactor_impl);
}

reactor::~reactor()
{
  assert(_reactor_impl);
  delete _reactor_impl;
}

reactor::instance()
{
    static reactor obj;
    return obj;
}

 bool   reactor::regist(event_handler* handler,int event) ;
{
    return _reactor_impl->regist(handler,event);
}

void    reactor::remove(event_handler* handler)
{
    _reactor_impl->remove(handler);
}

void    reactor::loop_evt(time_t timeout)
{
    _reactor_impl->loop_evt(timeout);
}