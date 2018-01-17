#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int findInOrder(int data[],int start,int end){
    int result = data[start];
    for(int i = start+1;i<=end;i++){
        if(result>data[i]) result = data[i];
    }
    return result;
}

int findMin(int data[],int length){
    if(data==nullptr || length<=0){
        logic_error ex("Invalid input!");
        throw new exception(ex);
    }
    int index1 = 0;
    int index2 = length-1;
    int mid = index1;
    while(data[index1]>=data[index2]){
        if(index2-index1==1){
            mid = index2;
            break;
        }
        if(data[index1]==data[index2]&&data[mid]==data[index1]){
            return findInOrder(data,index1,index2);
        }
        if(data[mid]>=data[index1]){
            index1 = mid;
        }else if(data[mid]<=data[index2]){
            index2 = mid;
        }
    }
    return data[mid];
}

int main(int argc,char* argv[]){
    int data[] = {1,1,0,1,1,1,1};
    int result = findMin(data,7);
    printf("%d\n",result);
    return 0;
}
