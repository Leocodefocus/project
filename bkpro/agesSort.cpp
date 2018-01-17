#include<cstdio>
#include<cstdlib>

void ageSort(int ages[],int length){
    int MaxAge = 99;
    int timesOfAge[MaxAge+1];
    for(int i=0;i<=MaxAge;i++){
        timesOfAge[i] = 0;
    }
    for(int i=0;i<length;i++){
        int age = ages[i];
        timesOfAge[age]++;
    }
    int index=0;
    for(int i=0;i<=MaxAge;i++){
        for(int j=0;j<timesOfAge[i];j++){
            ages[index]=i;
            index++;
        }
    }
    for(int i=0;i<length;i++){
        printf("%d ",ages[i]);
    }
    printf("\n");
}

int main(int argc,char* argv[]){
    int ages[]={12,23,43,34,26,23,32,67,54,45,29,33,51,11,61,47,55};
    ageSort(ages,17);
    return 0;
}
