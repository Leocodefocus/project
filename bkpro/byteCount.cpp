#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<bitset>
using namespace std;

int countBytes(int n){
    unsigned n1 = (unsigned)n;
    bitset<32> b(n1);
    bitset<32> c(n);
    printf("%d\n",n);
    cout<<b<<" "<<c<<endl;
    int count = 0;
    while(n1){
        if(n1&1) count++;
        n1 = n1>>1;
    }
    return count;
}

int flagShift(int n){
    unsigned flag = 1;
    int count = 0;
    while(flag){
        if(flag&n) count++;
        flag = flag<<1;
    }
    return count;
}

int subCount(int n){
    int count = 0;
    while(n){
        ++count;
        n=(n-1)&n;
    }
    return count;
}

int main(int agrc,char* argv[]){
    int result = countBytes(-100);
    int result1 = flagShift(-100);
    int result2 = subCount(-100);
    printf("%d %d %d\n",result,result1,result2);
    return result;
}
