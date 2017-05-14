#include <iostream>
#include <set>

using namespace std;

struct prod
{
    char left;
    string right;
}rules[10];

int n;

set<char> first(char nt, char tar)
{
    //cout << endl << "FIRST" << endl;
    int j;
    set<char> t,temp;
    for(j=0;j<n;j++)
    {
        if(rules[j].left==nt)
        {
            if(int(rules[j].right[0])<= 65 || int(rules[j].right[0]) >= 90)
            {
                t.insert(rules[j].right[0]);
            }
            else
            {
                if(rules[j].right[0] != tar)
                {
                    temp = first(rules[j].right[0], tar);
                    t.insert(temp.begin(),temp.end());

                }
            }
        }
    }
    return t;
}

set<char> follow(char nt_fol,char tar_fol)
{
    //cout << endl << "FOLLOW" << endl;
    int j;
    char nxt;
    set<char> t_fol,temp_fol;
    if(nt_fol==rules[0].left) t_fol.insert('$');
    for(j=0;j<n;j++)
    {
        std::size_t found = rules[j].right.find(nt_fol);
        if(found!=std::string::npos)
        {
            if(found==rules[j].right.size()-1 && rules[j].left!=tar_fol)
            {
                temp_fol = follow(rules[j].left,rules[j].left);
                t_fol.insert(temp_fol.begin(),temp_fol.end());
            }
            else
            {
                nxt = rules[j].right[found+1];
                //cout <<endl << "nxt=" <<nxt <<endl;
                //cout <<endl << "target=" <<nt_fol <<endl;
                //char fck;
                //cin >> fck;
                if(nxt<65 || nxt >90)
                {
                    t_fol.insert(nxt);
                }
                else
                {
                    temp_fol = first(nxt,nxt);
                    t_fol.insert(temp_fol.begin(),temp_fol.end());
                    std::set<char>::iterator fnd = t_fol.find('#');
                    if(fnd!=t_fol.end())
                    {
                        t_fol.erase(fnd);
                        if(rules[j].left!=tar_fol)
                        {
                            temp_fol = follow(rules[j].left,rules[j].left);
                            t_fol.insert(temp_fol.begin(),temp_fol.end());
                        }
                    }
                }
            }
        }
    }
    return t_fol;
}

int main()
{
    int i,k=0,p;
    char arrow,target,done[10];
    cout << "Number of productions : ";
    cin >> n;
    set<char>::iterator iter;
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
        set<char> q = follow(target,target);
        cout << endl << "FOLLOW(" << target << ") = { ";
        for(iter=q.begin();iter!=q.end();++iter)
        {
            //if(iter!=q.begin()) cout << " , ";
            cout << *iter << "  ";
        }
        cout << " }" << endl;

        done[k]= target;
        k++;
    }
    return 0;
}

