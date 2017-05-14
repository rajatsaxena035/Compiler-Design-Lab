#include <iostream>
#include <string>

using namespace std;

struct prod
{
    char left;
    string right;
};

int main()
{
    int n,i,k,j,status,flag;
    char arrow;
    cout << "Number of productions : ";
    cin >> n;
    prod rules[n];
    for(i=0;i<n;i++)
    {
        cout << endl;
        cin >> rules[i].left;
        cin >> arrow >> arrow;
        cin >> rules[i].right;
    }
    cout << endl << "------------------------------------" << endl;
    for(i=0;i<n;i++)
    {
        status=0;
        flag=0;
        if(rules[i].right == "#")
        {
            flag=1;
            break;
        }
        else
        {
            k= rules[i].right.length();
            for(j=0;j<k;j++)
            {
                if(rules[i].right[j]>64 && rules[i].right[j]<91)
                {
                    if(status==1)
                    {
                        flag=1;
                        break;
                    }
                    else status=1;
                }
                else status=0;
            }
            if(flag==1)
            {
                break;
            }
        }
    }
    if(flag==1) cout << endl << "It is NOT an Operator Precedence Grammer." << endl;
    else cout << endl << "It is an Operator Precedence Grammer" << endl;
    cout << endl << "------------------------------------" << endl;
    return 0;
}
