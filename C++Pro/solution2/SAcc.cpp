#include"SAcc.h"
#include"Acc.h"
#include<iostream>
using namespace std;
SAcc::SAcc(double rate,double balan){
        interest_rate=rate;
        balance=balan;
}
double SAcc::computeInterest(){
        return (interest_rate*balance);
}

