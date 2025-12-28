#pragma once
#include <iostream>
#include "simpledata.hpp"
using namespace std;
class user
{
private:
    int id;
    string user_name;
    string real_name;
    string password;
    string birth_day ;
    string date_time;
public:
    user( int id,string user_name,string real_name,string password,string birth_day,string date_time):
    id(id),user_name(user_name),real_name(real_name),password(password),birth_day(birth_day),date_time(date_time){};
    string get_user_name() const {return user_name;}
    int get_user_id() const {return id;}
    user(){};
    ~user(){};

};

