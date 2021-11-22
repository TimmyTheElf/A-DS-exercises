#include <iostream>

using namespace std;
int pot2(int x,int n){
    if(n==0) return 1;
    else return x*pot2(x,n-1);
}
float wielomian(int n, int x, int a[]){
    float wynik=0;
    for(int i=0;i<n+1;i++){
        wynik+=a[i]*pot2(x,i);
    }
    return wynik;
}
int zliczaj(int n){
int z=0;
for(int i=1;i<n+1;i++){
    z+=i;}
    return z;
}
float wielomian2(int n,int x,int a[]){
    float wynik=0;
    for(int i=n;i>0;i--){
        wynik=x*(wynik+a[i]);
    }
    wynik+=a[0];
return wynik;
}

int main()
{   int n,x;
    cin>>n;
    cin>>x;
    int *a=new int[n+1];
    for(int i=0;i<n+1;i++){
        cin>>a[i];
    }
    cout<<"Wersja 1: W(x) = "<<wielomian(n,x,a)<<", liczba mnozen = "<<zliczaj(n)<<endl;
    cout<<"Wersja 2: W(x) = "<<wielomian(n,x,a)<<", liczba mnozen = "<<n<<endl;
    delete [] a;
    return 0;
}
