#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int mx=1e5+123;
bool isprime[mx];
vector<int>prime;
void primegen()
{
   for(int i=3;i<mx;i+=2)isprime[i]=1;
   for(int i=3;i<=sqrt(mx);i+=2){
    if(isprime[i]==1){
        for(int j=i*i;j<mx;j+=(i+i)){
            isprime[j]=0;
        }
    }
   }
   prime.push_back(2);
    for(int i=3;i<mx;i+=2){
            if(isprime[i]==1)prime.push_back(i);
    }
}

int main()
{
    optimize();
    primegen();
    //cout<<prime.size()<<endl;
    for(int i=0;i<prime.size();i+=100){
        if(prime[i]<lim) cout<<prime[i]<<endl;
    }
    return 0;
}
