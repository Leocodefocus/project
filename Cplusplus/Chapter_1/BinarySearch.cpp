#include<iostream>
using namespace std;
int binarySearch(int NumArray[],int first,int last,int target){
	int index=0;
	int mid=first+(last-first)/2;
	if(NumArray[mid]==target){
		index=NumArray[mid];
	}else if(NumArray[mid]<target){
		index=binarySearch(NumArray,mid+1,last,target);
	}else{
		index=binarySearch(NumArray,first,mid-1,target);
	}
	return index;
}
