#include <iostream>
#include <fstream>
#include <string>
#define Max 1000000

using namespace std;

struct GymMember {
    string name;
    string address;
    string phone;
    string payInfo;
};

int cnt = 1, in = 0;

GymMember G[Max];

void addMemeber() {
    string name, address, phone, info;
    cout << "Enter name:\n";
    cin >> name;
    cout << "Enter Address:\n";
    cin >> address;
    cout << "Enter Phone Number:\n";
    cin >> phone;
    cout << "Enter Payment Info:\n";
    cin >> info;
    ofstream file("gymMember.dat", ios::out|ios::app);
    file << name << " " << address << " " << phone << " " << info << "\n";
    cout << "Data stored\n";
    file.close();
}

void StringSeperator(string Data) {
    int s = Data.size(), cnt1 = 0;

    for(int i=0; i<s; ++i) {
        if(cnt1==0) {
            if(Data[i]!=' ') G[in].name += Data[i];
            else {
                ++cnt1;
                continue;
            }
        }
        else if(cnt1==1) {
            if(Data[i]!=' ') G[in].address += Data[i];
            else {
                ++cnt1;
                continue;
            }
        }
        else if(cnt1==2) {
            if(Data[i]!=' ') G[in].phone += Data[i];
            else {
                ++cnt1;
                continue;
            }
        }
        else G[in].payInfo += Data[i];
    }
   ++in;
    ++cnt;
}

void dataRetrive() {
    ifstream file("gymMember.dat");
    string data;
    if(file.fail()) cout << "failed to open file\n";
    else {
        if(file.peek()==EOF) {
            cout << "No member found\n";
            file.close();
        }
        else {
            while(!file.eof()) {
                getline(file, data);
                StringSeperator(data);
            }
            file.close();
        }
    }
}

void display() {
    for(int i=0; i<cnt-2; ++i)
        cout << "Name: " << G[i].name << "\n" <<
        "Address: " << G[i].address << "\n" <<
        "Phone: " << G[i].phone << "\n" <<
        "Payment Information: " << G[i].payInfo << "\n\n";
}

void Delet_data() {
    ofstream file("GymMember.dat");
    if(file.fail()) cout << "unable to delete data\n";
    else {
        file.close();
        cout << "Data deleted successfully\n";
    }
}


int main() {

    int c;

    while(1) {
        cout << "Add member press 1\nShow all member's info press 2\n" <<
        "Delete all member's info press 3\nExit press 4\n";
        cin >> c;
        switch(c) {
            case 1:
                addMemeber();
                break;
            case 2:
                dataRetrive();
                display();
                break;
            case 3:
                Delet_data();
                break;
            case 4:
                exit(0);
            default:
                cout << "Wrong Input\n";
        }
    }

    return 0;

}
