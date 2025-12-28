#include <iostream>   // needed for cout
#include <fstream>
#include <sstream>
#include <map>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

void load_messages(const string& filename,
                   map<list<string>, list<string>>& message_conv)
{
    ifstream in(filename);
    string line;

    while (getline(in, line)) {
        if (line.empty()) continue;

        string u1, u2, msg;
        stringstream ss(line);

        // read first two users
        getline(ss, u1, ',');
        getline(ss, u2, ',');

        // rest of line = message
        getline(ss, msg);
        if (msg.empty()) msg = "";

        // normalize alphabetical order for key
        list<string> key = {u1, u2};
        key.sort();

        // add message
        message_conv[key].push_back(msg);
    }

    in.close();
}

int main() {
    map<list<string>, list<string>> message_conv;

    load_messages("pairs.txt", message_conv);

    // print loaded messages
    for (const auto& [key, msgs] : message_conv) {
        auto it = key.begin();
        cout << *it++ << " - " << *it << " :\n";
        for (const auto& m : msgs) {
            cout << "    " << m << endl;
        }
    }

    return 0;
}
