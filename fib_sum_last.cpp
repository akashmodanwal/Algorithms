#include<bits/stdc++.h>
using namespace std;

unsigned long long pow_iter(int m,int n){
    unsigned long long pow = 1;
    while(n>1){
        if(n%2==0){
            m=m*m;
            n=n/2;
            
        }
        else{
            pow=pow*m;
            m=m*m;
            n=(n-1)/2;        
        }
    }
    pow=pow*m;
    return pow;
}

unsigned long long fib_iter_sum(unsigned long long n){
    unsigned long long sum=0;
    unsigned long long fib[n+1];
    fib[0] = 0;
    fib[1] = 1;
    for(int i=2;i<=n;i++){
        fib[i] = (fib[i-1] +fib[i-2])%10;
        sum = sum  +fib[i];
    }
    return sum;
}

int main(){

    // clock_t start, end;
    // /* Recording the starting clock tick.*/
    // start = clock();
    // cout<<fib_rec(100);
    // //cout<<fib_iter(5000);
    // // Recording the end clock tick.
    // end = clock();
  
    // // Calculating total time taken by the program.
    // double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    // cout << "Time taken by program is : " << fixed 
    //      << time_taken << setprecision(5);
    // cout << " sec " << endl;

    // while(true){
    //     int n = rand() %1000000;
    //     cout<<n<<endl;

    //     cout<<endl;
    //     //long long res1 = fib_rec(n);
    //     long long res2 = fib_iter(n);
    //     long long res3 = fib(n);
        
    //     if(res3 == res2){
    //         cout<<"OK"<<endl;
    //     }
    //     else if(res3 != res2){
    //         cout<<res3<<" "<<res2<<endl;
    //         break;
    //     }
    // }
    unsigned long long  n;
    cin>>n;
    unsigned long long res = fib_iter_sum(n);
    cout<< res%10<<endl;
    // int r=0;
    // unsigned long long i =res;
    // while(i>0){
    //     i=i/10;
    //     r++;
    // }
    // int a= res/pow(10,r-1);
    // cout<<a;
    return 0;

}