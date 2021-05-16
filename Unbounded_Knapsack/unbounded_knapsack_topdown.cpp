#include<iostream>
using namespace std;
int dp[10][50];

int max(int a,int b){
    if(a>b)
        return a;
    return b;
}

int unbounded_knapsack(int *wt,int *value,int w,int n){
    int dp[n+1][w+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            if(wt[i-1]<=j){
                dp[i][j] = max(value[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
            }
            else if(wt[i-1]>j){
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    /*for (int i = 0; i <= n; i++)
     {
       for (int j = 0; j <= w; j++)
          printf ("%4d", dp[i][j]);
       printf("\n");
     }*/
    return dp[n][w];
}
int main(){
    int wt[] = {1,2,3,4,5,6,7,8};
    int value[] = {1,2,6,7,9,8,9,10};
    int n = sizeof(wt)/sizeof(wt[0]);
    int w=10;
    cout<<unbounded_knapsack(wt,value,w,n);
    return 0;
}
