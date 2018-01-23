#include<cstdio>
#include<cstdlib>
#include<bitset>
#include<assert.h>
#include<iostream>
#include<ctime>
using namespace std;

const int max_size = 5000000;

int main(int argc,char* argv[]){
    clock_t begin = clock();
    bitset<max_size> bit_map;
    bit_map.reset();
    int num;
    FILE* fp_out_file = fopen("data.txt","r");
    assert(fp_out_file);
    while(fscanf(fp_out_file,"%d ",&num)!=EOF){
        if(num<max_size) bit_map.set(num,1);
    }
    FILE* fp_in_file = fopen("sorted_data.txt","w");
    assert(fp_in_file);
    for(int i=0;i<max_size;i++){
        if(bit_map[i]==1)
            fprintf(fp_in_file,"%d ",i);
    }
    int result = fseek(fp_out_file,0,SEEK_SET);
    if(result) cout<<"Seek failed!"<<endl;
    else{
        bit_map.reset();
        while(fscanf(fp_out_file,"%d ",&num)!=EOF){
            if(num>=max_size&&num<2*max_size){
                num -= max_size;
                bit_map.set(num,1);
            }
        }
        for(int i=0;i<max_size;i++){
            if(bit_map[i]==1)
                fprintf(fp_in_file,"%d ",i+max_size);
        }
    }
    clock_t end = clock();
    cout<<"Bit Map Cost Time:"<<(end-begin) / CLOCKS_PER_SEC<<"s"<<endl;
    fclose(fp_out_file);
    fclose(fp_in_file);
    return 0;
}
