#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void login();
void registration();
void forgot();

int main()
{
    int c; //choice
    cout<<"\t\t\t________________________________________________________\n\n\n";
    cout<<"\t\t\t                 Welcome To Login Page                  \n\n\n";
    cout<<"\t\t\t                         MENU                           \n\n\n";
    cout<<"                                                                \n\n";
    cout<<"\t| Press 1 to LOGIN                         |"<<endl;
    cout<<"\t| Press 2 to REGISTER                      |"<<endl;
    cout<<"\t| Press 3 if you FORGOT your Password      |"<<endl;
    cout<<"\t| Press 4 to EXIT                          |"<<endl;
    cout<<"\n\t\t\t Please Enter your Choice- \n";
    cin>>c;
    cout<<endl;

    switch(c)
    {
        case 1:
            login();
            break;

        case 2:
            registration();
            break;

        case 3:
             forgot();
             break;

        case 4:
             cout<<"\t\t\t Thank you! \n\n";
             break;

        default:
            system("cls");
            cout<<"\t\t\t Choose a valid option \n";
            main();
    }
}

void login()
{
    int count;
    string userID, password, id, pass;
    system("cls");
    cout<<"\t\t\t Please enter the Username and Password"<<endl;
    cout<<"\t\t\t USERNAME  "<<endl;
    cin>>userID;
    cout<<"\t\t\t PASSWORD  \n";
    cin>>password;

    ifstream input("records.txt"); //input is object

    while(input<<id<<pass)
    {
        if(userID == id && pass == password)
        {
            count =1;
            system("cls");
        }

    }
    input.close();

    if(count == 1)
    {
        cout<<userID<<"\nSuccessfull LogIn\n";
        main();
    }
    else{
        cout<<"\n ERROR\n";
        main();
    }

}

void registration()
{
    int string ruserID, rpassword, rid, rpass;
    system("cls");
    cout<<"\t\t\t Please enter desired Username and Password"<<endl;
    cout<<"\t\t\t USERNAME  "<<endl;
    cin>>ruserID;
    cout<<"\t\t\t PASSWORD  \n";
    cin>>rpassword;

    ofstream f1("records.txt", ios::app); //f1 is object
    f1<<ruserID<<' '<<rpassword<<endl;
    system("cls");
    cout<<"\n Registration Successfull\n";
    main();
}


void forgot()
{
    int option;
    system("cls");
    cout<<"\nTo recover your password and search your id by username press 1\n";
    cout<<"\n Press 2 to go back to main menu"<<endl;
    cin>>option;

    switch(option)
    {
        case 1:
        {
            int count=0;
            string suserID, sid, spass;
            cout<<"\n Enter the last username you rememeber\n";
            cin>>suserID;

            ifstream f2("records.txt"); //f2 is object
            while(f2>>sid>>spass)
            {
                if(sid==suserID)
                {
                    count = 1;
                }
            }
            f2.close();
            if (count==1)
            {
                cout<<"\nYour account is found";
                cout<<"\nYOur password is: "<<spass;
                main();
            }
            else{
                cout<<"\n\t Oops! Account Not Found";
            }
            break;
        }

        case 2:
        {
            main();
            break;
        }

        default:
        {
            system("cls");
            cout<<"\t\t\t Choose a valid option \n";
            forgot();

        }
    }
}
