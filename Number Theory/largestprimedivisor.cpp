#include <iostream>

using namespace std;

int main() {

   while(1){
        long long n,a=-1,c=0;
    cin>>n;
    if(n==0)break;
   n=abs(n);
    for(long long i=2;(i*i)<=n&&n!=1;i++){
        while(n%i==0){
            a=i;
            n/=i;
        }
        if(a==i)c++;
    }
    //cout<<c<<" "<<a<<endl;
    if(n>a&&c>0)a=n;
    if(c==0)a=-1;
    cout<<a<<endl;
   }

     return 0;
}
