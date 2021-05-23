#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int max(int a,int b){
    if(a>b)
        return a;
    return b;
}

int LCS(string x,string y,int n){
    for(int i=0;i<-n;i++)
        dp[i][0] = 0;
    for(int i=1;i<=n;i++)
        dp[0][i] = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1]==y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else  
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][n];
}

string reverse(string x,int n){
    string y;
    for(int i=n-1;i>=0;i--){
        y.push_back(x[i]);  
    }
    return y;
}

int longest_palindromic_sequence(string x,int n){
    string y = reverse(x,n);
    return LCS(x,y,n);
}

int main(){
    string x ="nitinaa"; //nitin
    cout<<"Length of Longest Palindromic Subsequence: "<<longest_palindromic_sequence(x,x.length());
    return 0;
}