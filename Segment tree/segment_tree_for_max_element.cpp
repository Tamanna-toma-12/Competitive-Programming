#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+123;
int a[mx];
int seg[4*mx];
void build(int ind,int low,int high){
if(low==high){
        seg[ind]=a[low];
        return;
}
   int    mid=(low+high)/2;
    build(2*ind+1,low,mid);
    build(2*ind+2,mid+1,high);
    seg[ind]=max(seg[2*ind+1],seg[2*ind+2]);
}

int main()
{
    int n;
    cin>>n;
   // vector<int>v(n);
    for(int i=0;i<n;i++)cin>>a[i];
    build(0,0,n-1);
    for(int i=0;i<n*4;i++)cout<<seg[i]<<endl;
    return 0;
}
