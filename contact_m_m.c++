#include "bits/stdc++.h"
using namespace std;

class temp {
    string phoneNo, name, address, description, search;
    fstream file;

public:
    void addContact();
    void showAll();
    void searchContact();
} obj;

int main() {
    char choice;
    while (true) {
        cout << "1 --> Add Contact" << endl;
        cout << "2 --> Show All Contact" << endl;
        cout << "3 --> Search Contact" << endl;
        cout << "0 --> exit" << endl;
        cin >> choice;
        cin.ignore(); // Fix: Clear input buffer before getline calls
        switch (choice) {
        case '1':
            obj.addContact();
            break;
        case '2':
            obj.showAll();
            break;
        case '3':
            obj.searchContact();
            break;
        case '0':
            return 0;
        default:
            cout << "Invalid Selection...!" << endl;
            break;
        }
    }
    return 0;
}

void temp::addContact() {
    cout << "Enter Phone Number:: ";
    getline(cin, phoneNo);
    cout << "Enter Name:: ";
    getline(cin, name);
    cout << "Enter Person Address:: ";
    getline(cin, address);
    cout << "Enter Description:: ";
    getline(cin, description);

    file.open("data.csv", ios::out | ios::app);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }
    file << phoneNo << "," << name << "," << address << "," << description << "\n";
    file.close();
}

void temp::showAll() {
    file.open("data.csv", ios::in);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    while (getline(file, phoneNo, ',') &&
           getline(file, name, ',') &&
           getline(file, address, ',') &&
           getline(file, description, '\n')) {
        cout << "Phone Number: " << phoneNo << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Description: " << description << endl << endl;
    }
    file.close();
}

void temp::searchContact() {
    cout << "Enter Phone Number: ";
    getline(cin, search);

    file.open("data.csv", ios::in);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    bool found = false;
    while (getline(file, phoneNo, ',') &&
           getline(file, name, ',') &&
           getline(file, address, ',') &&
           getline(file, description, '\n')) {
        if (phoneNo == search) {
            cout << "Phone Number: " << phoneNo << endl;
            cout << "Name: " << name << endl;
            cout << "Address: " << address << endl;
            cout << "Description: " << description << endl << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Contact not found!" << endl;
    }
    file.close();
}
