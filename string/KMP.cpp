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
     while(t--){
        answer();
     }
     return 0;
}
void answer()
{
    string text;
    getline(cin,text);
    string pattern;
    getline(cin,pattern);
   // cout<<s<<endl;
    ll n=pattern.size();
    vector<ll>lcsp(n);
    lcsp[0]=0;
    int j=0;
    for(int i=1;i<n;i++){
        while(j>0&&pattern[j]!=pattern[i]){
            j=lcsp[j-1];
        }
        if(pattern[i]==pattern[j])j++;
        lcsp[i]=j;
    }
  vector<ll>ans;
  j=0;
  for(int i=0;i<text.size();i++){
    if(text[i]==pattern[j])j++;
    else{
      if(j>0)  j=lcsp[j-1];
    }
    if(j==n){
           // cout<<i<<endl;
        ans.pb(((i+1)-n)+1);
        j=lcsp[j-1];
    }
  }
  if(ans.empty())ans.pb(-1);
  for(auto u:ans)cout<<u<<" ";
  cout<<endl;
}

