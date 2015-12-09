#include<iostream>
using namespace std;
int MultiSum(int num[],int count){
	if(count>0){
		return num[count]*MultiSum(num,count-1);
	}
	return num[count];
}
int main(){
	int i;
	int num[10];
	for(i=0;i<10;i++){
		cin>>num[i];
	}
	cout<<MultiSum(num,9)<<endl;
	return 0;
}
