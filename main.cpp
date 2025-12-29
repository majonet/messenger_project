#include <iostream>
#include <ctime>
#include <list>
#include <bits/stdc++.h>
#include "simpledata.hpp"
#include <map>
#include "login_user.h"
#include <fstream>
#include <sstream>
#include <fstream>
#include <set>
#include <limits>
#include <cstdlib>
#include <thread>
#include <chrono>
using namespace std;

list<string> load_data(string find) {
    ifstream f("textFile.txt");
    list<string> mylist;
    if (!f.is_open()) {
        cerr << "error opening the file";
        return mylist;
    }

    string s;
    while (getline(f, s)) {
        if (s.find(find) != string::npos) {
            stringstream ss(s);
            string a;

            while (getline(ss, a, ',')) {
                mylist.push_back(a);
                // cout << a << endl;
            }
        }
    }

    return mylist;
}
// void save_data(list<string> &user_names,list<string> &full_names,list<string> &birthday,list<string> &passwords,list<string> &time_creates){
//   ofstream myfile;
// 	myfile.open("textFile.txt");
//   myfile << "username,";
//     for (string n : user_names)
//     {
//         myfile << n << ",";
//     };
// 	myfile <<endl;
//   myfile << "fullname,";
//     for (string n : full_names)
//     {
//         myfile << n << ",";
//     };
// 	myfile <<endl;
//   myfile << "birthday,";
//     for (string n : birthday)
//     {
//         myfile << n << ",";
//     };
// 	myfile <<endl;
//   myfile << "passwords,";
//     for (string n : passwords)
//     {
//         myfile << n << ",";
//     };
// 	myfile <<endl;
//   myfile << "time_creates,";
//     for (string n : time_creates)
//     {
//         myfile << n << ",";
//     };
// 	myfile <<endl;

// }
void save_line(ofstream& out, string title, list<string>& data) {
    // out << title;
    for (string x : data) {
        out << x << "," ;
    }
    out << endl;
}
void sign_up(list<string> &user_names,list<string> &full_names,list<string> &birthday,list<string> &passwords,list<string> &time_creates){
//user_name
  cout<< "enter user name : "<<endl;
  string now_user;
//   cin>> now_user;
  getline(cin,now_user);
  try{
   if (find(user_names.begin(), user_names.end(),now_user) != user_names.end()) {
      throw myerror("this user_name already exist");
   }
   else {
   user_names.push_back(now_user);}
  }
  catch (myerror &e) {
    cout << "Error: ";
    e.show_error();
    sign_up(user_names,full_names,birthday,passwords,time_creates);
    return;
}
//full_name
  cout<< "enter user full name : "<<endl;
  string f_name;
//   cin>> f_name;
  getline(cin,f_name);
  full_names.push_back(f_name);
//birth_day
   simpledata s;
    try {
      cin >> s;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    catch (myerror &e) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: ";
        e.show_error();
        full_names.pop_back();
        user_names.pop_back();
        sign_up(user_names,full_names,birthday,passwords,time_creates);
        return;} 
  string b= s.date_retrun();
  birthday.push_back(b);
//password
  cout<< "enter your password : "<<endl;
  string pass;
  do {
      cout << "Enter password (min 7 characters): ";
    //   cin >> pass;
    getline(cin,pass);
   } while (pass.length() <= 6);
  passwords.push_back(pass);
//time_created
//    time_t now = time(0);
//    char* date_time = ctime(&now);
   time_t now = time(0);
   string date_time = ctime(&now);
   date_time.pop_back();
   cout<< "date time created : "<<date_time<<endl;
  //  time_creates=load_data("time_creates");
   time_creates.push_back(date_time);
    ofstream file("textFile.txt");
    save_line(file, "username",user_names);
    save_line(file, "fullname",full_names);
    save_line(file, "birthday",birthday);
    save_line(file, "passwords",passwords);
    save_line(file, "time_creates", time_creates);
    file.close();
   }
// (value,int)
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
// (int,value)
template <typename T>
unordered_map<int, T> list_to_index_map_RE(const list<T>& lst)
{
    unordered_map<int, T> result;
    int index = 0;

    for (const auto& item : lst) {
        result[index++] = item;
    }

    return result;
}

map<string, list<string>> load_contacts(const string& filename) {
    map<string, list<string>> conv;
    ifstream file(filename);

    if (!file) {
        cout << "contact file not found, starting empty.\n";
        return conv;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string user, contact;

        // first value = user
        getline(ss, user, ',');

        // remaining values = contacts
        while (getline(ss, contact, ',')) {
            conv[user].push_back(contact);
        }
    }

    file.close();
    return conv;
}
void save_contacts(const string& filename,
                   const map<string, list<string>>& conv) {
    ofstream file(filename, ios::trunc);

    for (const auto& [user, contacts] : conv) {
        file << user;
        for (const auto& c : contacts) {
            file << "," << c;
        }
        file << "\n";
    }

    file.close();
}

void append_pairs_with_message(const string& filename,
                               const map<string, list<string>>& conv,
                               const string& message)
{
    set<pair<string, string>> existing_pairs;
    ifstream in(filename);
    string line;
    while (getline(in, line)) {
        if (line.empty()) continue;

        string u, c;
        stringstream ss(line);
        getline(ss, u, ',');
        getline(ss, c, ',');

        if (u > c) swap(u, c);
        existing_pairs.insert({u, c});
    }
    in.close();
    ofstream out(filename, ios::app);

    for (const auto& [user, contacts] : conv) {
        for (const auto& contact : contacts) {

            if (user == contact) continue;

            string a = user;
            string b = contact;
            if (a > b) swap(a, b);

            if (existing_pairs.count({a, b}) == 0) {
                out << a << "," << b << "," << message << "\n";
                existing_pairs.insert({a, b});
            }
        }
    }

    out.close();
}
void save_messages(
    const map<list<string>, list<string>>& message_conv3,
    const string& filename)
{
    ofstream file(filename);
    if (!file) {
        cout << "Cannot open file\n";
        return;
    }

    for (const auto& item : message_conv3) {
        const list<string>& users = item.first;
        const list<string>& messages = item.second;
        auto it = users.begin();
        file << *it;
        ++it;
        file << "," << *it;
        for (const string& msg : messages) {
            file << "," << msg;
        }

        file << "\n";
    }

    file.close();
}

