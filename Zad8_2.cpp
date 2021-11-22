#include <iostream>
#include <stack>
#include <string>

using namespace std;
bool check(string c){
    stack<char> stos;
    char x;
    for(int i=0;i<c.length();i++){
        if(c[i]!='(' && c[i]!='[' && c[i]!='{' && c[i]!=')' && c[i]!=']' && c[i]!='}') continue;
         if (c[i]=='(' || c[i]=='[' || c[i]=='{')
        {
            stos.push(c[i]);
            continue;
        }
                if (stos.empty())
            return false;

        switch (c[i]) {
        case ')':
            x = stos.top();
            stos.pop();
            if (x == '{' || x == '[') return false;
            break;

        case '}':
            x = stos.top();
            stos.pop();
            if (x == '(' || x == '[')
                return false;
            break;

        case ']':
            x = stos.top();
            stos.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
    }
    return (stos.empty());



}

int main()
{   int tests;
    cin>>tests;
    cin.sync();
    cin.clear();
    for(int i=0;i<tests;i++){
        char* C=new char[256];
        cin.getline(C,256,'\n');
        if(check(C)) cout<<"TAK"<<endl;
        else cout<<"NIE"<<endl;
        delete [] C;

    }

    return 0;
}
