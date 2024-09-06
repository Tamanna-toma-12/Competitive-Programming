#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
const int mx=32e4+123;
bitset<mx> isprime;
vector<int>prime;
void primegen()
{
    //mx+=100;
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
 int NOD (long long int n){
    int ret=1;
for(auto p:prime){
    if(1LL*p*p>n)break;
  if(n%p==0){
        int c=1;
    while(n%p==0){
        n/=p;
        c++;
    }
    ret*=c;
  }
}
if(n>1)ret*=2;
return ret;
}
int main()
{
    optimize();
    primegen();
    cout<<NOD(6)<<endl;
    return 0;
}
