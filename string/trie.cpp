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
#define  mod         (ll)1e9+7;
#define  gcd(a,b)    __gcd(a,b)
#define  Max(a,b,c)  max(max(a,b),c)
#define  Min(a,b,c)  min(min(a,b),c)
#define  pii         pair<int,int>
#define  S           second
#define  F           first
#define  inf         1e16
void answer();
const ll mx=2e6+123;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
class trieNode{
  public:
   char data;
   trieNode* child[30];
   ll c;
  // bool isTerminal;
   trieNode(char ch){
    data=ch;
    for(int i=0;i<30;i++){
      child[i]=NULL;
    }
    c=0;
   // isTerminal=false;
   }
};
class trie{
  public:
  trieNode* root;
  trie(){
    root=new trieNode('\0');
  }
  void insertWord(trieNode* root,string word){
         trieNode* cur=root;
         for(auto ch:word){
          if(cur->child[ch-'a']==NULL){
             cur->child[ch-'a']=new trieNode(ch);
          }
          cur=cur->child[ch-'a'];
          cur->c++;
         }
  }
  void insertion(string word)
  {
   return insertWord(root,word);
  }
  ll searchTrie(trieNode* root,string word){
    trieNode* cur=root;
    for(auto ch:word){
      if(cur->child[ch-'a']==NULL)return 0;
      cur=cur->child[ch-'a'];
    }
    return cur->c;
  }
  ll search(string word){
    return searchTrie(root,word);
  }
};
int main()
{
    optimize();
     int tt=1;
  //  cin>>tt;
    ll tc=tt;
     while(tt--){
   //cout<<"Case "<<tc-tt<<": ";
        answer();
     }
     return 0;
}
void answer(){
    trie* t;
    t=new trie();
    ll n,k;
    cin>>n>>k;
    ////vector<string>v;
    while(n--){
    string(s);
    cin>>s;
   // reverse(all(s));
//    v.pb(s);
    t->insertion(s);
    }
   ll ans=0;
   while(k--){
        string s;
   cin>>s;
    cout<<t->search(s)<<endl;
   }
   //cout<<ans<<endl;

 }

