#ifndef __REACTOR_H__
#define __REACTOR_H__
#include<time.h>

#include"reactor_impl.h"
#include"event_handler.h"
class reactor{
public:
    reactor();
    ~reactor();
public:
   static  reactor& instance();
   bool    regist(event_handler* handler,int event) ;
   void    remove(event_handler* handler);
   void    loop_evt(time_t timeout);


private:
    reactor_impl* _reactor_impl;
};

#endif