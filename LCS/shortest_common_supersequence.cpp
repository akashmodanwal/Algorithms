#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int max(int a,int b){
    if(a>b)
        return a;
    return b;
}

int LCS(string x,string y,int n,int m){
    
    for(int i=0;i<=n;i++)
        dp[i][0]= 0;
    for(int i=1;i<=m;i++)
        dp[0][i] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int SCS(string x,string y,int n,int m){
    return m+n - LCS(x,y,n,m);
}

int main(){
    string x="aggtab";
    string y="gxtxayb";
    cout<<"Shortest Common Supersequence's Length: "<<SCS(x,y,x.length(),y.length());
    return 0;
}