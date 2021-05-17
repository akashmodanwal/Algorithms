#include<iostream>
#include<cstring>
using namespace std;

int dp[50][50];

int max(int a,int b){
    if(a>b)
        return a;
    return b;
}

int LCS_topdown(string x,string y,int n,int m){

    for(int i=0;i<=n;i++)
        dp[i][0] = 0;
    for(int i=1;i<=m;i++)
        dp[0][i] = 0;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(x[i-1] == y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    /*for (int i = 0; i <= n; i++)
        {
       for (int j = 0; j <= m; j++)
          printf ("%4d", dp[i][j]);
       printf("\n");
    }*/
    return dp[n][m];
}
int main(){
    string x= "abcdghqwerty";
    string y= "abedfhrqwerty";
    cout<<"Largest Common Subsequence's Length: "<<LCS_topdown(x,y,x.length(),y.length());
    return 0;
}