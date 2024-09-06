#include<bits/stdc++.h>
using namespace std;
int mx=1e6+123;
vector<long long>v(mx);
vector<long long>r(mx);
void phi()
{
    for(int i=1;i<=mx;i++)v[i]=i;
    for(int i=2;i<=mx;i++){
        if(v[i]==i){
            for(int j=i;j<=mx;j+=i){
                v[j]*=(i-1);
                v[j]/=i;
            }
        }
    }
    for(int i=1;i<=mx;i++){
        for(int j=i;j<=mx;j+=i){
            r[j]+=v[i]*i;
        }
    }

}

int main()
{
    phi();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long ans=r[n]+1;
        ans*=n;
        ans/=2;
        cout<<ans<<endl;

    }
    return 0;
}

