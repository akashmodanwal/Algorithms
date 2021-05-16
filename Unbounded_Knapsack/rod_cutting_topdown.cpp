#include<iostream>
using namespace std;

int max(int a,int b){
    if(a>b)
        return a;
    return b;
}

int rod_cutting(int *piece,int *price,int length,int n){
    int dp[n+1][length+1];
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=length;j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
            
            if(piece[i-1]<=j)
                dp[i][j] = max(price[i-1]+dp[i][j-piece[i-1]],dp[i-1][j]);
            
            else if(piece[i-1]>j)
                dp[i][j] = dp[i-1][j];
            
        }
    }
    return dp[n][length];
}

int main(){
    int piece[]={1,2,3,4,5,6,7,8};
    int price[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
    int length = 8;
    int n= sizeof(piece)/sizeof(piece[0]);
    cout<< rod_cutting(piece,price,length,n);
    return 0;
}