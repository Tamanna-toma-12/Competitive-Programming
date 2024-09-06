#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+123;
bitset<mx>isprime;
vector<int>prime;
void primegen(){
  isprime[2]=1;
  for(int i=3;i<=mx;i+=3)isprime[i]=1;
  for(int i=3;i<=sqrt(mx);i+=2){
    if(isprime[i]==1){
        for(int j=i*i;j<=mx;j+=(i+i)){
          isprime[j]=0;
        }
    }
  }
  prime.push_back(2);
  for(int i=3;i<=mx;i+=2){
    if(isprime[i]==1){
        prime.push_back(i);
    }
  }
}
 unsigned long long SOD(long long  n){
    long long x=1;
    for(int i=0; ;i++){
        if(1LL*prime[i]*prime[i]>n)break;
      long long   int y=0,c=0;
        while(n%prime[i]==0){
            y+=pow(prime[i],c);
            n/=prime[i];
            c++;
        }
        y+=pow(prime[i],c);
        x*=y;
    }
    if(n>1)x*=(n+1);
    return x;

}
int main()
{
    primegen();
    int t;
    cin>>t;
    while(t--){
    long long  n;
    cin>>n;
    cout<<SOD(n)<<endl;
    }
    return 0;
}
