#pragma once
#include<iostream>
using namespace std;
#include "basic_message.h"
#include <map>
class voice_message:public basic_message{
private:
string voice_prompt; 
public:
    voice_message(user sender,char* date_time,string prompt=""):basic_message(sender,date_time),voice_prompt(prompt){};
    voice_message(){};
    ~voice_message(){};
    void print_message()override {cout<<voice_prompt<<"( this is a voice message )"<<endl;};
    
};
