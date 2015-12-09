#ifndef SACC_H
#define SACC_H
#include "Acc.h"
class SAcc:public Acc{
        protected:
		double interest_rate;
        public:
		SAcc(double rate,double balan);
                double computeInterest();
};
#endif

