#include<bits/stdc++.h>
using namespace std;
#define  optimize()  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll          long long int
#define  ull         unsigned long long int
#define  pb          push_back
#define  all(v)      v.begin(),v.end()
#define  rall(v)     v.rbegin(),v.rend()
#define  endl        "\n"
#define  lcm(a,b)    a/__gcd(a,b)*b
#define  mod         (ll)998244353
#define  gcd(a,b)    __gcd(a,b)
#define  Max(a,b,c)  max(max(a,b),c)
#define  Min(a,b,c)  min(min(a,b),c)
#define  pii         pair<ll,ll>
#define  S           second
#define  F           first
void answer();
const ll mx=1e9;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int main()
{
    optimize();
     int t=1;
    //cin>>t;
    int tt=t;
     while(t--){
       //  cout<<"Case "<<tt-t<<": ";
        answer();
     }
     return 0;
}
void answer()
{   
    ll n;
    string s;
    cin>>s;
    n=s.size();
    vector<ll>z(n);
    z[0]=0;
    ll l=0,r=0;
    for(int i=1;i<n;i++){
        if(i<r){
            z[i]=min(z[i-l],r-i);
        }
        while(i+z[i]<n&&s[z[i]]==s[i+z[i]]){
            z[i]++;
        }
        if(i+z[i]>r){
            l=i;
            r=i+z[i];
        }

    }
    for(auto u:z)cout<<u<<" ";
    cout<<endl;
}
