#include <iostream>

using namespace std;
void NWP(char u[], char v[],int n,int m){
    int L[n+1][m+1];
    int P[n+1][m+1];
    for(int i=0;i<=n;i++){
        L[i][0]=0;
    }
    for(int i=0;i<=m;i++){
        L[0][i]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(u[i-1]==v[j-1]){
                L[i][j]=L[i-1][j-1]+1;
                P[i][j]=1;
            }
            else if(L[i-1][j] > L[i][j-1]){
                 L[i][j] = L[i-1][j]; P[i][j] = 2;
            }
            else{
                 L[i][j] = L[i][j-1]; P[i][j] = 3;
            }

        }
    }

    int k=L[n][m],i=n,j=m;
    char z[k+1];

    while(i>0&&j>0){
        if(P[i][j]==1){
            z[k-1]=u[i-1];k--;i--;j--;
        }
        if(P[i][j]==2) i--;
        if(P[i][j]==3) j--;    }
        for(int i=0;i<L[n][m];i++){
            cout<<z[i];
        }



}



int main()
{   int t,k=0,m=0;
    char A[100],B[100];
    cin>>t;
    for(int i=0;i<t;i++){
        do{
        cin>>A[k];
        k++;
        }while(A[k-1]!='.');

        do{
        cin>>B[m];
        m++;
        }while(B[m-1]!='.');

    NWP(A,B,k-1,m-1);
    cout<<endl;
    k=0;
    m=0;

    }


    return 0;
}
