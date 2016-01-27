#include<iostream>
using namespace std;
class test{
	public:
		test(){cout<<"Cons\n"<<endl;}
		~test(){cout<<"Des\n"<<endl;}
};
int main(){
	for(int i=0;i<2;i++){
		test cd;
	}
	char* str="test";
	cout<<*str<<endl;
	cout<<str<<endl;
	return 0;
}
