#include<iostream>
#include<cstring>
using namespace std;

int dp[50][50];

int largest_common_substring(string x,string y,int n,int m){

    for(int i=0,j=0;i<=n,j<=m;i++,j++){
        dp[i][0]=0;
        dp[0][j]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1] == y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else if(x[i-1] != y[j-1])
                dp[i][j] = 0;
        }
    }

    /*for (int i = 0; i <= n; i++)
        {
       for (int j = 0; j <= m; j++)
          printf ("%4d", dp[i][j]);
       printf("\n");
    }*/

    int res = 0;
    for (int i = 0; i <= n; i++){
       for (int j = 0; j <= m; j++)
            if(dp[i][j]>res)
                res = dp[i][j];
    }
    return res;
}

int main(){
    string x= "abcdghqwerty"; //qwerty
    string y= "abcefhrqwerty"; //qwerty
    cout<<"Largest Common Substring's Length: "<<largest_common_substring(x,y,x.length(),y.length());
    return 0;
}