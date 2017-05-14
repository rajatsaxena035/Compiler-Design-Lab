#include <iostream>
#include <string>

using namespace std;

int token(string t)
{
    if(t=="{" || t=="(") return "Left Parenthesis";
    else if(t=="}" || t==")") return "Right Parenthesis";
    else if(t=="=") return "Assignment Operator";
    else if(t=="+")
    else if(t=="-")
    else if(t=="/")
    else if(t=="*")
    else if(t=="%")
    else if(t=="==")
    else if(t=="!=")
    else if(t==">")
    else if(t=="<")
    else if(t==">=")
    else if(t=="<=")
    else if(t==";")
    else
    {

    }
}

int main()
{
    string exp[100];
    int len,i;

    string keywords[]= {"alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand",
      "bitor", "bool", "break", "case", "catch", "char", "char16_t", "char32_t", "class", "compl", "const", "constexpr",
      "const_cast", "continue", "decltype", "default", "delete", "do", "double", "dynamic_cast", "else", "enum",
      "explicit", "export", "extern", "false", "float", "for","friend", "goto", "if", "inline", "int", "long", "mutable",
      "namespace", "new", "noexcept", "not", "not_eq", "nullptr", "operator", "or", "or_eq", "private", "protected public",
      "register", "reinterpret_cast","return","short","signed","sizeof","static","static_assert","static_cast","struct",
      "switch", "template", "this","thread_local","throw","true","try","typedef","typeid","typename","union","unsigned",
      "using","virtual","void", "volatile","wchar_t","while","xor","xor_eq"};

    cout << "Enter the expression : " << endl;
    cin >> exp;
    len = exp.size();
    for(i=0;i<len;i++)
    {
        cout << token(exp[i]);
    }
    return 0;
}
