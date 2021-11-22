#include <iostream>
#include <ctime>
using namespace std;
int pot1(int x,int n){
    if(n==0) return 1;
    int p=x;
    for(int i=1;i<n;i++){
            p*=x;}
    return p;
}

int pot2(int x,int n){
    if(n==0) return 1;
    else return x*pot2(x,n-1);
}

int pot3(int x,int n){
    if(n==0) return 1;
    if(n%2==0) return pot3(x,n/2)*pot3(x,n/2);
    if(n%2==1) return x*pot3(x,(n-1)/2)*pot3(x,(n-1)/2);
}
int pot4(int x,int n){
    int p=1;
    while(n!=0){
        if(n%2==0){
            x*=x;
        }
        if(n%2==1){
            p*=x;
            x*=x;
        }
        n=n/2;
    }
return p;
}
int main()
{
int x,n,p;
clock_t start,e,ttest;
cin>>x;
cin>>n;
start=clock();
for(int i=0;i<1000000;i++){

}e=clock();
ttest=e-start;
start=clock();
for(int i=0;i<1000000;i++){
    p=pot1(x,n);
}e=clock();
cout<<"Wersja 1: "<<x<<"^"<<n<<" = "<<p<<", czas obliczen = "<<(e-start)/double(CLK_TCK)/1000000/ttest<<" mikrosekund"<<endl;
start=clock();
for(int i=0;i<1000000;i++){
    p=pot2(x,n);
}e=clock();
cout<<"Wersja 2: "<<x<<"^"<<n<<" = "<<p<<", czas obliczen = "<<(e-start)/double(CLK_TCK)/1000000/ttest<<" mikrosekund"<<endl;
start=clock();
for(int i=0;i<1000000;i++){
    p=pot3(x,n);
}e=clock();
cout<<"Wersja 3: "<<x<<"^"<<n<<" = "<<p<<", czas obliczen = "<<(e-start)/double(CLK_TCK)/1000000/ttest<<" mikrosekund"<<endl;
start=clock();
for(int i=0;i<1000000;i++){
    p=pot4(x,n);
}e=clock();
cout<<"Wersja 4: "<<x<<"^"<<n<<" = "<<p<<", czas obliczen = "<<(e-start)/double(CLK_TCK)/1000000/ttest<<" mikrosekund"<<endl;
    return 0;
}
