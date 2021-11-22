#include <iostream>

using namespace std;
int counter=0;
void Swap(int *b,int *c){
    int q=*b;
    *b=*c;
    *c=q;
}
 void ShowArray(int A[],int n){
     for(int i=0;i<n;i++){
        cout<<A[i]<<' ';
     }
}
 void ScanArray(int A[],int n){
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
}
 int Partition(int A[],int l, int r){
    int q=A[l+(r-l)/2],i=l-1,j=l;
    Swap(&A[l+(r-l)/2],&A[r]);
    while(j<r){
        if(A[j]<q){
                i++;
            Swap(&A[i],&A[j]);

        }
    j++;
    }
    Swap(&A[i+1],&A[r]);
    return i+1;
}
 void QuickSort(int A[],int l,int r){
     counter++;
     int q;
     if(l<r){
        q=Partition(A,l,r);
        QuickSort(A,l,q-1);
        QuickSort(A,q+1,r);
     }
 }

int main()
{   int n,tests;
    cin>>tests;
    for(int i=0;i<tests;i++){
    cin>>n;
    int*tab=new int[n];
    ScanArray(tab,n);
    QuickSort(tab,0,n-1);
    ShowArray(tab,n);
    cout<<"\nLiczba wywolan funkcji QuickSort = "<<counter;
    delete [] tab;
    counter=0;
    }

    return 0;
}
