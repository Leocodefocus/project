#include<cstdio>
#include<cstdlib>
#include<memory.h>
#include<iostream>
using namespace std;

int getNum(int n){
    int result = 0;
    while(n>0){
        result += n%10;
        n=n/10;
    }
    return result;
}

int countCore(int rows,int cols,int row,int col,int threshold,bool* visited){
    int count = 0;
    if(row>=0&&row<rows&&col>=0&&col<cols&&(getNum(row)+getNum(col))<=threshold&&!visited[row*cols+col]){
        visited[row*cols+col] = true;
        count = 1 + countCore(rows,cols,row,col-1,threshold,visited) 
                  + countCore(rows,cols,row,col+1,threshold,visited) 
                  + countCore(rows,cols,row-1,col,threshold,visited) 
                  + countCore(rows,cols,row+1,col,threshold,visited);
    }
    return count;
}

int moveCount(int rows,int cols,int threshold){
    if(threshold<=0||rows<=0||cols<=0) return 0;
    bool *visited = new bool[rows*cols];
    for(int i=0;i<rows*cols;i++) visited[i]=false;
    int count = countCore(rows,cols,0,0,threshold,visited);
    delete[] visited;
    return count;
}

int main(int argc,char* argv[]){
    int result = moveCount(100,100,18);
    printf("%d\n",result);
    return 0;
}
