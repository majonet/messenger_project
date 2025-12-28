#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <list>
#include <string>

using namespace std;

/* ---------- LOAD CONTACTS ---------- */
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

        getline(ss, user, ',');

        while (getline(ss, contact, ',')) {
            conv[user].push_back(contact);
        }
    }

    file.close();
    return conv;
}

/* ---------- SAVE CONTACTS ---------- */
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

/* ---------- SHOW CONTACTS ---------- */
void show_contacts(const map<string, list<string>>& conv) {
    for (const auto& [user, contacts] : conv) {
        cout << user << " : ";
        for (const auto& c : contacts) {
            cout << c << " ";
        }
        cout << endl;
    }
}

/* ---------- ADD CONTACT ---------- */
void add_contact(map<string, list<string>>& conv,
                 const string& user,
                 const string& contact) {
    auto& lst = conv[user];

    for (const auto& c : lst) {
        if (c == contact) {
            cout << "contact already exists\n";
            return;
        }
    }

    lst.push_back(contact);
    cout << "contact added\n";
}

/* ---------- MAIN ---------- */
int main() {
    map<string, list<string>> conv;

    conv = load_contacts("contact.txt");

    cout << "\n--- Contacts loaded ---\n";
    show_contacts(conv);

    cout << "\nAdd new contact\n";
    string user, contact;
    cout << "user: ";
    cin >> user;
    cout << "contact: ";
    cin >> contact;

    add_contact(conv, user, contact);

    cout << "\n--- Updated contacts ---\n";
    show_contacts(conv);

    save_contacts("contact.txt", conv);

    cout << "\nContacts saved to file.\n";
    return 0;
}
