#ifndef __EPOLL_IMPL_H__
#define __EPOLL_IMPL_H__
#include<map>
#include<time>

#include"event_handler.h"

class epoll_impl
{
public:
   bool    regist(int fd,int event) ;
   void    remove(int fd);
   void    wait_event(const std::map<int,event_handler*>& map_handlers,time_t timeout);
  

};

#endif