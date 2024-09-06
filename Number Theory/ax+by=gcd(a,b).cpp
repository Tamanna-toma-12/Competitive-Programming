#include<bits/stdc++.h>
using namespace std;
int X,Y;
int gcd(int a,int b){
int x2,x1,y2,y1,r2,r1,r,q,x,y;
x2=1,x1=0,y2=0,y1=1;
for(r2=a,r1=b;r1!=0;x2=x1,x1=x,y2=y1,y1=y,r2=r1,r1=r){
    q=r2/r1;
    r=r2%r1;
    x=x2-(q*x1);
    y=y2-(q*y1);
}
X=x2;
Y=y2;
return r2;
}
int main()
{
    int a=240,b=46;
    int g=gcd(a,b);
    cout<<X<<" "<<Y<<" "<<g<<endl;
    return 0;
}
