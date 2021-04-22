#include<iostream>
using namespace std;
int max(int,int);
int cutrod(int *p,int n){
    if(n<=0)
        return 0;
    int q = -999999;
    for(int i=1;i<=n;i++){
        q = max(q,p[i]+cutrod(p,n-i));
    }
    return q;
}
 int max(int a,int b){
     if(a>=b){
         return a;
     }
     else{
         return b;
     }
 }

 int main(){
     int t;
     cin>> t;
     while(t--){
    int n;
    cin>>n;
     int a[]={0,1,5,8,9,10,17,20,24,30};
     int r= cutrod(a,n);
     cout<<r;}
     return 0;
 }
