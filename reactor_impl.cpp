#include"reactor.h"


reactor_impl::reactor_impl()
{
    _epoll_impl = new epoll_impl();
    assert(_epoll_impl);
}

reactor_impl::~!reactor_impl() 
{
    delete _epoll_impl;
}

bool    reactor_impl::regist(event_handler* handler,int event) 
{
    int fd =  handler->get_instance();
    auto it  = _map_handlers.find(fd);
    if(it == _map_handlers.end())
    {
        _map_handlers.insert(std::make_pair<int,event_handler*>(fd,handler));
    }
    return _epoll_impl->regist(fd,event);
}

void    reactor_impl::remove(event_handler* handler)
{
    int fd =  handler->get_instance();
    auto it  = _map_handlers.find(fd);
    if(it != _map_handlers.end())
    {
        delete it->second;
        _map_handlers.erase(it);
    }
}

void    reactor_impl::loop_evt(time_t timeout)
{
    _epoll_impl->wait_event(_map_handlers,timeout);
}