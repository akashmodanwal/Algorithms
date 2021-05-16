#include<iostream>
using namespace std;

int coin_change(int *coin,int sum,int n){
   
   static int dp[4][6];
    dp[0][0]=1;

    for(int i=1;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<=sum;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(coin[i-1]<=j)
                dp[i][j] = dp[i][j-coin[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    /*for (int i = 0; i <= n; i++)
     {
       for (int j = 0; j <= sum; j++)
          printf ("%4d", dp[i][j]);
       printf("\n");
     }*/
    return dp[n][sum];
}

int main(){
    int coin[]={1,2,3};
    int sum = 5;
    int n = sizeof(coin)/sizeof(coin[0]);
    cout<<"No Of Ways: "<<coin_change(coin,sum,n);
    return 0;
}