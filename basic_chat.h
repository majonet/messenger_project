#pragma once
#include <iostream>
#include<vector>
#include "user.h"
using namespace std;
class basic_chat
{
private:
    int id;
    vector<user> users;
    string name_conv;
public:
    basic_chat(int id,vector<user> users,string name_conv):id(id),users(users),name_conv(name_conv){};
    basic_chat(){};
    ~basic_chat(){};
    // friend istream& operator>> (istream& in,simpledata& sim);

};

