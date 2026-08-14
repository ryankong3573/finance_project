#include <iostream>
#include "headers.h"
using namespace std;

enum{
    REGISTER, LOGIN, EXIT
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
    menu();
    int user_choice = receive_input();
    switch(user_choice)
    {
        case REGISTER:
            cout<<"Register"<<endl;
            break;
        case LOGIN:
            cout<<"Login"<<endl;
            break;
        case EXIT:
            cout<<"Exit"<<endl;
    }
}