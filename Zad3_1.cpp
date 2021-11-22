#include <iostream>

using namespace std;
void prime(int n){
    while(n%2==0)
    {
        cout<<2<<' ';
        n=n/2;
    }
     for (int i = 3; i <= n/2; i = i + 2)
    {

        while (n % i == 0)
        {
            cout << i <<' ';
            n = n/i;
        }
    }
    if(n>2) cout<<n<<' ';

}


int main()
{   int n;
    while(true)
    {
        cin>>n;
        if(n==0) break;
        prime(n);
    }

    return 0;
}
