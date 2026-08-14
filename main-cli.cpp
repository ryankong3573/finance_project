#include <iostream>
#include "headers.h"
using namespace std;

enum{
    REGISTER, LOGIN, EXIT
};

class user{
    string username;
    string password;
    int account_id;
public:
    user(string username, string password, int account_id)
    {
        this->username = username;
        this->password = password;
        this->account_id = account_id;
    }
};

void register_user(int &user_id)
{
    string username, password;
    int account_id;

    cout<<"Enter your username:";
    cin>>username;

    cout<<"Enter your password:";
    cin>>password;

    account_id = user_id;
    user_id += 1;
}

void menu()
{
    cout<<"Welcome to saver's app"<<endl;
    cout<<"1.Register new account"<<endl;
    cout<<"2.Login account"<<endl;
    cout<<"3.Exit"<<endl;
}

int main()
{
    int user_id = 0;

    menu();
    int user_choice = receive_input();
    switch(user_choice)
    {
        case REGISTER:
            register_user(user_id);
            break;
        case LOGIN:
            cout<<"Login"<<endl;
            break;
        case EXIT:
            cout<<"Exit"<<endl;
            break;
    }
}