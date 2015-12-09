#include<iostream>
using namespace std;
void writeArrayBack(char anArray[],int first,int last)
{
	if(first<=last){
		cout<<anArray[last]<<endl;
		writeArrayBack(anArray,first,last-1);
	}
}
int main(){
	char anArray[10];
	int i;
	for(i=0;i<10;i++){
		cin>>anArray[i];
	}
	writeArrayBack(anArray,0,9);
	return 0;
}
