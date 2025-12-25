#pragma once
#include <iostream>
#include "simpledata.hpp"
#include "user.h"
#include "list"
using namespace std;
class login_user:public user
{
private:
    char* login_time;
    // user local_user;
public:
    login_user(int id,string user_name,string real_name,string password,simpledata birth_day,char* date_time,char* login_time):user(id,user_name,real_name,password,birth_day,date_time),login_time(login_time){};
    login_user(){};
    ~login_user(){};
    //
    void save_action();
    void show_menu();
    void log_out();
    void new_conversation();
    void user_contact();
    void show_all_users(list<string> &user_names,list<string> &full_names,list<string> &birthday,list<string> &passwords,list<string> &time_creates);
    
};

