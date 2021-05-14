#include<bits/stdc++.h>
using namespace std;

int dp[5][8];

int count_subsets_for_sum(int *arr,int n,int sum){

    dp[0][0]=1;

    for(int i=1;i<=n;i++)
        dp[i][0] = 1;
    
    for(int i=1;i<=sum;i++)
        dp[0][i] = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
            }
            else    
                dp[i][j] = dp[i-1][j];
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

int subset_with_diffrence(int *arr,int diff,int n){
    int s = 0;
    for(int i=0;i<n;i++){
        s = s + arr[i];
    }
    int sum = (diff + s)/2;
    return count_subsets_for_sum(arr,n,sum);
}

int main(){
    int arr[]={1,1,2,3};
    int n= sizeof(arr)/sizeof(arr[0]);
    int diff = 1;
    cout<<"Number of subsets with given Diffrence "<<diff<<" is "<<subset_with_diffrence(arr,diff,n);
    return 0;
}