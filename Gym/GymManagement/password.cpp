#include <iostream>
#include <fstream>

using namespace std;


class Admin {

public:
    void check() {
        ifstream file2("c:\\users\\rafis\\documents\\admin.txt");
        string user;
        getline(file2, user);
        file2.close();
        if(user.empty()) {
            ofstream file("c:\\users\\rafis\\documents\\admin.txt");
            file << "Admin\nadmin";
            file.close();
        }
    }

};


