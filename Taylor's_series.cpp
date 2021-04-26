#include<iostream>
using namespace std;
double e(int x,int n){
    static double p=1,f=1;
    double r;
    if(n==0)
        return 1;
    else{
        r=e(x,n-1);
        p=p*x;
        f=f*n;
        return r+(p/f);
    }
}


double e_iter(int x,int n){
    double t=1;
    double num=1,den=1;
    for(int i=1;i<=n;i++){
        num=num*x;
        den=den*i;
        t=t+num/den;
    }
    return t;
}

int main(){
    double a=e(2,10);
    double c=e_iter(2,10);
    cout<<a<<endl<<c;
    return 0;
}
