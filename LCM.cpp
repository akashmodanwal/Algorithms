#include<bits/stdc++.h>
using namespace std;

long long GCD(long long a,long long b){
    if(a%b != 0){
        return GCD(b,a%b);
    }
    else{
        return b;
    }
}

long long LCM(long long a,long long b){
    long long c = GCD(a,b);
    return (a*b)/c;
}

int main(){
    unsigned long long a,b;
    cin>>a>>b;
    cout<<LCM(a,b);
}