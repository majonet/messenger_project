#pragma once
#include<iostream>
#include "user.h"
using namespace std;
#include <map>
// enum type {text,voice};
class basic_message
{
private:
    user sender;
    char* date_time;
    // type s_ty;
public:
    basic_message(user sender,char* date_time):sender(sender),date_time(date_time){};
    basic_message(){};
    ~basic_message(){};
    virtual void print_message(){cout<<"your message created (basic message);"<<endl;};
};

