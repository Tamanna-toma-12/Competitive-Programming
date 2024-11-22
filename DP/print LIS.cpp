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
/*using namespace __gnu_pbds;
//typedef tree< long long, null_type, less<long long>, rb_tree_tag,tree_order_statistics_node_update >ordered_set;//for set
///less er jaigay greater dile boro theke choto set
typedef tree<long long,null_type,less_equal<long long>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;//for multiset
///less er jaigay greater dile boro theke choto multiset
///cout<<x(name of set or multiset).order_of_key(-5(parameter))<<endl;//number of items in a set that are stricly smaller than
///our item*/
const ll mx=2e5+123;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
 map<string,vector<string>>adj;
    vector<pair<string,string>>ans;
     map<string,string>parent;
int main()
{
    optimize();
    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)cin>>a[i];
	    vector<int>dp(n,1);
	    for(int i=1;i<n;i++){
	        int c=0;
	        for(int j=0;j<i;j++){
	            if(a[j]<a[i]){
	                c=max(c,dp[j]);
	            }
	        }
	        dp[i]+=c;
	    }
	    int mx=0,m=0;
	    for(int i=0;i<n;i++){
	        if(dp[i]>=mx){
	            if(dp[i]>mx){
	                mx=dp[i];
	                m=a[i];
	            }
	            else{
	                if(a[i]>m){
	                    m=a[i];
	                }
	            }
	        }
	    }
	    vector<int>LIS;
	    LIS.push_back(m);
	   // cout<<m<<" "<<mx<<endl;
	   // mx--;
	    for(int i=n-1;i>=0;i--){
	        int ans=0;
	       // cout<<a[i]<<" "<<m<<endl;
	        if(a[i]==m){
	            mx--;
	            for(int j=0;j<i;j++){
	                if(dp[j]==mx&&a[j]<m){
	                    LIS.push_back(a[j]);
	                    m=a[j];
	                    break;
	                }
	            }
	        }
	    }
	    int sum=0;
	    //cout<<mx<<endl;
	    reverse(LIS.begin(),LIS.end());
	    for(auto u:LIS)cout<<u<<" ";
	    cout<<endl;
    return 0;
}
