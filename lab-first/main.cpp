#include <iostream>
#include <set>

using namespace std;

struct prod
{
    char left;
    string right;
} rules[10];

int n;
set<char> arr[10];

set<char> first(int j)
{
    set<char> temp;
    if(rules[j].right[0] == '#')
        temp.insert('#');
    else if(rules[j].right[0] < 65 && rules[j].right[0] > 90)
        temp.insert(rules[j].right[0]);
    return temp;
}

int main()
{
    int i;
    char arrow,target;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> rules[i].left;
        cin >> arrow >> arrow;
        cin >> rules[i].right;
    }
    for(i=0;i<n;i++)
    {
        target = rules[i].left;
        for()
    }
    return 0;
}
