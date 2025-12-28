#pragma once
#include<iostream>
using namespace std;
#include "basic_message.h"
#include <map> 

class text_message:public basic_message{
private:
    string text_prompt;
public:
    text_message(user sender,char* date_time,string text_prompt):basic_message(sender,date_time),text_prompt(text_prompt){};
    text_message(){};
    ~text_message(){};
    void print_message()override {cout<<text_prompt<<"( this is a text message )"<<endl;};
};
