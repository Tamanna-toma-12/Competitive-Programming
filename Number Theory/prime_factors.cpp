#include<bits/stdc++.h>
using namespace std;
int factor(int n){
int a=0,b=0;
for(int i=2;i<=sqrt(n);i++){
   a=0;
   while(n%i==0){
    a++;
    n=n/i;
   }
   if(a>0)b++;
}
if(n>1)b++;
return b;
}
int main()
{
    while(1){
        int n;
        cin>>n;
        if(n==0)break;
        else cout<<n<<" : "<<factor(n)<<endl;
    }

    return 0;
}
