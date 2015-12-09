#include"CAcc.h"
#include"Acc.h"
#include<iostream>
using namespace std;
CAcc::CAcc(double fee,double balan){
	balance=balan;
	fee_per_trans=fee;
	//balance=balan;
}
void CAcc::deposit(double amount){
	balance=balance+amount;
}
void CAcc::withdraw(double debit){
	 if(debit<=(balance+fee_per_trans)){
                balance-=debit;
        }
        else{
                cout<<"Debit amount exceeded account balance."<<endl;
        }
}

