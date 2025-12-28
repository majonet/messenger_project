#pragma once
#include <iostream>
#include "simpledata.hpp"
#include "user.h"
#include "list"
using namespace std;
class login_user:public user
{
private:
    string login_time;
public:
    login_user(int id,const string& user_name,const string& real_name,const string& password,string birth_day,string date_time,string login_time):user(id,user_name,real_name,password,birth_day,date_time),login_time(login_time){};
    login_user(){};
    ~login_user(){};
    //
    void show_menu();
    void log_out();
    void show_conversation(const login_user& u,map<string, list<string>>& conv);
    map<string, list<string>> new_conversation(login_user& u,map<string, list<string>>& conv,const list<string> &user_names);
    void show_all_users(list<string>&user_names,list<string> &full_names,list<string> &birthday,list<string> &passwords,list<string> &time_creates);
    map<list<string>, list<string>>show_send_message(const login_user& u,map<list<string>, list<string>>& message_conv);
};

