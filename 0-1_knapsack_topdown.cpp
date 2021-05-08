#include<iostream>
#include<cstring>
using namespace std;
int dp[50][50];
int max(int a,int b){
    if(a>=b)
        return a;
    else return b;
}
int knapsack(int wt[], int val[], int w, int n) {
    for(int i=0; i < w+1; i++){
        for(int j=0; j< n+1;j++){
            if(j==0 || i==0)
                dp[i][j]=0;
            if(wt[j-1]<=i)
                dp[i][j]=max(val[j-1]+dp[i-wt[j-1]][j-1],dp[i][j-1]);
            else 
                dp[i][j]=dp[i][j-1];
        }
    }
    return dp[w][n];
}
int main()
{
    memset(dp,-1,sizeof(dp));
     int val[] = { 20, 5, 10, 40, 15, 25};
    int wt[] = {1, 2, 3, 8, 7, 4 };
    int w = 10;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapsack(wt, val,w,n);
    return 0;
}