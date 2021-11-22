#include <iostream>

using namespace std;
int check(int tab[],int c){
    int sum=0;
    for(int i=0;i<c-1;i++){
        sum+=tab[i];
    }
    return sum;
}

int main()
{   int x,s=1,c=0,sum;
    while(true){
        cin>>x;
        int *tab=new int[x];
        if(x==0) break;

    while(s!=x+1){
        if(x%s==0) {
            tab[c]=s;
            c++;
        }
        s++;
    }
    sum=check(tab,c);
    if(sum==x) {cout<<"TAK"<<endl;}
    else{cout<<"NIE"<<endl;}

    sum=0;c=0;s=1;
    delete [] tab;
    }
    return 0;
}
