#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>




using namespace std;
void ZnajdzMaxMin(int a[100][3],int k,int n,int& mi,int& ma){
    mi=2021;
    ma=0;
    for(int i=0;i<n;i++){
        if(a[i][k]>ma) ma=a[i][k];
        if(a[i][k]<mi) mi=a[i][k];
    }
}

void ZliczanieSort(int a[100][3],int q,int n){
    int mi,ma;
    ZnajdzMaxMin(a,q,n,mi,ma);
    int k=ma-mi+1;
    int* counters=new int[k];
    int b[100][3];
    for(int i=0;i<k;i++){
        counters[i]=0;
    }
    for(int i=0;i<n;i++){
        counters[a[i][q]-mi]++;
    }
    for(int i=1;i<k;i++){
        counters[i]=counters[i]+counters[i-1];
        }

    for(int i=n-1;i>=0;i--){
            for(int j=0;j<3;j++){
            b[counters[a[i][q]-mi]-1][j]=a[i][j];}
            counters[a[i][q]-mi]--;

    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=b[i][j];
        }
    }





    delete[] counters;

}




int main () {
    int tests,n;
    cin>>tests;
    string temp;
    int tab[100][3];
    for(int i=0;i<tests;i++){
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>temp;
            istringstream(temp.substr(0,4))>>tab[j][0];
        istringstream(temp.substr(5,2))>>tab[j][1];
        istringstream(temp.substr(8,2))>>tab[j][2];
        }
        ZliczanieSort(tab,2,n);
        ZliczanieSort(tab,1,n);
        ZliczanieSort(tab,0,n);

        cout<<"Test nr "<<i+1<<endl;
          for(int j=0;j<n;j++){
            cout<<tab[j][0]<<'-';
            if(tab[j][1]<10){
                cout<<'0'<<tab[j][1]<<'-';
            }
            else{
                cout<<tab[j][1]<<'-';
            }
            if(tab[j][2]<10){
                cout<<'0'<<tab[j][2]<<endl;
            }
            else{
                cout<<tab[j][2]<<endl;
            }


        }



    }




  return 0;
}
