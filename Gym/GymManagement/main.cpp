#include <iostream>
#include "password.cpp"
#include "Login.cpp"

using namespace std;

int main() {

    Admin p;
    LogIn l;
    p.check();
    l.log();

    return 0;

}
