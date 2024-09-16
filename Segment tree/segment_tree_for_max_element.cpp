#include<bits/stdc++.h>
using namespace std;
#define  optimize()  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
const int mx=1e5+123;
int a[mx];
long long tree[4*mx];
void build(int node,int st,int en)
{
    if(st==en){
            tree[node]=a[st];
            return;
    }
    int mid=(st+en)>>1;
    build(2*node+1,st,mid);
    build(2*node+2,mid+1,en);
    tree[node]=max(tree[2*node+1],tree[2*node+2]);
}
long long query(int node,int st,int en,int l,int r){
  if(st>r||en<l)return 0;
  if(st>=l&&en<=r)return tree[node];
int  mid=(st+en)/2;
  long long q1,q2;
  q1=query(2*node+1,st,mid,l,r);
  q2=query(2*node+2,mid+1,en,l,r);
  return max(q1,q2);
}
void update(int node,int st,int en,int value,int index){
    if(st>index||en<index)return;
    if(st>=index&&en<=index){
            tree[node]=value;
            return;
    }
   int mid=(st+en)/2;
   update(2*node+1,st,mid,value,index);
   update(2*node+2,mid+1,en,value,index);
   tree[node]=max(tree[2*node+1],tree[2*node+2]);

}
int main()
{
     optimize();
     int tt=1;
   cin>>tt;
    ll tc=tt;
     while(tt--){
   cout<<"Case "<<tc-tt<<": "<<endl;
   ll n,q;
   cin>>n>>q;
   for(int i=0;i<n;i++)cin>>a[i];
   build(0,0,n-1);
   while(q--){
    ll l,r;
    cin>>l>>r;
    l--;
    r--;
    cout<<query(0,0,n-1,l,r)<<endl;
   }
     }
     return 0;
}
