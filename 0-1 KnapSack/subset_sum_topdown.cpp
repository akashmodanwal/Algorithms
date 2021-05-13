#include<iostream>
#include<cstring>
using namespace std;
bool dp[50][50];

bool subset_sum(int* arr,int sum,int n ){

    dp[0][0]= true;
    
    for(int i=1;i<=n;i++){
        dp[i][0]=true;
    }

    for(int i=1;i<=sum;i++){
        dp[0][i]=false;
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
    /*
    for (int i = 0; i <= n; i++)
     {
       for (int j = 0; j <= sum; j++)
          printf ("%4d", dp[i][j]);
       printf("\n");
     }*/
    return dp[n][sum];
}

int main(){
    int arr[] = {31,12,2,6,9,12,33,22,456};
    int sum = 20;
    int n=sizeof(arr)/sizeof(arr[0]);
    bool c=subset_sum(arr,sum,n);
    if(c==true){
        cout<<"Subset Found"<<endl;
    }
    else{
        cout<<"No Subset Found"<<endl;
    }
    return 0;
}