#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int max(int a,int b){
    if(a>b)
        return a;
    return b;
}

int min(int a,int b){
    if(a>b)
        return b;
    return a;
}

int LCS(string a,string b,int n,int m){
    for(int i=0;i<=n;i++)
        dp[i][0]= 0;
    for(int i=1;i<=m;i++)
        dp[0][i] =0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else  
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}

void solve(string a,string b,int n,int m){
    int lcs = LCS(a,b,n,m);
    cout<<"No Of Insertion: "<<min(n,m)-lcs<<endl;
    cout<<"No of Deletion: "<<max(n,m)-lcs<<endl;
}

int main(){
    string a="heapks";
    string b="peaas";
    solve(a,b,a.length(),b.length());
    return 0;
}