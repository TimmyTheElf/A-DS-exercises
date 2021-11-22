#include <iostream>

using namespace std;
int counter=0;
 void Merge(int A[],int l,int q, int r){
     int b=q-l+1,c=r-q;
     int *B=new int[b];
     int *C=new int[c];
     for(int i=0;i<b;i++){
        B[i]=A[l+i];
    }
     for(int i=0;i<c;i++){
        C[i]=A[q+1+i];
    }
     int i=0,j=0,k=l;
     while (i < b && j < c){
        if (B[i] <= C[j]){
            A[k] = B[i];
            i++;
        }
        else{
            A[k] = C[j];
            j++;
        }
    k++;
    }
     while(i<b){
        A[k]=B[i];
        i++; k++;
     }
     while(j<c){
        A[k]=C[j];
        j++; k++;
     }
}

 void MergeSort(int A[], int l, int r){
     counter++;
     int q;
 if(l<r){
    q=(l+r)/2;
    MergeSort(A,l,q);
    MergeSort(A,q+1,r);
    Merge(A,l,q,r);
 }
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


int main()
{   int n,tests;
    cin>>tests;
    for(int i=0;i<tests;i++){
    cin>>n;
    int*tab=new int[n];
    ScanArray(tab,n);
    MergeSort(tab,0,n-1);
    ShowArray(tab,n);
    cout<<"\nLiczba wywolan funkcji ScalanieSort = "<<counter;
    delete [] tab;
    counter=0;
    }


    return 0;
}
