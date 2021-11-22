#include <iostream>

using namespace std;
void ScanArray(int *A,int n){
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
 }
 void ShowArray(int *A,int n){
     for(int i=0;i<n-1;i++){
        cout<<A[i]<<' ';
     }
     cout<<A[n-1]<<endl;}
void ZnajdzMaxMin(int *a,int n,int& mi,int& ma){
    mi=101;
    ma=-1;
    for(int i=0;i<n;i++){
        if(a[i]>ma) ma=a[i];
        if(a[i]<mi) mi=a[i];
    }
}

void ZliczanieSort(int *a,int n){
    int mi,ma;
    ZnajdzMaxMin(a,n,mi,ma);
    int k=ma-mi+1;
    int* counters=new int[k];
    int* b=new int[n];
    for(int i=0;i<k;i++){
        counters[i]=0;
    }
    for(int i=0;i<n;i++){
        counters[a[i]-mi]++;
    }
    for(int i=1;i<k;i++){
        counters[i]=counters[i]+counters[i-1];
        }
    for(int i=n-1;i>=0;i--){
            b[counters[a[i]-mi]-1]=a[i];
            counters[a[i]-mi]--;

    }
    ShowArray(b,n);



    delete[] counters;
    delete[] b;
}

int main()
{   int tests,n;

    cin>>tests;
    for(int i=0;i<tests;i++){
        cin>>n;
        int *tab=new int[n];
        ScanArray(tab,n);
        ZliczanieSort(tab,n);
        delete [] tab;
        }


    return 0;
}
