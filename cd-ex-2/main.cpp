//PDA for language a^nb^n

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string str;
    stack<char> stck;
    int len,i,flag=0;

    cout << "Enter the string: ";
    cin >> str;

    len=str.length();

    for(i=0;i<len;i++)
    {
        if(str[i]=='a' && flag==0) stck.push(str[i]);
        else if(str[i]=='b')
        {
            if(stck.size()==0)
            {
                break;
            }
            else stck.pop();
            flag=1;
        }
        else break;
    }

    if(stck.size()==0 && i==len) cout << endl << "String accepted by PDA" << endl;
    else cout << endl << "String NOT accepted by PDA" << endl;

    return 0;
}
