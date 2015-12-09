#ifndef CACC_H
#define CACC_H
#include "Acc.h"
class CAcc:public Acc{
	protected:
		double fee_per_trans;
	public:
		CAcc(double fee,double balan);
		void deposit(double amount);
                void withdraw(double debit);

};
#endif
