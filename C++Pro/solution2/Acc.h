#ifndef ACC_H
#define ACC_H
class Acc{
	protected:
		double balance;	
	public:
		Acc();
		Acc(double balan);
		virtual void deposit(double amount);
		virtual void withdraw(double debit);
		//void setNet(double balan);
		double getNet();
};
#endif
