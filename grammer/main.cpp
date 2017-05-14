#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int len,i;
    cout << "The grammer is : " << endl << endl;
    cout << " A -> Ab" << endl;
    cout << " A -> a" << endl;
    cout << endl << "Enter a string : ";
    cin >> str;
    len = str.size();
    for(i=0;i<len;i++)
    {
        if(i==0 && str[i]=='a') continue;
        else if(i>0 && str[i]=='b') continue;
        else break;
    }
    if(i==len)
    {
        cout << endl << "String belongs to the Grammer" << endl;
    }
    else
    {
        cout << endl << "String does NOT belong to the Grammer" << endl;
    }
    return 0;
}
