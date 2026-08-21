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
    double account_balance;
    double asset_worth;
    int account_id;
    inline static int id = 0;
    inline static vector<user> users_data;

public:

    void print_user_details()
    {
        cout<<username<<"'s account"<<endl;
        cout<<"Account Balance:"<<account_balance<<endl;
        cout<<"Asset Worth:"<<asset_worth<<endl;
    }

    void register_user()
    {
        cout<<"Username: ";
        cin>>username;

        password = create_password();

        account_id = id;
        ++id;

        account_balance = 0;
        asset_worth = 0;

        cout<<"Your user id is: "<<this->account_id<<endl;
        users_data.push_back(*this);
    }

    user* login_user()
    {
        string password;

        user* found_user = search_user();
        if(found_user == nullptr){
            return nullptr;
        }

        cout<<"Enter Password:";
        cin>>password;

        if(found_user->password == password)
        {
            cout<<"Login successful"<<endl;
            return found_user;
        }
        else{
            cout<<"Incorrect Password"<<endl;
        }
        return nullptr;
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

void user_menu()
{
    cout<<"1.Deposit Money"<<endl;
    cout<<"2.Withdraw Money"<<endl;
    cout<<"3.View current investment Plan"<<endl;
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
                user* logged_user = existing_user.login_user();
                
                if(logged_user != nullptr)
                {
                    print_space();
                    user user_info = *logged_user;
                    user_info.print_user_details();
                    print_space();
                    user_menu();
                    int option = receive_input();
                    break;
                }
                
            }
            case EXIT:
            {
                cout<<"Exit"<<endl;
                quit = true;
            }
        }
    }
    
}