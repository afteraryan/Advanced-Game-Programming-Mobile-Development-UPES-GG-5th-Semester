#include<iostream>
#include<string>

using namespace std;

string inputUser(string str)
{
    cout<<"Enter String: ";
    std::getline(cin,str);
    return str;
}

void output(string str)
{
    cout<<str;
}

int main()
{
    string str;
    str = inputUser(str);
    output(str);
    return 0;
}