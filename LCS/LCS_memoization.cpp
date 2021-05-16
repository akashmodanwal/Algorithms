#include<iostream>
#include<cstring>
using namespace std;

int dp[50][50];

int LCS_memoized(string x,string y,int n,int m){
    if(n==0 || m==0)
        return 0;
    if(dp[n][m] != -1)
        return dp[n][m];
    if(x[n-1]==y[m-1])
        return dp[n][m]= 1+ LCS_memoized(x,y,n-1,m-1);
    else if(x[n-1]!=y[m-1])
        return dp[n][m] = max(LCS_memoized(x,y,n-1,m), LCS_memoized(x,y,n,m-1));
}

int main(){
    memset(dp,-1,sizeof(dp));
    string x= "abcdgh";
    string y= "abedfhr";
    cout<<"Largest Common Subsequence's Length: "<<LCS_memoized(x,y,x.length(),y.length());
    return 0;
}

