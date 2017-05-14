#include <iostream>
#include <set>
#include <string>

using namespace std;

struct prod
{
    char left;
    string right;
};


int main()
{
    int n,i,j=0;
    string k,a,b;
    char arrow;
    cout << "Number of productions : ";
    cin >> n;
    set<char>::iterator iter;
    prod rules[n];
    for(i=0;i<n;i++)
    {
        cout << endl;
        cin >> rules[i].left;
        cin >> arrow >> arrow;
        cin >> rules[i].right;
    }
    cout << endl << "Removing Left Factoring : " << endl;
    for(i=0;i<n;)
    {
        if(rules[i].left == rules[i+1].left && rules[i].right[0] == rules[i+1].right[0])
        {
            k = rules[i].right[0];
            for(j=1;rules[i].right[j] == rules[i+1].right[j];j++)
            {
            }
            k.assign(rules[i].right.begin(),rules[i].right.begin()+j);
            a.assign(rules[i].right.begin()+j,rules[i].right.end());
            if(a.size()==0)
            {
                a = '#';
            }
            b.assign(rules[i+1].right.begin()+j,rules[i+1].right.end());
            if(b.size()==0)
            {
                b = '#';
            }
            cout << endl << rules[i].left << " -> " << k << rules[i].left << '`' << endl;
            cout << endl << rules[i].left << '`' << " -> " << a << endl;
            cout << endl << rules[i].left << '`' << " -> " << b << endl;
            i+=2;
        }
        else
        {
            cout << endl << rules[i].left << " -> " << rules[i].right << endl;
            i++;
        }
    }
    return 0;
}
