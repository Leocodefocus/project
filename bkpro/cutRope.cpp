#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<memory.h>
#include<math.h>

using namespace std;

int maxMultiply(int length){
    if(length<=1) return 0;
    if(length==2) return 1;
    if(length==3) return 2;

    int* products = new int[length+1];
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;
    int max=0;
    for(int i=4;i<=length;i++){
        max=0;
        for(int j=1;j<=i/2;j++){
            int product=products[j]*products[i-j];
            if(product>max) max=product;
            products[i]=max;
        }
    }
    max = products[length];
    delete[] products;
    return max;
}

int maxGreedy(int length){
    if(length<2) return 0;
    if(length==2) return 1;
    if(length==3) return 2;
    int timesOf3 = length/3;
    if(length-timesOf3*3==1) timesOf3-=1;
    int timesOf2 = (length-3*timesOf3)/2;
    return (int)(pow(3,timesOf3))*(int)(pow(2,timesOf2));    
}

int main(int argc,char* argv[]){
    int length = 8;
    int result = maxMultiply(length);
    int result1 = maxGreedy(length);
    printf("%d %d\n",result,result1);
    return 0;
}
