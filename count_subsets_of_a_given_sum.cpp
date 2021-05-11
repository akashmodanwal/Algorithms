#include<iostream>
using namespace std;

int count_subset(int* arr,int n,int sum){
    int dp[n+1][sum+1];
    dp[0][0]=1;

    for(int i=1;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<=sum;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    /*for (int i = 0; i <= n; i++)
     {
       for (int j = 0; j <= sum; j++)
          printf ("%4d", dp[i][j]);
       printf("\n");
     }*/
    return dp[n][sum];
}

int main(){
    int arr[]={2,3,6,5,8,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum = 10;
    int c =count_subset(arr,n,sum);
    cout<<"Count Of Subsets with Sum "<<sum<<" is "<<c<<endl;
    return 0;
}