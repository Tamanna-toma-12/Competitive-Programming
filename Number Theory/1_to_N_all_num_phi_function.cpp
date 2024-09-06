#include<bits/stdc++.h>
using namespace std;
int mx=1e7+123;
vector<int>v(mx);
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
}
int main()
{
    phi();
    cout<<v[9]<<endl;
    return 0;
}
