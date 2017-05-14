#include <iostream>
#include <string>

using namespace std;

struct prod
{
    char left;
    string right;
    string second;
};

int remRec(prod p, prod r)
{
    string a,b,temp,temp1;
    temp = p.right;
    a.assign(temp.begin()+1,temp.end());
    temp = r.right;
    b.assign(temp);
    cout << p.left << " -> " << b << p.left << '`' << endl;
    cout << p.left << '`' << " -> " << a << p.left << '`' << endl;
    cout << p.left << '`' <<  " -> #" << endl;
    return 0;
}

int main()
{
    int n,i,k,j;
    char arrow;
    cout << "Number of productions : ";
    cin >> n;
    k=n+1;
    prod rules[n];
    for(i=0;i<n;i++)
    {
        cout << endl;
        cin >> rules[i].left;
        cin >> arrow >> arrow;
        cin >> rules[i].right;
    }
    for(i=0;i<n;i++)
    {
        cout << endl << "-------------------------------" << endl;
        cout << endl << "Analyzing production : " << i+1 << endl;
        if(rules[i].left == rules[i].right[0])
        {
            cout << "This production is recursive" << endl << "Removing Recursion ....." << endl << endl;
            for(j=0;j<n;j++)
            {
                if(j==i) continue;
                else if(rules[i].left == rules[j].left)
                {
                    remRec(rules[i],rules[j]);
                }
            }
        }
        else
        {
            cout << "This production is NOT recursive" << endl;
        }
    }
    return 0;
}
