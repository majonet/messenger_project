#include <iostream>
#include <ctime>
#include <list>
#include <bits/stdc++.h>
#include "simpledata.hpp"
#include <map>
#include "login_user.h"
#include <fstream>
#include <sstream>
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
                cout << a << endl;
            }
        }
    }

    return mylist;
}
void save_data(list<string> &user_names,list<string> &full_names,list<string> &birthday,list<string> &passwords,list<string> &time_creates){
  ofstream myfile;
	myfile.open("textFile.txt");
  myfile << "username,";
    for (string n : user_names)
    {
        myfile << n << ",";
    };
	myfile <<endl;
  myfile << "fullname,";
    for (string n : full_names)
    {
        myfile << n << ",";
    };
	myfile <<endl;
  myfile << "birthday,";
    for (string n : birthday)
    {
        myfile << n << ",";
    };
	myfile <<endl;
  myfile << "passwords,";
    for (string n : passwords)
    {
        myfile << n << ",";
    };
	myfile <<endl;
  myfile << "time_creates,";
    for (string n : time_creates)
    {
        myfile << n << ",";
    };
	myfile <<endl;

}
void sign_up(list<string> &user_names,list<string> &full_names,list<string> &birthday,list<string> &passwords,list<string> &time_creates){
//user_name
  cout<< "enter user name : "<<endl;
  string now_user;
  cin>> now_user;
  try{
   if (find(user_names.begin(), user_names.end(),now_user) != user_names.end()) {
      throw myerror("this user_name already exist");
   }
   else {
   user_names.push_back(now_user);}
  }
  catch (myerror &e) {
    e.show_error();
    }
//full_name
  cout<< "enter user full name : "<<endl;
  string f_name;
  cin>> f_name;
  full_names.push_back(f_name);
//birth_day
   simpledata s;
    try {
      cin >> s;
    }
    catch (myerror &e) {
        cout << "Error: ";
        e.show_error();
    } 
  string b= s.date_retrun();
  birthday.push_back(b);
//password
  cout<< "enter your password : "<<endl;
  string pass;
  do {
      cout << "Enter password (min 7 characters): ";
      cin >> pass;
   } while (pass.length() <= 6);
  passwords.push_back(pass);
//time_created
   time_t now = time(0);
   char* date_time = ctime(&now);
   cout<< "date time created : "<<date_time<<endl;
   time_creates=load_data("time_creates");
   full_names.push_back(date_time);

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

//login
void login(list<string> &user_names,list<string> &full_names,list<string> &birthday,list<string> &passwords,list<string> &time_creates){
  cout<< "enter user name : "<<endl;
  string now_user;
  cin>> now_user;
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
    cin>> pass;
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
    in_user.show_menu();
    cin >> choice;

    switch (choice) {
    case 1:
        in_user.show_all_users(user_names, full_names, birthday, passwords, time_creates);
        break;

    case 2:
        map<string, list<string>> conv=load_contacts("contact.txt");
        try{
        conv = in_user.new_conversation(in_user, conv, user_names);
        save_contacts("contact.txt", conv);  
      }
      catch (myerror &e) {
        cout << "Error: ";
        e.show_error();
        }
        break;

    case 3:
        map<string, list<string>> conv=load_contacts("contact.txt");
        
        in_user.show_conversation(current_user, conv);
        break;

    case 4:
        message_conv = in_user.show_send_message(current_user, message_conv);
        break;

    case 5:
        in_user.log_out();
        break;

    default:
        cout << "Invalid choice\n";
    }
        } while (choice != 5);

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
  // sign_up();
  //login(user_names,passwords);
}