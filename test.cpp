#include <iostream>
#include <fstream>
#include <string>
#include<list>
using namespace std;


int main()
{ 
    list<string> l1={"ali","reza","hello"};
	string firstname, lastname, birthyear, birthmonth, date;
	cout << "Whats your firstname? "; getline(cin, firstname);
	cout << "Whats your lastname? "; getline(cin, lastname);
	cout << "Whats your birth year? "; getline(cin, birthyear);
	cout << "Whats your birth month? "; getline(cin, birthmonth);
	cout << "Whats your birth date? "; getline(cin, date);


	ofstream myfile;

	myfile.open("name.txt");
    myfile << "username,";
    for (string n : l1)
    {
        myfile << n << ",";
    };
	myfile <<endl;
	myfile << firstname<<endl;
	myfile << lastname<<endl;
	myfile << birthyear<<endl;
	myfile << birthmonth<<endl;
	myfile << date<<endl;
	myfile.close();

	return 0;
}