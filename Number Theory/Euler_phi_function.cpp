#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+123;
bool isprime[mx];
vector<int>prime;
void primegen()
{
    isprime[2]=1;
    for(int i=3;i<=mx;i+=2)isprime[i]=1;
    int sq=sqrt(mx);
    for(int i=3;i<=sq;i+=2){
        if(isprime[i]==1){
            for(int j=i*i;j<=mx;j+=(i+i)){
                isprime[j]=0;
            }
        }
    }
    prime.push_back(2);
    for(int i=3;i<=mx;i+=2){
        if(isprime[i]==1)prime.push_back(i);
    }
}
long long int phi(long long int n){
    if(n==1)return 0;
 long long int ret=n;
 for(auto u:prime){
        if(1LL*u*u>n||n==0)break;
 if(n%u==0){
    ret/=u;
    ret*=(u-1);
    while(n%u==0){
        n/=u;
    }
 }
 }
 if(n>1){
    ret/=n;
    ret*=(n-1);
 }
 return ret;
}
int main()
{
    primegen();

    while(1){
      long long  int n;
        cin>>n;
        if(n==0)break;
        cout<<phi(n)<<endl;
    }
    return 0;
}
