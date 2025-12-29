#include "login_user.h"

void search_user(string b,const map<string, int>& user_map,
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
// void login_user::save_action(){
//   cout<<"your action is save"<<endl; 
// }
void login_user::show_menu() {
    cout << "=============================\n";
    cout << "        MAIN MENU\n";
    cout << "=============================\n";
    cout << "1. Show all users\n";
    cout << "2. New conversation\n";
    cout << "3. Show conversations\n";
    cout << "4. Send message\n";
    cout << "5. Logout\n";
    cout << "=============================\n";
    cout << "Enter your choice: ";
}


void login_user::log_out(){ 
    cout<<"user logout success";     
}
template <typename T>
std::map<T, int> list_to_index_map(const std::list<T>& lst)
{
    std::map<T, int> result;
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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
    // cin >> b;
    getline(cin,b); 
    auto user_map = list_to_index_map(user_names);
    auto search = [b](const map<string, int>& user_map,
                      const list<string>& full_names,
                      const list<string>& birthday,
                      const list<string>& passwords,
                      const list<string>& time_creates) 
    {
        if (user_map.count(b)) {
            cout << "user_name is found\t";
            int h = user_map.at(b);
            auto it_full = full_names.begin();
            advance(it_full, h);
            cout << "full_name: " << *it_full << "\t";
            auto it_birth = birthday.begin();
            advance(it_birth, h);
            cout << "birthday: " << *it_birth << "\t";
            auto it_time = time_creates.begin();
            advance(it_time, h);
            cout << "time_creates: " << *it_time <<"\t";
        }
        else {
            cout << "user name not found\n";
        }
        cout<<endl;
    };
    search(user_map, full_names, birthday, passwords, time_creates);
    break;
}

case 3: {
    cout << "1_username 2_membership_date 3_id" << endl;
    int ch;
    cout<<"enter your chose:  ";
    cin>>ch;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    switch (ch){
    case 1:{ 
    auto user_map = list_to_index_map(user_names);
    for (const auto& [k, v] : user_map) {
    cout << k << " : " << v << std::endl;
    search_user(k,user_map, full_names, birthday,time_creates);}
    break;}
    case 2:{
    auto user_map = list_to_index_map(user_names);
    for (const auto& item : user_names) {
        search_user(item,user_map, full_names, birthday,time_creates);
    } 
    break;}
    case 3:{
    cout<<"id"<<endl;
    auto user_map = list_to_index_map(user_names);
    for (const auto& item : user_names) {
        search_user(item,user_map, full_names, birthday,time_creates);
    } 
    break;}
         
}

}

default:
    cout << "invalid option\n";
}
}

map<string, list<string>> login_user::new_conversation(login_user& u, map<string, list<string>>& conv,const list<string> &user_names)
{
    string s = u.get_user_name();
    cout<<"enter username you want for privet chat :  "<<endl;
    string si;
    // cin>>si;
    getline(cin, si);
    auto user_map = list_to_index_map(user_names);
    if (user_map.count(si)) {
        cout << "user_name is found\n";
        list<string> contact=conv[s];
        auto it = find(contact.begin(), contact.end(), si);
        if (it != contact.end()) {
            cout << si << " exists in the list." << endl;
            throw myerror("exists in the list.");
        } else {
            contact.push_back(si);
            cout << si << "add to  "<<s<<"  list contact "<< endl;
            conv[s]=contact;
        } 
    }
    else{cout << "user_name is not found\n";}
    return conv;
}

void login_user::show_conversation(const login_user& u,map<string, list<string>>& conv){
    cout<<"choose one 1_sort base name. 2_search with user_name"<<endl;
    int i;
    cin>> i;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    list<string> contact_user=conv[u.get_user_name()];
    auto user_map = list_to_index_map(contact_user);
    switch (i) {
    case 1:
        for (const auto& [k, v] : user_map) {cout << k << " : " << v << endl;}
        break;
    case 2: {
        cout << "write user_name to find: " << endl;
        string user_n;
        // cin >> user_n;
        getline(cin, user_n);
        auto it = user_map.find(user_n);
        if (it != user_map.end()) {
            cout << "user id is " << it->second << endl;
        } else {
            cout << "user not found" << endl;
        }
        break;
    }}
}

map<list<string>, list<string>>  login_user::show_send_message(const login_user& u,map<list<string>, list<string>>& message_conv){
    string name= u.get_user_name();
    cout<<"write username you want to chat" <<endl;
    string user_n;
    // cin>> user_n;
    getline(cin,user_n);
    list<string>key;
    key.push_back(name);
    key.push_back(user_n);
    key.sort();
    auto it = message_conv.find(key);
    if (it != message_conv.end()) {
        string user_id;
        user_id=to_string(u.get_user_id()); 
        cout<<"your id is : "<<user_id<<endl;
        for (string x : message_conv[key]) {cout << x << endl;}
        cout << "send your message (type q to quit, voice message end with -v-):" << endl;
        string input;
        while (true) {
                getline(cin, input);

                if (input == "q") {
                    break;
                }

                time_t now = time(0);
                string dt_str = ctime(&now);
                dt_str.pop_back();

                if (input.size() >= 3 && input.substr(input.size() - 3) == "-v-") {
                    voice_message meg(u, ctime(&now), input);

                    string out_p;
                    out_p = user_id + "--> " + dt_str + "  :  " + input + "  (voice)";
                    message_conv[key].push_back(out_p);
                }
                else {
                    text_message meg(u, ctime(&now), input);

                    string out_p;
                    out_p = user_id + "--> " + dt_str + "  :  " + input + "  (text)";
                    message_conv[key].push_back(out_p);
                }
            }
        }
    else {
        cout << "user not found or not have chat with you" << endl;
    }
    return message_conv;
};

