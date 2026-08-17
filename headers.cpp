#include <iostream>
#include "headers.h"
using namespace std;

int receive_input()
{
    int input;

    cout<<"Enter input:";
    cin>> input;

    return input - 1;
}

string create_password()
{
    bool password_confirmed = false;
        string password1, password2;
        while(!password_confirmed)
        {
            cout<<"Enter Password: ";
            cin>>password1;
            cout<<"Confirm Password: ";
            cin>>password2;

            if(password1==password2)
            {
                password_confirmed = true;
            }
            else
            {
                cout<<"Password is not the same (try again)"<<endl;
            }
        }
    return password1;
}

