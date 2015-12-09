#include<iostream>
#include"Acc.h"
#include"CAcc.h"
#include"SAcc.h"
#include"OAcc.h"
#define FEE 5.0
#define INTERESTRATE 5
#define MINBALANCE 100.0
using namespace std;
void display_list(){
	cout<<"------Welcome to use XYZ's system------"<<endl;
	cout<<"\tthe fee per transaction is "<<FEE<<"$"<<endl;
	cout<<"\tthe interest rate is "<<INTERESTRATE<<"%"<<endl;
	cout<<"\tyour account should maintain "<<MINBALANCE<<"$ as minbalance"<<endl;
	cout<<"\t1.Deposit Money"<<endl;
	cout<<"\t2.Withdraw Money"<<endl;
	cout<<"\t3.Print Balance"<<endl;
	cout<<"\t4.Print Interest"<<endl;
	cout<<"---------------------------------------"<<endl;
	cout<<"Your Choice:";
}
int main(){
	double fee=5.0;
	double interestrate=0.05;
	double minbalance=100.0;
	double balance=0.0;
        double debit=0.0;
	//Acc account(balance);//=new Acc(0.0);
	CAcc c_acc(fee,balance);//=new CAcc(0.0,0.0);
	OAcc o_acc(balance,fee,interestrate,minbalance);//=new OAcc(0.0,0.0,0.0,0.0);
	SAcc s_acc(interestrate,balance);//=new SAcc(0.0,0.0);
	int choice;
	display_list();
	while(cin>>choice){
		switch(choice){
			case 1:
				cout<<"Please enter the amount to deposit:";
				cin>>balance;
					//account.deposit(balance);
					c_acc.deposit(balance);
					o_acc.deposit(balance);
					s_acc.deposit(balance);
				break;
			case 2:
				cout<<"Please enter the amount to withdraw:";
					cin>>debit;
					o_acc.withdraw(debit);
					if(o_acc.getNet()!=s_acc.getNet()){
					//	account.withdraw(debit);
						c_acc.withdraw(debit);
						o_acc.withdraw(debit);
						s_acc.withdraw(debit);
					}else{
						cout<<"Your account does not have enough money!"<<endl;
					}
				break;
			case 3:
					cout<<"The balance is "<<c_acc.getNet()<<"$"<<endl;
				break;
			case 4:
					cout<<"The present interest is "<<s_acc.computeInterest()<<"$"<<endl;
				break;
			default:
				break;
		}
		display_list();
	}
	return 0;
}
