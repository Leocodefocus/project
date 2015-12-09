#include"mergesort.h"
#include<stdlib.h>
#include<iostream>
#include<stdio.h>
#include"time.h"
#define MAX_LENGTH 100
#define random(x)(rand()%x)
using namespace std;
int get_random(int m,int n){
	return (random(m)+n-m);
}
int get_sequence(int S[],int k,int m,int n){
	int i;
	for(i=0;i<k;i++){
		S[i]=get_random(m,n);
	}
	return 0;
}
void Merge(int S[],int low,int mid,int high){
	int B[MAX_LENGTH];
	int i,j;
	int k;
	for(k=low;k<=high;k++){
		B[k]=S[k];
	}
	for(i=low,j=mid+1,k=i;i<=mid&&j<=high;k++){
		if(B[i]<=B[j])
			S[k]=B[i++];
		else
			S[k]=B[j++];
	}
	while(i<=mid)	S[k++]=B[i++];
	while(j<=high)	S[k++]=B[j++];
}
void Merge_Sort(int S[],int low,int high){
	if(low<high){
		int mid=(low+high)/2;
		Merge_Sort(S,low,mid);
		Merge_Sort(S,mid+1,high);
		Merge(S,low,mid,high);
	}
}
void mergesort(int S[],int k){
	Merge_Sort(S,0,k-1);
	//cout
}
int minimum(int S[],int k){
	int i=0;
	int min=S[0];
	for(i=0;i<k;i++){
		if(S[i]<min){
			min=S[i];
		}
	}
	return min;
	//cout<<"unsorted sequence of "<<k<<" integers:"<<min<<endl;
}
int maximum(int S[],int k){
	int i=0;
	int max=S[0];
	for(;i<k;i++){
		if(S[i]>max){
			max=S[i];
		}
	}
	return max;
	//cout<<"sorted sequence of "<<k<<" integers:"<<max<<endl;
}
double average(int S[],int k){
	double aver;
	int sum=0;
	int i;
	for(i=0;i<k;i++){
		sum+=S[i];
	}
	aver=(double)sum/k;
	return aver;
}
