#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int MCM(int arr[],int i,int j){
    if(i>=j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int min = INT_MAX;
    for(int k=i;k<=j-1;k++){
        int temp = MCM(arr,i,k) + MCM(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
        if(temp<min)
            min =temp;
    }
    return dp[i][j]= min;
}

int main(){
    int arr[]={1,2,3,4,5};
    memset(dp,-1,sizeof(dp));
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<MCM(arr,1,n-1);
    return 0;
}