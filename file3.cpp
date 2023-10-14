#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    int status;
    char st[50];
    cout<<"Enter name of the file(with extension)\n";
    cin>>st;
    status=remove(st);
    if(status==0)
    cout<<"File removed successfully";
    else
    cout<<"Error occurred";
    return 0;
}
