#include <iostream>

using namespace std;

int main()
{
    int nfa_states,i,len,j,k=0,flaga=0,flagb=0;
    string temp;

    cout << "Enter the number of states in NFA: ";
    cin >> nfa_states;

    string dfa_states[nfa_states];

    struct{
        char state;
        string zero;
        string one;
    }nfa[nfa_states],dfa[nfa_states];

    cout << endl << "Enter the transition table of NFA: " << endl << endl;
    cout << "q 0 1\n-------------\n";
    for(i=0;i<nfa_states;i++)
    {
        cin >> nfa[i].state;
        cin >> nfa[i].zero;
        cin >> nfa[i].one;
        cout << "\n";
    }

    dfa_states[k]=nfa[0].state;
    //cout << dfa_states[0] << endl;

    for(i=0;i<=k;i++)
    {
        //cout << "Loop: " << i << endl;

        len = dfa_states[i].length();
        //cout << len << endl;

        temp=dfa_states[i];
        //cout << temp << endl;

        for(j=0;j<1;j++)
        {
            //cout << temp[j]-97 << endl;
            //cout << "One"<< endl;
            dfa[i].zero += nfa[temp[j]-97].zero;
            //cout << "2"<< endl;
            dfa[i].one += nfa[temp[j]-97].one;
        }
        //cout << "3"<< endl;
        for(j=0;j<=k;j++)
        {
            if(dfa[i].zero == dfa_states[j])
            {
                flaga=1;
            }
        }
        //cout << "4"<< endl;
        if(flaga==0)
        {
            k++;
            dfa_states[k]=dfa[i].zero;
        }
        flaga=0;
        //cout << "5"<< endl;
        for(j=0;j<=k;j++)
        {
            if(dfa[i].one == dfa_states[j])
            {
                flaga=1;
            }
        }
        //cout << "6"<< endl;
        if(flaga==0)
        {
            k++;
            dfa_states[k]=dfa[i].one;
            flaga=0;
        }
        //cout << "7"<< endl;
        flaga=0;
        //cout << "k: " << k << endl;
    }
    //cout << "k = " << k << endl;
/*
    cout << dfa[0].zero << endl;
    cout << dfa[0].one << endl;

    cout << dfa[1].zero << endl;
    cout << dfa[1].one << endl;
*/
    cout << "DFA transition table: " << endl << endl;
    cout << "q 0 1\n-------------\n";
    for(i=0;i<=k;i++)
    {
        cout << dfa_states[i] << " ";
        cout << dfa[i].zero << " ";
        cout << dfa[i].one;
        cout << "\n";
    }
    //testing
    return 0;
}
