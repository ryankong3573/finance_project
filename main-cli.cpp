#include <iostream>
#include <vector>
#include "headers.h"
using namespace std;

enum{
    REGISTER, LOGIN, EXIT
};

class user{

    string username;
    string password;
    int account_id;
    inline static int id = 0;
    inline static vector<user> users_data;

public:
    void register_user()
    {
        cout<<"Username: ";
        cin>>username;

        password = create_password();

        account_id = id;
        ++id;

        cout<<"Your user id is: "<<this->account_id;
        users_data.push_back(*this);
    }
};


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
        {
            user new_user;
            new_user.register_user();
            break;
        }
        case LOGIN:
        {
            cout<<"Login"<<endl;
            break;
        }
        case EXIT:
        {
            cout<<"Exit"<<endl;
            break;
        }
    }
}