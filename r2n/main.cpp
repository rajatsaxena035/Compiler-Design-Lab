#include <iostream>

using namespace std;

int main()
{
    int len,i,realen=0,states,inputs,k,j;
    string re;
    cout << "Enter the RE:" << endl;
    cin >> re;
    len=re.size();
    for(i=0;i<len;i++)
    {
        if(re[i]=='.')
        {
            realen++;
        }
    }
    states=realen+2;
    inputs=realen+1;
    //cout << "Number of states = " <<states << endl;
    //cout << "Number of inputs = " <<inputs << endl;
    string input[inputs];
    for(i=0;i<len;i++)
    {
        if(re[i]=='.')
        {
            k=i-1;
            j=i+1;
            break;
        }
    }
    for(i=0;i<=k;i++)
    {
        input[0]+=re[i];
    }
    //cout << input[0];
    for(i=j;i<len;i++)
    {
        input[1]+=re[i];
    }
    //cout << input[0] << endl;
    //cout << input[1];
    cout << endl;
    for(i=0;i<inputs;i++)
    {
        cout << "q" << i << "\t" << input[i] << "\t" ;
    }
    cout << "qf";

/*
    int num=2,i=0;
    for(i=0;i<num;i++)
    {
        states[i]="q";
        states[i]+=states[i]+i;
    }
    cin >> re;
    cout << "q0" << " " << re << " " << "q1";
  */
    return 0;
}
