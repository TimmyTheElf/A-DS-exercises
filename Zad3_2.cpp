#include <iostream>

using namespace std;
void func1(int n){
if(n<10){
    cout<<n<<' ';
    return ;
}
else{
    cout<<n%10<<' ';
    func1(n/10);
}
}
void func2(int n){
if(n<10){
    cout<<n<<' ';
    return ;
}
else{
    func2(n/10);
    cout<<n%10<<' ';

}
}

int main()
{
    int n;
    while(true)
    {
        cin>>n;
        if(n==0) break;
        func1(n);
        cout<<"# ";
        func2(n);

    }
return 0;
}
