#include<iostream>
using namespace std;

int max(int a,int b){
    if(a>=b)
        return a;
    else return b;
}
int knapsack(int wt[], int val[], int w, int n) {
    if(n==0 || w==0)
        return 0;
    if(wt[n-1]<=w){
        return max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
    }
    else if (wt[n-1]>w){
        return knapsack(wt,val,w,n-1);
    }
}
int main()
{
    int val[] = { 20, 5, 10, 40, 15, 25};
    int wt[] = {1, 2, 3, 8, 7, 4 };
    int w = 10;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapsack(wt, val,w,n);
    return 0;
}
