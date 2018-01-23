#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<time.h>
#include<assert.h>

using namespace std;

const unsigned long size = 10000000;
int num[size];

unsigned long randint(unsigned long l,unsigned long u){
    //printf("%d\n",RAND_MAX);
    return l+(rand()*RAND_MAX+rand())%(u-l+1);  
}

int main(int argc,char* argv[]){
    unsigned long n;
    FILE* fp = fopen("data.txt","w");
    for(int i=0;i<size;i++) num[i]=i+1;
    srand((unsigned)time(NULL));
    unsigned long i;
    for(n=0;n<size;n++){
        //printf("%ld\n",n);
        i = randint(n,size-1);
        //printf("%ld\n",i);
        printf("%ld %d %ld %d\n",i,num[i],n,num[n]);
        int nm = num[n];num[n]=num[i];num[i]=nm;
    }
    for(n=0;n<size;n++){        
        fprintf(fp,"%d ",num[n]);
        //if((n+1)%1000==0) fprintf(fp,"%s","\n");
    }
    fclose(fp);
    return 0;
}
