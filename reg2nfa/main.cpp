#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    struct current
    {
        int first,last;
    } stat[15];

    int l,j,change,n=0,i=0,state=1,x,y,start,fin;
    char store,*input1,input[15];
    cout << "\n\n****ENTER THE REGULAR EXPRESSION****\n\n";
    cin >> input1;

    for(i=0;i<10;i++) input[i]=NULL;

    l=strlen(input1);
    a:
    for(i=0;input1[i]!=')';i++);
    for(j=i;input1[j]!='(';j--);
    for(x=j+1;x<i;x++)
    if(isalpha(input1[x]))
    input[n++]=input1[x];
    else if(input1[x]!='0')
    store=input1[x];
    input[n++]=store;
    for(x=j;x<=i;x++)
    input1[x]='0';
    if(input1[0]!='0')
    goto a;
    cout << "\n\n\tFROM\tTO\tINPUT\n\n";
    i=0;
    while(input[i]!='\0')
    {
    if(isalpha(input[i]))
    {
    stat[i].first=state++;
    stat[i].last=state++;
    cout << "\n\t%d\t%d\t%c",stat[i].first,stat[i].last,input[i];
    }
    else
    {
    change=0;
    switch(input[i])
    {
    case'|':
    stat[i].first=state++;
    stat[i].last=state++;
    x=i-2;
    y=i-1;
    if(!isalpha(input[y]))
    {
    b:
    switch(input[y])
    {
    case'*':if(!isalpha(input[y-1]))
    {
    y=y-1;
    goto b;
    }
    else
    x=y-2;
    break;
    case'|':x=y-3;
    break;
    case '.':x=y-3;break;
    }
    change=1;
    }
    if(!isalpha(input[y]&&change==0))
    c:switch(input[x])
    {
    case '*':
    if(!isalpha(input[x-1]))
    {x=x-1;goto c;
    }
    else x=x-2;
    break;
    case'|':x=x-2;
    break;
    case '.':x=x-3;
    break;
    }
    cout << "\n\t%d\t%d\tE",stat[i].first,stat[x].first;
    cout << "\n\t%d\t%d\tE",stat[x].last,stat[i].last;
    cout << "\n\t%d\t%d\tE",stat[i].first,stat[i-1].first;
    cout << "\n\t%d\t%d\tE",stat[i-1].last,stat[i].last;
    start=stat[i].first;
    fin=stat[i].last;
    break;
    case'.':
    x=i-2;
    y=i-1;
    if(!isalpha(input[y]))
    {
    d:
    switch(input[y])
    {
    case'*':if(!isalpha(input[y-1]))
    {
    y=y-1;
    goto d;
    }
    else
    x=y-2;
    break;
    case'|':x=y-3;
    break;
    case '.':x=y-3;
    break;
    }
    change=1;
    }
    if(!isalpha(input[y]&&change==0))
    e:switch(input[x])
    {
    case'*':
    if(!isalpha(input[x-1]))
    {
    x=x-1;
    goto e;
    }
    else x=x-2;
    break;
    case'|':x=x-3;
    break;
    case'.':x=x-3;
    break;
    }
    stat[i].last=stat[y].last;
    stat[i].first=stat[x].first;
    cout << "\n\t%d\t%d\tE",stat[x].last,stat[i-1].first;
    start=stat[x].first;
    fin=stat[i-1].last;
    break;
    case'*':
    stat[i].first=state++;
    stat[i].last=state++;
    cout << "\n\t%d\t%d\tE",stat[i].first,stat[i-1].first;
    cout << "\n\t%d\t%d\tE",stat[i].first,stat[i].last;
    cout << "\n\t%d\t%d\tE",stat[i-1].last,stat[i-1].first;
    cout << "\n\t%d\t%d\tE",stat[i-1].last,stat[i].last;
    start=stat[i].first;
    fin=stat[i].last;
    break;
    }}
    i++;
    }
    cout << "\n the starting state is %d",start;
    cout << "\n the final state is %d",fin;

    return 0;
}
