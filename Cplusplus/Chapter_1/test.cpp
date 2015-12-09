//函数模板
#include<iostream>
using namespace std;
template <class T> T getMax(T a,T b){
	T result;
	result=(a>b)?a:b;
	return result;
}
int main(){
	int a=10;
	int b=5;
	int c;
	c=getMax(a,b);
	cout<<c<<endl;
	return 0;
}
