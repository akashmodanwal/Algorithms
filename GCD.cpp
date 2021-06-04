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

int main(){
    long long a,b;
    cin>>a>>b;
    cout<<GCD(a,b);
    return 0;
}