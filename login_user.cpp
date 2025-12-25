#pragma once
#include "login_user.h"
#include <iostream>
#include <ctime>
#include <list>
#include <bits/stdc++.h>
#include <map>
void search_user(string b,const unordered_map<string, int>& user_map,
                      const list<string>& full_names,
                      const list<string>& birthday,
                      const list<string>& time_creates) 
    {
        if (user_map.count(b)) {
            cout << "user_name is found\n";
            int h = user_map.at(b);
            auto it_full = full_names.begin();
            advance(it_full, h);
            cout << "full_name: " << *it_full << endl;
            auto it_birth = birthday.begin();
            advance(it_birth, h);
            cout << "birthday: " << *it_birth << endl;
            auto it_time = time_creates.begin();
            advance(it_time, h);
            cout << "time_creates: " << *it_time << endl;
        }
        else {
            cout << "user name not found\n";
        }
    };
void login_user::save_action(){
  cout<<"your action is save"<<endl; 
}
void login_user::log_out(){ 
    save_action();
    cout<<"user logout success";     
}
template <typename T>
std::unordered_map<T, int> list_to_index_map(const std::list<T>& lst)
{
    std::unordered_map<T, int> result;
    int index = 0;

    for (const auto& item : lst) {
        result[item] = index++;
    }

    return result;
}
void login_user::show_all_users(list<string> &user_names,list<string> &full_names,list<string> &birthday,list<string> &passwords,list<string> &time_creates){
    cout<<"chose one of this: "<<endl; 
    cout<<"1_show user list"<<endl;
    cout<<"2_search with username or name"<<endl;
    cout<<"3_sorting with 1_username 2_membership date 3_id of user"<<endl;
    int a;
    cout<<"enter your chose:  ";
    cin>>a;
    switch (a) {

case 1: {
    for (const string& car : user_names) {
        cout << car << "\n";
    }
    break;
}

case 2: {
    cout << "enter username or name for search: " << endl;
    string b;
    cin >> b;
    auto user_map = list_to_index_map(user_names);
    auto search = [b](const unordered_map<string, int>& user_map,
                      const list<string>& full_names,
                      const list<string>& birthday,
                      const list<string>& passwords,
                      const list<string>& time_creates) 
    {
        if (user_map.count(b)) {
            cout << "user_name is found\n";
            int h = user_map.at(b);
            auto it_full = full_names.begin();
            advance(it_full, h);
            cout << "full_name: " << *it_full << endl;
            auto it_birth = birthday.begin();
            advance(it_birth, h);
            cout << "birthday: " << *it_birth << endl;
            auto it_time = time_creates.begin();
            advance(it_time, h);
            cout << "time_creates: " << *it_time << endl;
        }
        else {
            cout << "user name not found\n";
        }
    };
    search(user_map, full_names, birthday, passwords, time_creates);
    break;
}

case 3: {
    cout << "1_username 2_membership_date 3_id" << endl;
    int ch;
    cout<<"enter your chose:  ";
    cin>>ch;
    switch (ch){
    case 1: 
    auto user_map = list_to_index_map(user_names);
    
           
}

}

default:
    cout << "invalid option\n";
}
}