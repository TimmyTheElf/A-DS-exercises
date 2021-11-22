#include <iostream>
#include <vector>

using namespace std;
vector<int> Find(int A[],int B[],int n){
int i=0;
vector<int> chosen;
chosen.push_back(0);
for(int j=1;j<n;j++){
    if(A[j]>=B[i]){
        chosen.push_back(j);
        i=j;
    }
}
return chosen;
}

int GRS(int A[],int B[],int n){
int res=0;
vector<int> all;
for(int i=0;i<n;i++){
    all.push_back(i);
}
while(!all.empty()){
    res++;
    int C[all.size()],D[all.size()];
    for(int i=0;i<all.size();i++){
        C[i]=A[all[i]];
        D[i]=B[all[i]];
    }
    vector<int> erased=Find(C,D,all.size());
    for(int i=0;i<erased.size();i++){
        all.erase(all.begin()+erased[i]-i);
    }
}
return res;
}

void Sort(int A[],int B[],int n){
int temp;
for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
        if(A[j]>A[j+1]){
            temp=A[j];
            A[j]=A[j+1];
            A[j+1]=temp;
            temp=B[j];
            B[j]=B[j+1];
            B[j+1]=temp;
        }
    }

}
}

int main()
{
int t,n;
int A[101];
int B[101];
cin>>t;
for(int k=0;k<t;k++){
    cin>>n;
    for(int j=0;j<n;j++){
        cin>>A[j];
        cin>>B[j];
    }
    Sort(A,B,n);
    cout<<GRS(A,B,n)<<endl;


    }
    return 0;
}
