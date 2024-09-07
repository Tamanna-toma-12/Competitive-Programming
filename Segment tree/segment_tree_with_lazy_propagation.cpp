#include<bits/stdc++.h>
using namespace std;
const int mx=2e5+123;
long long a[mx];
long long tree[4*mx];
long long lazy[4*mx];
void build(int index,int start,int ending){
    if(start==ending){
        tree[index]=a[start];
        return;
    }
    int mid=(start+ending)>>1;
    build(2*index+1,start,mid);
    build(2*index+2,mid+1,ending);
    tree[index]=tree[2*index+1]+tree[2*index+2];
}
void update(int index ,int s,int e,int l,int r,long long val){
      if(lazy[index]!=0){
        tree[index]+=((e-s)+1)*lazy[index];
        if(s!=e){
            lazy[2*index+1]+=lazy[index];
            lazy[2*index+2]+=lazy[index];

        }
        lazy[index]=0;
      }
      if(l>e||r<s)return;
      else if(s>=l&&e<=r){
        tree[index]+=((e-s)+1)*val;
        if(e!=s){
            lazy[2*index+1]+=val;
            lazy[2*index+2]+=val;
        }
        return;
      }
      int mid=(e+s)>>1;
      update(2*index+1,s,mid,l,r,val);
      update(2*index+2,mid+1,e,l,r,val);
      tree[index]=tree[2*index+1]+tree[2*index+2];
}
long long querysum(int index,int s,int e,int l){
    if(lazy[index]!=0){
         tree[index]+=((e-s)+1)*lazy[index];
        if(s!=e){
            lazy[2*index+1]+=lazy[index];
            lazy[2*index+2]+=lazy[index];

        }
        lazy[index]=0;
    }
    if(l>e||l<s)return 0;
    if(s==e&&s==l)return tree[index];
    int mid=(s+e)>>1;
    return querysum(2*index+1,s,mid,l)+querysum(2*index+2,mid+1,e,l);

}
int main()
{
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++)cin>>a[i];
    build(0,0,n-1);
    memset(lazy,0,sizeof(lazy));
    while(q--){
        int t;
        cin>>t;
        if(t==2){
            int l;
            cin>>l;
            l--;
            cout<<querysum(0,0,n-1,l)<<endl;
        }
        else{
            int a,b,val;
            cin>>a>>b>>val;
            a--;
            b--;
            update(0,0,n-1,a,b,val);
        }
    }
    return 0;
}
