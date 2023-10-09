#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <cstdlib>
#include <time.h>
using namespace std;

int continuewithforget = 0;

void login();
void loginadmin();
void Registeration();
void forget();
void viewallusers();
int main();
//void adminchoice();

void loginadmin() {
   system("cls");
   string admin_username = "aryanjiit";
   string admin_password = "jiit";
   string check_user, check_pass;

    cout <<"\n\n\n\t\t\t\t\t\tWelcome Admin Panel";
    cout<<"\n\n\n\n\t\t\t\t\t\tUsername:";
    cin >> check_user;
     cout<<"\n\t\t\t\t\t\tPassword:";
    char ch;
    ch = _getch();
     while(ch != 13){
      check_pass.push_back(ch);
      cout << '*';
      ch = _getch();
    }
    if (check_user == admin_username && check_pass == admin_password) {
       // adminchoice();
       cout << "successful!!";
    }
    else {
        cout<<"\n\n\t\t\t\tWrong password or username! Try Again please!"<<endl;
        system("pause");
        loginadmin();
    }
}


void login() {

    int counter;
    string username, check_user, check_pass;
    string password = "";
    string name, surname, age, nid;
    int count = 0;
    system("cls");
    cout <<"\n\n\n\t\t\t\t\t     Welcome to Gaming zone";
    cout<<"\n\n\n\n\t\t\t\t\t\tUsername:";
    cin>>username;
    cout<<"\n\t\t\t\t\t\tPassword:";
      char ch;
    ch=_getch();
    while(ch != 13){
      password.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   ifstream input ("database.txt");
   while (input >> name >> surname>> age >> nid >> check_user >> check_pass ) {
    if (username == check_user && password == check_pass) {
        counter = 1;
         system("games.exe");
    }
   }
   input.close();
  // if (counter == 1) {
   // system("cppproject-Games.exe");  // Link the final Exe file here!!
  // }
}

void Registration() {
    string name, surname;
    int age;
    string id;
     cout <<"\n\n\n\t\t\t\t\tWelcome to Gaming Console";
    cout<<"\n\n\n\t\t\t\t\tEnter your firstname:";
    cin>>name;
    cout<<"\n\t\t\t\t\tEnter your surname:";
    cin>>surname;
    cout<<"\n\t\t\t\t\tEnter your age:";
    cin>>age;
    cout<<"\n\t\t\t\t\tEnter your National ID(without spaces):";
    cin>>id;
    string regusername,regpassword;
    cout<<"\n\t\t\t\t\tEnter new username:";
    cin>>regusername;
    ifstream check("data.txt");
    string tempusername,tempHold;
    while(check>>tempusername&&check>>tempHold){
        if(tempusername==regusername){
            cout<<"\n\n\t\t\t\t\t Username already exist";
            check.seekg(0,ios::beg);
            cout<<"\n\t\t\t\t\tEnter new username:";
            cin>>regusername;
        }
    }
    cout<<"\n\t\t\t\t\tEnter new Password:";
    cin>>regpassword;
    ofstream reg("data.txt",ios::app);
    reg<<regusername<<" "<<regpassword<<" "<<id<<endl;
    ofstream regg("database.txt",ios::app);
    regg<<name<<" "<<surname<<" "<<age<<" "<<id <<" "<<regusername<<" "<<regpassword<<endl;

    cout<<"\n\t\t\t\t\tRegistration completed succesfully!";
    string decide;
    cout<<"\n\n\t\t\t\t\tDo you want to Login?(yes/no):";
    cin>>decide;
    if(decide=="yes"){
        login();
    }
    else{
        main();
    }
}

void forget(){
    int counter_forget=0;
    string uname,id,searchuser,searchpass,searchid;
    system("CLS");
    cout <<"\n\n\n\t\t\t\t\tWelcome to Gaming Console";
    cout <<"\n\n\n\t\t\t\t\t\tPASSWORD REMINDER ";
    cout<<"\n\n\n\n\t\t\t\t\tPlease Enter your username:";
    cin>>uname;
    cout<<"\n\t\t\t\t\tPlease Enter your National ID:";
    cin>>id;
    ifstream searchusername("data.txt");
    while(searchusername>>searchuser>>searchpass>>searchid){
        if(searchid==id&&searchuser==uname){
            counter_forget=1;
        }
    }
    searchusername.close();
    if(counter_forget==1){
        cout<<"\n\t\t\t\t\tYour password is "<<searchpass;
        cin.get();
        int choice ;
		cout<<"\n\n\t\t\t\t\tPress 1 to continue for menu ...";
    	cin>>choice;
        switch(choice){
    	case 1:
    		main();
            break;
        default: main(); break;
        }
    }
    else{
        cout<<"\n\t\t\t\t\tWrong Username,Please try again!"<<endl;
        cin.get();
        system("pause");
        system("CLS");
        forget();
    }
}

int main () {
     cout <<"\n\n\n\t\t\t\t\tWelcome to Gaming Console";
     cout << "\n\n\n\t\t\t\t\tWhat do you want to do!!";
     cout << "\n\n\n\t\t\t\t\t1. Login";
     cout << "\n\n\n\t\t\t\t\t2. Registration";
     cout << "\n\n\n\t\t\t\t\t3.Forgot Password";
     cout << endl;

     int j;
      cin >> j;
       if (j == 1) {
        login();
       }
       else if (j == 2) {
        Registration();
       }
       else if (j == 3) {
        forget();
       }
       else {
          cout << "INVALID RESPONSE!!";
          system("pause");
        int s = main();
       }

     return 0;
}
