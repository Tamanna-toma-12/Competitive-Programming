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
const ll mx=1e5+123;

struct node {
    ll ind=-1;
    ll cnt;
    node *next[2];
    node () {
        cnt = 0;
        for (int i = 0; i < 2; i++) next[i] = NULL;
    }
};

node *root;

string bin(ll n) {
    string ans = "";
    for (int i = 31; i >= 0; i--) {
        ans += ((n >> i) & 1) ? '1' : '0';
    }
    return ans;
}

void insert(string s,ll in) {
    node *cur = root;
    cur->ind=in;
    for (int i = 0; i < s.size(); i++) {
        int id = s[i] - '0';
        if (cur->next[id] == NULL) {
        cur->next[id] = new node();
        }
        cur = cur->next[id];
        cur->ind=in;
        cur->cnt++;
    }
}
void erase(string s) {
    node *cur = root;
    for (int i = 0; i < s.size(); i++) {
        int id = s[i] - '0';
        node *nxt = cur->next[id];
        if (!nxt) return;
        nxt->cnt--;
        if (nxt->cnt == 0) {
            delete nxt;
            cur->next[id] = NULL;
            return;
        }
        cur = nxt;
    }
}

ll search(string s,ll l) {
    ll ans = 0;
    node *cur = root;
    for (int i = 0; i < 32; i++) {
        int bit = s[i] - '0', need = 1 - bit;
        if (cur->next[need]&&cur->next[need]->ind>=l) {
            ans |= (1LL << (31 - i));
            cur = cur->next[need];
        }
        else cur = cur->next[bit];

    }
    return ans;
}
void del(node* cur) {
    for (int i = 0; i < 2; i++)
    if (cur->next[i]) del(cur->next[i]);
    delete (cur);
}
int main()
{
    optimize();
    int t=1;
    cin>>t;
    int tt=t;

    while(t--){
        answer();
     }
     return 0;
}

void answer()
{
  ll n,m,k,x,y;

  root=new node();

  cin>>n>>m;

  vector<ll>v(n);
  ll ans=n+1;
  for(int i=0;i<n;i++){
     cin>>v[i];
     if(ans==2)continue;
     insert(bin(v[i]),i);
     ll l=0,r=i;
     x=-1;
     while(l<=r){
          ll mid=(l+r)/2;
        //  cout<<mid<<endl;
          ll mx=search(bin(v[i]),mid);
          if(mx>=m){
               x=mid;
               l=mid+1;
          }
         else r=mid-1;
     }
     if(x!=-1)ans=min(ans,i-x+1);
  }
  if(m==0)ans=1;
  if(ans==n+1)ans=-1;

  cout<<ans<<endl;

}
