#include<bits/stdc++.h>
using namespace std;

int dp[50][50];

int max(int a,int b){
    if(a>b)
        return a;
    return b;
}

void LCS(string x,string y,int n,int m){
    for(int i=0;i<=n;i++)
        dp[i][0] = 0;
    for(int i=0;i<=m;i++)
        dp[0][i] = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] =max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    /*for (int i = 0; i <= n; i++)
        {
       for (int j = 0; j <= m; j++)
          printf ("%4d", dp[i][j]);
       printf("\n");
    }*/
}

string Print_LCS(string x,string y,int n,int m){
    LCS(x,y,n,m);
    int i=n,j=m;
    string res;
    
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            res.push_back(x[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    string x= "abcdghqwerty"; //abchqwerty
    string y= "abcefhrqwerty"; //abchqwerty
    cout<<"Longest Common Subsequence is: "<<Print_LCS(x,y,x.length(),y.length());
    return 0;
}