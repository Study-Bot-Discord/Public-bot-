#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    string st;
    cout<<"Enter the information to write in the afile.dat file \n";
    getline(cin,st);
    ofstream file("afile.dat",ios::binary);
    file.write((const char*)&st,sizeof(st));
    file.close();
    cout<<"Information is written in the file successfully\n";
    ifstream file1("afile.dat",ios::binary);
    file1.read((char *)&st,sizeof(st));
    cout<<"Data read from afile.dat file is: "<<st<<endl;
    file1.close();
    return 0;
}
