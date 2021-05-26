#include<iostream>
#include<cstdlib>
using namespace std;


long long Max_pair_product(long long *A,int n){
    long long max = 0;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if(max<A[i]*A[j])
                max=A[i] * A[j];
        }
    }
    return max;
}

long long Max_pair_product_fast(long long *A,int n){
    int max1 = -1;
    int max2 = -1;
    for(int i=0;i<n;++i){
        if(max1 == -1 || A[max1]<A[i])
            max1 = i;
    }
    for(int j=0;j<n;++j){
        if(j != max1){
         if((max2 ==- 1) || (A[j] > A[max2]))
            max2 = j;
        }
    }
    return A[max1]*A[max2];
}

int main(){
    int n;
    cin>>n;
    long long *A= new long long[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    cout<<Max_pair_product_fast(A,n);
    /*
    while(true){
        int n = rand() %10000 +2;
        cout<<n<<endl;
        long long *A = new long long[n];
        for(int i=0;i<n;i++){
            A[i] = rand() % 1000000;
            cout<<A[i]<<" ";
        }
        cout<<endl;
        long long res1 = Max_pair_product(A,n);
        long long res2 = Max_pair_product_fast(A,n);
        
        if(res1 == res2){
            cout<<"OK"<<endl;
        }
        else if(res1 != res2){
            cout<<res1<<" "<<res2<<endl;
            break;
        }
   }*/
    return 0;
}