#include<iostream>
#include<fstream>
using namespace std;
//writing into a file
int main()
{
    ofstream input("file1.txt");
    string st;
    cout<<"Enter the information to store in the file \n";
    getline(cin,st);
    input<<st<<endl;
    cout<<"Information is stored in the file successfully\n";
    return 0;
}
