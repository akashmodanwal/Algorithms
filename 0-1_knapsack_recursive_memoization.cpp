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
    if(n==0 || w==0)
        return 0;
    if(dp[w][n]!= -1){
        return dp[w][n];
    }
    if(wt[n-1]<=w){
        return (dp[w][n]=max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1)));
    }
    else if (wt[n-1]>w){
        return (dp[w][n]=knapsack(wt,val,w,n-1));
    }
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
