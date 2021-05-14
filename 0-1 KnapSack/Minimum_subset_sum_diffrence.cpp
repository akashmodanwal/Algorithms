#include<bits/stdc++.h>
#include<vector>
using namespace std;
bool dp[5][300];

int min(int a,int b){
    if(a>b){
        return b;
    }
    else
        return a;
}

void subset_sum(int *arr,int sum,int n){
    dp[0][0] = true;
    for(int i=1;i<=n;i++)
        dp[i][0] = true;
    for(int i=1;i<=sum;i++)
        dp[0][i] = false;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
        
    }
    /*
    for (int i = 0; i <= n; i++)
     {
       for (int j = 0; j <= sum; j++)
          printf ("%4d", dp[i][j]);
       printf("\n");
     }
    */
    return ;
}

int minimum_subset_sum_diffrence(int *arr,int n){
    vector<int> A;
    int sum=0;
    for(int i=0;i<n;i++){
        sum = sum + arr[i];
    }
    subset_sum(arr,sum,n);
    for(int j=0;j<=sum/2+1;j++){
        if(dp[n][j]==true){
            A.push_back(j);
        }
    }
    int m = INT_MAX;
    for(int i=0;i<A.size();i++){
        m = min(m,(sum-2*A[i]));
    }
    return m;
}

int main(){
    int arr[]= {14,25,78,96};
    int n=sizeof(arr)/sizeof(arr[0]);
    int a= minimum_subset_sum_diffrence(arr,n);
    cout<<"Minimum Subset Sum Diffrence is: "<<a;//{96+14} - {78+25} = 7
    return 0;

}
