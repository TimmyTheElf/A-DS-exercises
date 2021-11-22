#include <iostream>
#include <ctime>

using namespace std;
int NWD1(int a,int b){
    if(a<0) a=-a;
    if(b<0) b=-b;
    if (a==b) return a;
    int x,y,p;
    if(a<b){
        x=a;
        y=b-a;}
    else{
    x=b;
    y=a-b;}
    while(x!=y){
        if(x<y){
            y=y-x;}
        else{p=x;
    x=y;
    y=p-y;}
    }
return x;
}

int NWD2(int a,int b){
    if(a<0) a=-a;
    if(b<0) b=-b;
    if (a==b) return a;
    int x,y,p;
    x=b; y=a%b;
    while(y!=0){
        p=x;
        x=y;
        y=p%y;

    }
return x;
}
int NWD3(int a,int b){
    if(a<0) a=-a;
    if(b<0) b=-b;
    if(a==b) return b;
    if(b==0) return a;
    else return NWD3(b,a%b);
}

int main()
{ int a,b,n;
clock_t start,e,ttest,treal;
cin>>a;
cin>>b;
/*start=clock();
for(int i=0;i<1000000;i++){

}e=clock();
ttest=e-start;*/
start=clock();
for(int i=0;i<1000000;i++){ n=NWD1(a,b);}
e=clock();
cout<<"Wersja 1: NWD1("<<a<<","<<b<<") = "<<n<<", czas obliczen = "<<(e-start)/double(CLK_TCK)/1000000<<" mikrosekund"<<endl;
start=clock();
for(int i=0;i<1000000;i++){ n=NWD2(a,b);}
e=clock();
cout<<"Wersja 2: NWD2("<<a<<","<<b<<") = "<<n<<", czas obliczen = "<<(e-start)/double(CLK_TCK)/1000000<<" mikrosekund"<<endl;
start=clock();
for(int i=0;i<1000000;i++){ n=NWD3(a,b);}
e=clock();
cout<<"Wersja 3: NWD3("<<a<<","<<b<<") = "<<n<<", czas obliczen = "<<(e-start)/double(CLK_TCK)/1000000<<" mikrosekund"<<endl;
    return 0;
}
