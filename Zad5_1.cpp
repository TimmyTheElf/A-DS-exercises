#include <iostream>

using namespace std;
 void ScanArray(int A[],int n){
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
 }
void Kadane(int tab[],int s){
int max_total=INT_MIN, max_local=0,p=0,k=0,m=0;

for(int i=0;i<s;i++){
    max_local=max_local+tab[i];
    if(max_total<max_local)
        {
        max_total=max_local;
        p=m;
        k=i;
        }
    if(max_local<0){
        max_local=0;
        m=i+1;
    }
}
cout<<max_total<<' '<<p+1<<' '<<k+1;
}
bool checkifnegative(int tab[],int s){
    int negatives=0;
    for(int i=0;i<s;i++){
        if(tab[i]<0) negatives++;
    }
    if(negatives==s) return true;
    return false;

}

int main()
{   int t,s;
    cin>>t;
    for(int i=0;i<t;i++){
    cin>>s;
    int *tab=new int[s];
    ScanArray(tab,s);
    if(checkifnegative(tab,s)){
        cout<<"0 0 0";
    }else{
    Kadane(tab,s);}
    delete [] tab;
    }


    return 0;
}
