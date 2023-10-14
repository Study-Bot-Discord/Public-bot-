#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    string st1,st2;
    cout<<"Enter name of the file(with extension) from which data has to be taken\n";
    getline(cin,st1);
    ifstream read(st1);
    getline(read,st2);
    cout<<"Data is taken successfully\n";
    read.close();
    cout<<"Enter name of the file(with extension) where data has to be copied\n";
    getline(cin,st1);
    ofstream write(st1);
    write<<st2;
    cout<<"Data is copied successfully\n";
    write.close();
    return 0;
}
