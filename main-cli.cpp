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

        cout<<"Your user id is: "<<this->account_id<<endl;
        users_data.push_back(*this);
    }

    void login_user()
    {
        string password;

        user* user = search_user();
        if(user == nullptr){
            cout<<"Enter username again."<<endl;
            return;
        }

        cout<<"Enter Password:";
        cin>>password;

        if(user->password == password)
        {
            cout<<"Login successful"<<endl;
        }
        else{
            cout<<"Incorrect Password"<<endl;
        }

    }

    user* search_user()
    {
        string username;
        cout<<"Enter username: ";
        cin>>username;

        for(int i = 0; i<users_data.size(); i++)
        {
            if(username == users_data[i].username)
            {
                return &users_data[i];
            }
        }
        cout<<"Username not found.";
        return nullptr;
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
    bool quit = false;

    while(quit == false)
    {
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
                user existing_user;
                existing_user.login_user();
                break;
            }
            case EXIT:
            {
                cout<<"Exit"<<endl;
                quit = true;
            }
        }
    }
    
}