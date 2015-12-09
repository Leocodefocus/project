#include"OAcc.h"
#include"Acc.h"
#include<iostream>
using namespace std;
OAcc::OAcc(double balan,double fee,double rate,double min_balan){
	balance=balan;
	fee_per_trans=fee;
	interest_rate=rate;
	min_balance=min_balan;
}
double OAcc::computeInterest(){
	return ((interest_rate*balance)/100);
}
void OAcc::deposit(double amount){
	balance+=amount;
}
void OAcc::withdraw(double debit){
	if(debit<=(balance+fee_per_trans+min_balance)){
                balance-=debit;
        }
        else{
                cout<<"Debit amount exceeded account balance."<<endl;
        }

}
