#include<iostream>
using namespace std;
int pow_rec1(int m,int n);
int pow_rec2(int m,int n);
int pow_iter(int m,int n);
int main(){
    int m,n;
    cout<<"Enter number before exponent!"<<endl;
    cin>>m>>n;
    int r=pow_iter(m,n);
    int s=pow_rec1(m,n);
    int t=pow_rec2(m,n);
    cout<<r<<s<<t;
    return 0;
}
int pow_iter(int m,int n){
    int pow=1;
    while(n>1){
        if(n%2==0){
            m=m*m;
            n=n/2;
            
        }
        else{
            pow=pow*m;
            m=m*m;
            n=n/2;        
        }
    }
    pow=pow*m;
    return pow;
}
int pow_rec1(int m, int n){
    if(n==0){
        return 1;
    }
    else{
        return pow_rec1(m,n-1)*m;
    }
}

int pow_rec2(int m,int n){
    if(n==0){
        return 1;
    }
    if(n%2==0){
        return pow_rec2(m*m,n/2);
    }
    else
        return m*pow_rec2(m*m,(n-1)/2);

}
