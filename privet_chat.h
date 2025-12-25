#pragma once
#include<iostream>
#include "user.h"
#include "basic_message.h"
#include "basic_chat.h"
using namespace std;
#include <map>
enum type {text,voice};
class privet_message:public basic_chat
{
private:
    basic_message mes;
    user target;
public:
    // basic_message(user sender,char* date_time,type s_ty):sender(sender),date_time(date_time),s_ty(s_ty){};
    privet_message(int id,vector<user> users,string name_conv,user sender,char* date_time,type s_ty,user target):basic_chat(id,users,name_conv),mes(sender,date_time,s_ty),target(target){}
    ~privet_message();
};