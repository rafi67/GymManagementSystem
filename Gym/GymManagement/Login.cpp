#include <iostream>
#include <fstream>

using namespace std;


class LogIn {

public:
    void log() {
        string user, pass;
        cout << "User name: ";
        cin >> user;
        cout << "Password: ";
        cin >> pass;
        string data[2], userData;
        int i = 0;
        ifstream file("c:\\users\\rafis\\documents\\admin.txt");
        while(getline(file, userData)) data[i++] = userData;
        if(user==data[0] && pass==data[1]) cout << "Login Successful\n";
        else cout << "Wrong password or username\n";
    }

};
