#include"mergesort.h"
#include<iostream>
#define MAX_LENGTH 100

using namespace std;
int S[MAX_LENGTH];
int main(){
	int k,m,n,min,max;
	double aver;
	cout<<"You can quit anytime through pressing CTRL+C"<<endl;
	cout<<"Please enter the values of k,m,n:";
	while(cin>>k>>m>>n){
	if(k>0&&m>0&&n>0&&(k+m<=n)){
		get_sequence(S,k,m,n);
		cout<<"unsorted sequence of "<<k<<" integers:";
		for(int i=0;i<k;i++){
			cout<<S[i]<<" ";
		}
		cout<<endl;
		mergesort(S,k);
		cout<<"sorted sequence of "<<k<<" integers:";
		 for(int i=0;i<k;i++){
                       cout<<S[i]<<" ";
                }
		cout<<endl;
		min=minimum(S,k);
		max=maximum(S,k);
		aver=average(S,k);
		cout<<"min,max,and average of the sequence:"<<min<<","<<max<<" "<<aver<<endl;
	}
	else{
		cout<<"input error!!"<<endl;
	}
	cout<<"Please quit or enter the values of k,m,n:";
	}
	return 0;
}
