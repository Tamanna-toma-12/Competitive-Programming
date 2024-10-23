#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll  long long
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define  endl "\n"
#include<ext/pb_ds/assoc_container.hpp>
#define lcm(a,b) a/__gcd(a,b)*b
using namespace __gnu_pbds;
typedef tree< long long, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update >ordered_set;//for set
//less er jaigay greater dile boro theke choto set
//typedef tree<long long,null_type,less_equal<long long>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;//for multiset
//less er jaigay greater dile boro theke choto multiset
///cout<<x(name of set or multiset).order_of_key(-5(parameter))<<endl;//number of items in a set that are stricly smaller than
///our item
///cout<<x(name of set or multiset).find_by_order(1(parameter))<<endl;//find the item in index 1
const ll mx=2e5+123;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int main()
{
    optimize();
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        cout<<"Case "<<tc<<": ";
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        ordered_set st;
        for(int i=1;i<=n;i++)st.insert(i);
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            int j=i;
           // j--;
            j-=v[i];
          //  cout<<j<<endl;
            int x=*st.find_by_order(j);
            ans[i]=x;
            st.erase(st.find_by_order(st.order_of_key(x)));
            
        }
         cout<<ans[0]<<endl;
    }
   
    return 0;
}
