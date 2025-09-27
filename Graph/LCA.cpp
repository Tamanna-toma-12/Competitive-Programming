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
#define  gcd(a,b)    __gcd(a,b)
#define  Max(a,b,c)  max(max(a,b),c)
#define  Min(a,b,c)  min(min(a,b),c)
#define  pii         pair<ll,ll>
#define  S           second
#define  F           first
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree< long long, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update >ordered_set;
void answer();
const ll inf=2e18;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
const ll mod=1e9+7;
const ll mx=2e5+123;
ll n,qe;
vector<ll>adj[mx+1];
ll st[mx][100];
ll lev[mx];
ll LCA(ll u,ll v){
    if(lev[u]<lev[v])swap(u,v);
    ll x=n,c=0;
    while(x>0){
        x/=2;
        c++;
    }

    ll d=lev[u]-lev[v];
   // cout<<c<<endl;
    for(int i=c;i>=0;i--){
        if((1<<i)&d){
          //cout<<i<<endl;
          u=st[u][i];
        }
    }
   if(u==v){
      // cout<<u<<endl;
       return u;
   }

   for(int i=c;i>=0;i--){
     if(st[u][i]!=st[v][i]){
        u=st[u][i];
        v=st[v][i];
     }
   }
   //cout<<u<<endl;
   return st[u][0];
}
int main()
{
    optimize();
    int t=1;
    //cin>>t;
    int tt=t;
     while(t--){
        answer();
     }
     return 0;
}
void answer()
{
  ll m,k,x,y,z;
  cin>>n>>qe;
  for(int i=1;i<=n;i++)adj[i].clear();
  for(int i=2;i<=n;i++){
      cin>>x;
      adj[x].pb(i);
      adj[i].pb(x);
  }
  ll p[n+1];
  p[1]=-1;
  queue<ll>q;
  bool vis[n+1];
  memset(vis,0,sizeof(vis));
  vis[1]=1;
  q.push(1);
  lev[1]=1;
  while(!q.empty()){
    ll node=q.front();
    q.pop();
    for(auto u:adj[node]){
      if(!vis[u]){
        vis[u]=1;
        lev[u]=lev[node]+1;
        p[u]=node;
        q.push(u);
      }
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=0;j<100;j++)st[i][j]=-1;
  }
  for(int i=1;i<=n;i++){
    st[i][0]=p[i];
  }
  for(int i=1;(1<<i)<=n;i++){
    y=i-1;
    for(int j=1;j<=n;j++){
         if(st[j][y]==-1||st[st[j][y]][y]==-1){
             st[j][i]=-1;
             continue;
         }
        st[j][i]=st[st[j][y]][y];
    }
  }
  while(qe--){
      ll x,y;
      cin>>x>>y;

      cout<<LCA(x,y)<<endl;

  }
}
