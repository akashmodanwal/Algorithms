#include<bits/stdc++.h>
using namespace std;
unsigned long long fib_rec(unsigned long long n){
    if(n<=1)
        return n;
    return fib_rec(n-2)+fib_rec(n-1);
}
unsigned long long fib_iter(unsigned long long n){
    unsigned long long t0=0,t1=1,s;

    if(n<=1)
        return n;

    for(int i=2;i<=n;i++){
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

unsigned long long fib(unsigned long long n){
    unsigned long long fib[n+1];
    fib[0] = 0;
    fib[1] = 1;
    for(int i=2;i<=n;i++){
        fib[i] = fib[i-1] +fib[i-2];
    }
    return fib[n];
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
    unsigned long long n;
    cin>>n;
    cout<<fib_iter(n);
    return 0;

}