map<list<string>, list<string>> load_messages(const string& filename,
                   map<list<string>, list<string>>& message_conv)
{
    ifstream in(filename);
    string line;
    while (getline(in, line)) {
        if (line.empty()) continue;
        string u1, u2, msg;
        stringstream ss(line);
        getline(ss, u1, ',');
        getline(ss, u2, ',');
        getline(ss, msg);
        if (msg.empty()) msg = "";
        list<string> key = {u1, u2};
        key.sort();
        message_conv[key].push_back(msg);
    }
    in.close();
    return message_conv;
}

//login
void login(list<string> &user_names,list<string> &full_names,list<string> &birthday,list<string> &passwords,list<string> &time_creates){
  cout<< "enter user name : "<<endl;
  string now_user;
//   cin>> now_user;
  getline(cin,now_user);
  auto user_map = list_to_index_map(user_names);
  auto passwords_map = list_to_index_map_RE(passwords);
  auto full_names_map = list_to_index_map_RE(full_names);
  auto birthday_map = list_to_index_map_RE(birthday);
  auto time_creates_map= list_to_index_map_RE(time_creates);
  try{
   if (user_map.count(now_user)) {  
    // cout << "User found, index: " << user_map[now_user] << endl;
    cout<< "enter your password : "<<endl;
    string pass;
    // cin>> pass;
    getline(cin,pass);
    int h = user_map[now_user];
    try{
    if(passwords_map[h]==pass){
      cout<<"you loging succsesfully."<<endl;
      time_t now = time(0);          
      char* dt = ctime(&now);
      string dt_str(dt); 
    // int id,const string& user_name,const string& real_name,const string& password,string birth_day,string date_time,string login_time)
      login_user  in_user(h,now_user,full_names_map[h],passwords_map[h],birthday_map[h],time_creates_map[h],dt_str);
      bool epoch=true;
      int choice;
do {
    // std::this_thread::sleep_for(std::chrono::seconds(2));
    // system("cls");
    in_user.show_menu();
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    switch (choice) {
    case 1:{
        in_user.show_all_users(user_names, full_names, birthday, passwords, time_creates);
        break;}

    case 2:{
        map<string, list<string>> conv=load_contacts("contact.txt");
        try{
        conv = in_user.new_conversation(in_user, conv, user_names);
        save_contacts("contact.txt", conv);  
        append_pairs_with_message("conv_message.txt",conv,"");
      }
      catch (myerror &e) {
        cout << "Error: ";
        e.show_error();
        }
        break;}

    case 3:
        {map<string, list<string>> conv1=load_contacts("contact.txt");
        map<list<string>,list<string>> message_conv2;
        load_messages("conv_message.txt",message_conv2);
        in_user.show_conversation(in_user, conv1,message_conv2);
        break;}

    case 4:
        {map<list<string>,list<string>> message_conv3;
        load_messages("conv_message.txt",message_conv3);
        // message_conv3 = in_user.show_send_message(in_user, message_conv3);
        // cout<<"asdas"<<endl;
        message_conv3=in_user.show_send_message(in_user, message_conv3);
        save_messages(message_conv3,"conv_message.txt");
        break;}
    case 5:
        {in_user.log_out();
        in_user.~login_user();
        cout<<" chose on of this 1_login  2_sign up: "<<endl;
        int st_input;
        cin>>st_input;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (st_input == 1) {
        login(user_names, full_names, birthday, passwords, time_creates);
        } 
        else if (st_input == 2) {
            sign_up(user_names, full_names, birthday, passwords, time_creates);
        } 
        else {
            cout << "Invalid input, please choose 1 or 2." << endl;
        }
        break;}

    default:
        cout << "Invalid choice\n";
        break;
    }
        } while (true);

    }
    else{
    throw myerror("password is incorrect");}
    }
    catch (myerror &e) {
    e.show_error();
    }
  }
  else {
   throw myerror("this user_name not exist");}
  }
  catch (myerror &e) {
    e.show_error();
  }
}
int main() 
{
// load data
   list<string> user_names = load_data("username");
   list<string> full_names = load_data("fullname");
   list<string> birthday   = load_data("birthday");
   list<string> passwords=load_data("passwords");
   list<string>time_creates=load_data("time_creates");
//    cout<<" chose on of this 1_login  2_sign up: "<<endl;
//    int st_input;
//    cin>>st_input;
while (true) {
    string st_input;
    cout << "1. Login  2. Sign up  q. Quit Choose: ";
    cin >> st_input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (st_input == "1") {
        login(user_names, full_names, birthday, passwords, time_creates);
    }
    else if (st_input == "2") {
        sign_up(user_names, full_names, birthday, passwords, time_creates);
    }
    else if (st_input == "q") {
        cout << "Goodbye!" << endl;
        break;
    }
    else {
        cout << "Invalid input, please choose 1, 2, or q." << endl;
    }
    std::this_thread::sleep_for(std::chrono::seconds(2));
    system("cls"); 
 
}

}