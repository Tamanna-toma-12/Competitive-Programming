#include<bits/stdc++.h>
using namespace std;
const int mx=3e3+123;
vector<int> v[mx];
//const int MX=1e8+123;
bitset <mx>isprime;
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
int main()
{
    primegen();
    for(auto u:prime){
        for(int j=u;j<=mx;j+=u){
            v[j].push_back(u);
        }
    }
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(v[i].size()==2){
                ans++;
                cout<<i<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}
