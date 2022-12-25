#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#define Max 1000000

using namespace std;

struct GymMember {
    int id;
    string name;
    string address;
    string phone;
    string payInfo;
};

int cnt = 1, in = 0, ID = 1;

GymMember G[Max];

void addMemeber() {
    string name, address, phone, info;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter name:\n";
    getline(cin, name);
    cout << "Enter Address:\n";
    getline(cin, address);
    cout << "Enter Phone Number:\n";
    cin >> phone;
    cout << "Enter Payment Info:\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, info);
    ofstream file("gymMember.dat", ios::out|ios::app);
    file << ID++ << "*" << name << "*" << address << "*" << phone << " " << info << "\n";
    cout << "Data stored\n";
    file.close();
}

void StringSeperator(string Data) {
    int s = Data.size(), cnt1 = 0;

    for(int i=0; i<s; ++i) {
        if(cnt1==0) {
            G[i].id = 0;
            if(Data[i]!='*') {
                G[i].id *= 10;
                G[i].id += Data[i]-'0';
            }
            else {
                ++cnt1;
                ID = G[i].id+1;
                continue;
            }
        }
        else if(cnt1==1) {
            if(Data[i]!='*') G[in].name += Data[i];
            else {
                ++cnt1;
                continue;
            }
        }
        else if(cnt1==2) {
            if(Data[i]!='*') G[in].address += Data[i];
            else {
                ++cnt1;
                continue;
            }
        }
        else if(cnt1==3) {
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

void Delete_data() {
    ofstream file("GymMember.dat");
    if(file.fail()) cout << "unable to delete data file not found\n";
    else {
        file.close();
        cout << "Data deleted successfully\n";
    }
}

int Linear_Search(string n) {
    for(int i=0; i<cnt-2; ++i) if(G[i].name==n) return i;
    return -1;
}

void Delete_Seperately() {
    string name;
    cout << "Enter the name to delete: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);
    if(cnt==1) dataRetrive();
    int index = Linear_Search(name);
    if(index==-1) cout << "Deletion failed, Data not found\n";
    else {
        for(int i=index; i<cnt-3; ++i) {
            G[i].id = G[i+1].id;
            G[i].name = G[i+1].name;
            G[i].address = G[i+1].address;
            G[i].phone = G[i+1].phone;
            G[i].payInfo = G[i+1].payInfo;
        }
        --cnt;
        ofstream file("gymMember.dat");
        for(int i=0; i<cnt-2; ++i) file << G[i].id << "*" << G[i].name
        << "*" << G[i].address << "*" << G[i].phone << " " << G[i].payInfo;
        file.close();
        cout << "Successfully deleted member " << name << "\n";
    }
}


int main() {

    int c;

    while(1) {
        cout << "Add member press 1\nShow all member's info press 2\n" <<
        "Delete all member's info press 3\nDelete member indiviually press 4\nExit press 5\n";
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
                Delete_data();
                break;
            case 4:
                Delete_Seperately();
                break;
            case 5:
                exit(0);
            default:
                cout << "Wrong Input\n";
        }
    }

    return 0;

}
