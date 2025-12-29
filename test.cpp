#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() {
    string name;
    cout<<"simple  test cin"<<endl;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int i;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter your full name: ";
    getline(cin, name);   // reads the whole line (with spaces)

    cout << "You entered: " << name << endl;

    return 0;
}
