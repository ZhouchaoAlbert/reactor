#ifndef __REACTOR_IMPL_H__
#define __REACTOR_IMPL_H__
#include<time.h>
#include<map>

#include"epoll_impl.h"
#include"event_handler.h"

class reactor_impl{
public:
    reactor_impl();
     ~!reactor_impl();

public:
   bool    regist(event_handler* handler,int event) ;
   void    remove(event_handler* handler);
   void    loop_evt(time_t timeout);

private:
    epoll_impl* _epoll_impl;
    std::map<int,event_handler*> _map_handlers;
};

#endif