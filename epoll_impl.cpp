#include"epoll_impl.h"


bool    epoll_impl::regist(int fd,int event) 
{
    return false;
}

void    epoll_impl::remove(int fd)
{

}

void    epoll_impl::wait_event(const std::map<int,event_handler*>& map_handlers,time_t timeout)
{

}