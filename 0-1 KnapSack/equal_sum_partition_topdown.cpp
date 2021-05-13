#include<iostream>
#include<stdio.h>
using namespace std;

int a;

bool subset_sum(int* arr, int sum, int n){
    bool dp[n+1][sum+1];

    dp[0][0]= true;

    for(int i=1;i<=n;i++){
        dp[i][0] = true;
    }
    
    for(int i=1;i<=sum;i++){
        dp[0][i] = false;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

bool equal_sum_partition(int* arr,int n){
    int s=0;
    for(int i=0;i<n;i++){
        s = s + arr[i];
    }
    a=s/2;
    return subset_sum(arr,s/2,n);
}

int main(){
   
    int arr[]={7,14,28,24,25};
    int n = sizeof(arr)/sizeof(arr[0]);
    bool c = equal_sum_partition(arr,n);
    if(c==true){
        printf("Equal sum Partition Found With Sum %d",a);
    }
    else{
        cout<<"Partition with Equal sum Not found ";
    }
    return 0;
}