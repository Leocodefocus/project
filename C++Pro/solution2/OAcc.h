#ifndef OACC_H
#define OACC_H
#include "Acc.h"
class OAcc:public Acc{
	protected:
		double fee_per_trans;
		double interest_rate;
		double min_balance;
	public:
		OAcc(double balan,double fee,double rate,double min_balan);
		double computeInterest();
		void deposit(double amount);
		void withdraw(double debit);
};
#endif
