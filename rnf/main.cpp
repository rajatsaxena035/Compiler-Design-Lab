#include <iostream>

using namespace std;

int main()
{
    int len,i,realen=0,states,inputs,k=0,j=0,q=0,f,z,start=0;
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
    cout << endl << "Number of states = " <<states << endl;
    cout <<  endl << "Number of inputs = " <<inputs << endl;
    string input[inputs];
    j=0;
    for(i=0;i<len;i++)
    {
        if(re[i]=='.')
        {
            start=j;
            k=i-1;
            j=i+1;
            break;
        }
        for(z=start;z<=k;z++)
        {
            input[q]="";
            input[q]+=re[z];
        }
        cout << input[q] << endl;
        q++;
        for(z=j;z<len;z++)
        {
            input[q]="";
            input[q]+=re[z];
        }
        cout << input[q] << endl;
    }
    /*
    for(i=0;i<=q;i++)
    {
        cout << input[i] << endl;
    }
    */
    //cout << input[0] << endl;
    //cout << input[1];
    cout << endl;

    for(i=0;i<inputs;i++)
    {
        cout << "q" << i << "\t" << input[i] << "\t" ;
    }
    cout << "qf";

    cout << endl;

    return 0;
}
