#include <iostream>
#include <set>

using namespace std;

struct prod
{
    char left;
    string right;
};

set<char> first(char nt, prod rules[], int num, char tar)
{
    int j;
    set<char> t,temp;
    for(j=0;j<num;j++)
    {
        if(rules[j].left==nt)
        {
            if(int(rules[j].right[0])< 65 || int(rules[j].right[0]) > 90)
            {
                t.insert(rules[j].right[0]);
            }
            else
            {
                if(rules[j].right[0] != tar)
                {
                    temp = first(rules[j].right[0],rules, num, tar);
                    t.insert(temp.begin(),temp.end());

                }
            }
        }
    }
    return t;
}

int main()
{
    int n,i,k=0,p;
    char arrow,target,done[10];
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
    for(i=0;i<n;i++)
    {
        target = rules[i].left;
        for(p=0;p<=k;p++)
        {
            if(done[p]==target)
            {
                break;
            }
        }
        if(p!=k+1)
        {
            continue;
        }
        set<char> q = first(target,rules,n,target);
        cout << endl << "FIRST(" << target << ") = { ";
        for(iter=q.begin();iter!=q.end();++iter)
        {
            if(iter!=q.begin()) cout << " , ";
            cout << *iter;
        }
        cout << " }" << endl;

        done[k]= target;
        k++;
    }
    return 0;
}
