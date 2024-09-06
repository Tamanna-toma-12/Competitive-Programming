#include<bits/stdc++.h>
using namespace std;
long long SNOD(long long n){
long long ret=0;
for(long long int i=1;i<=sqrt(n);i++){
    ret+=(n/i)-i;
}
//ret num of(a<b)pair &&ret num of(a>b)pair;
ret*=2;
ret+=sqrt(n);
return ret;
}
int main()
{
    cout<<SNOD(5)<<endl;
    return 0;
}
