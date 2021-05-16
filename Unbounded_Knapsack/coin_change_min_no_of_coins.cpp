#include<bits/stdc++.h>
using namespace std;

int dp[4][6];

int no_of_coins(int *coin,int sum,int n){
    for(int i=0;i<=n;i++)
        dp[i][0] = 0;

    for(int i=0;i<=sum;i++)
        dp[0][i] = INT_MAX-1;

    for(int i=1;i<=sum;i++){
        if(i%coin[0]==0){
            dp[1][i] = i/coin[0];
        }
        else{
            dp[1][i] = INT_MAX -1;
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=2;j<=sum;j++){
            if(coin[i-1]<=j){
                dp[i][j] = min(1+dp[i][j-coin[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    /*for (int i = 0; i <= n; i++)
        {
       for (int j = 0; j <= sum; j++)
          printf ("%4d", dp[i][j]);
       printf("\n");
    }*/
    if(dp[n][sum]==INT_MAX-1 || dp[n][sum] == INT_MAX)
        dp[n][sum] =-1;
    return dp[n][sum];
}

int main(){
    int coin[]={1,2,5};
    int sum = 11;
    int n = sizeof(coin)/sizeof(coin[0]);
    cout<<"No Of Ways: "<<no_of_coins(coin,sum,n);
    return 0;
}