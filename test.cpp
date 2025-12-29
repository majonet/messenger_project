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

int main() {
    // list<string> passwords=load_data("passwords");
    list<string> passwords=load_data("username");
    int h=0;
    for(string i: passwords){
        h+=1;
        cout<<h<<" : "<<i<<endl;
    }
}
