#include<cstdlib>
#include<cstdio>
#include<time.h>
#include<iostream>
#define random(x) (rand()%x)
using namespace std;

int getRandom(int n){
    srand((int)time(0));
    return random(n);
}

int iPartition(int data[],int length,int start,int end){
    if(data==nullptr || start<0 || length<=0 || end>=length) exit(0);
    int index = start+getRandom(end-start+1);
    swap(data[index],data[end]);
    int small = start-1;
    for(index=start;index<end;index++){
        if(data[index]<data[end]){
            ++small;
            if(small!=index) swap(data[small],data[index]);
        }
    }
    swap(data[++small],data[end]);
    return small;
}

void quickSort(int data[],int length,int start,int end){
    if(start==end) return;
    int index = iPartition(data,length,start,end);
    if(index>start)
        quickSort(data,length,start,index-1);
    if(index<end)
        quickSort(data,length,index+1,end);
}

int main(int argc,char* argv[]){
    int data[] = {3,2,4,6,5,1,2,7,9,0,8};
    quickSort(data,11,0,10);
    for(int i=0;i<11;i++){
        printf("%d ",data[i]);
    }
    printf("\n");
    return 0;
}
