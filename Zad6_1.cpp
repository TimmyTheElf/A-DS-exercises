#include <iostream>

using namespace std;

int main()
{   int t,n;
    int A[101];
    int B[101];
    int C[101];
    int D[101];
    int temp,a,s;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>A[j];
            cin>>B[j];
            C[j]=j+1;
        }
    for(int j=0;j<n;j++){
        for(int k=j+1;k<n;k++){
            if((B[k]<B[j])||(B[k]==B[j]&&A[j]>A[k])){
                temp=A[j];
                A[j]=A[k];
                A[k]=temp;
                temp=B[j];
                B[j]=B[k];
                B[k]=temp;
                temp=C[j];
                C[j]=C[k];
                C[k]=temp;
            }
        }
    }
     a=1;s=0;
     D[0]=C[0];
    for(int j=1;j<n;j++){
         if(A[j]>=B[s]){
            D[a]=C[j];
            a++;
            s=j;
         }
    }
    for(int j=0;j<a;j++){
        if(j==a-1)
        cout<<D[j]<<endl;
        else cout<<D[j]<<' ';
    }


    }

    return 0;
}
