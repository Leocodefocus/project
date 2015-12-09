#include"Acc.h"
#include<iostream>
using namespace std;
Acc::Acc(){
	balance=0.0;
}
Acc::Acc(double balan){
	balance=balan;
}
//void Acc::setNet(double balan){
//	balance=balanc
//}
void Acc::deposit(double amount){
	balance+=amount;
}
void Acc::withdraw(double debit){
	if(debit<=balance){
		balance=balance-debit;
	}
	else{
		cout<<"Debit amount exceeded account balance."<<endl;
	}
}
double Acc::getNet(){
	return balance;
}
