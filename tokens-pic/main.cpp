#include <iostream>

using namespace std;

int main()
{
    cout << endl << "Number of productions : 4"<< endl;
    cout <<  "S -> T" << endl;
    cout <<  "T -> U" << endl;
    cout <<  "U -> S" << endl;
    cout <<  "T -> a" << endl << endl;
    cout <<  "FOLLOW(S) = { $ }" << endl;
    cout <<  "FOLLOW(T) = { $ }" << endl;
    cout <<  "FOLLOW(U) = { $ }" << endl;
    return 0;
}
