#include<bits/stdc++.h>
using namespace std;
const int mx=1e6+123;
bool isprime[mx];
vector<int>prime;
void primegen()
{
    memset(isprime,1,sizeof(isprime));
    for(int i=2;i<=sqrt(mx);i++){
        if(isprime[i]==1){
            for(int j=i*2;j<=mx;j+=i){
                isprime[j]=0;
            }
        }
    }
    for(int i=3;i<=mx;i++){
        if(isprime[i]==1)prime.push_back(i);
    }
}
int main()
{
    primegen();
    int n;
    while(1){
        cin>>n;
        int a=0,b=0;
        if(n==0)break;
        for(int i=0;i<n;i++){
            if(prime[i]>n)break;
            int x=n-prime[i];
            if(isprime[x]==1){
                a=prime[i];
                b=x;
                break;
            }
        }
        if(a==0)cout<<"Goldbach's conjecture is wrong."<<endl;
        else cout<<n<<" = "<<a<<" + "<<b<<endl;
    }
    return 0;
}
