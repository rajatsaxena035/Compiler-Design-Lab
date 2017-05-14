#include <iostream>
#include <stack>

using namespace std;

int main()
{
    // variables declarations and initializations
    string str;
    stack<char> pda;
    char first;
    int i,status=0,len,flag=0;

    //input the string
    cin >> str;
    first=str[0];
    len=str.size();

    //logic
    if(first=='b' || len==0) status=1;
    else
    {
        for(i=0;i<len;i++)
        {
            if(str[i]=='a')
            {
                pda.push(first);
                flag=1;
            }
            else if(str[i]=='b' && str[i-1]!='b')
            {
                pda.pop();
                flag=0;
            }
            else
            {
                status=1;
                break;
            }
        }
    }

    //output
    if(status==1 || pda.size()!=0) cout << "\nNo\n";
    else cout << "\nYes\n";

    return 0;
}
