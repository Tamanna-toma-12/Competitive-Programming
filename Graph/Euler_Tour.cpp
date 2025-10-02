#include<bits/stdc++.h>
using namespace std;
#define  optimize()  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll          long long int
#define  ull         unsigned long long int
#define  pb          push_back
#define  all(v)      v.begin(),v.end()
#define  rall(v)     v.rbegin(),v.rend()
//#define  endl        "\n"
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
vector<ll>adj[mx];
ll st[mx],en[mx];
bool vis[mx];
ll t;
ll a[mx];
long long tree[4*mx];
void dfs(ll u){
   vis[u]=1;
   st[u]=t++;
   //cout<<u<<endl;
   for(auto v:adj[u]){
      if(vis[v]==0){
         dfs(v); 
      }
   }

   en[u]=t-1;
}
void build(int node,int st,int en)
{
    if(st==en){
            tree[node]=a[st];
            return;
    }
    int mid=(st+en)>>1;
    build(2*node+1,st,mid);
    build(2*node+2,mid+1,en);
    tree[node]=tree[2*node+1]+tree[2*node+2];
}
long long query(int node,int st,int en,int l,int r){
  if(st>r||en<l)return 0;
  if(st>=l&&en<=r)return tree[node];
int  mid=(st+en)/2;
  long long q1,q2;
  q1=query(2*node+1,st,mid,l,r);
  q2=query(2*node+2,mid+1,en,l,r);
  return q1+q2;
}
void update(int node,int st,int en,ll value,int index){
    if(st>index||en<index)return;
    if(st>=index&&en<=index){
            tree[node]=value;
            return;
    }
   int mid=(st+en)/2;
   update(2*node+1,st,mid,value,index);
   update(2*node+2,mid+1,en,value,index);
   tree[node]=tree[2*node+1]+tree[2*node+2];

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
  ll n,m,k,x,y,q;
   
  cin>>n>>q;
  vector<ll>v(n);

  for(int i=0;i<n;i++)cin>>v[i];
  for(int i=1;i<=n;i++){
   adj[i].clear();
   vis[i]=0;
  }

  for(int i=1;i<n;i++){
     cin>>x>>y;
     adj[x].pb(y);
     adj[y].pb(x);
  }
  
  t=0;
  dfs(1);
  for(int i=1;i<=n;i++){
   a[st[i]]=v[i-1];
  }
 // cout<<st[4]<<" "<<en[4]<<endl;
  cout<<endl;
  build(0,0,n-1);

  while(q--){
       ll t;
       cin>>t;
       if(t==1){
         cin>>x>>y;
         x=st[x];
         update(0,0,n-1,y,x);
       }
      else{
         cin>>x;
         y=en[x];
         x=st[x];
       //  cout<<x<<" "<<y<<endl;
         cout<<query(0,0,n-1,x,y)<<endl;
      }
  }
 
}
