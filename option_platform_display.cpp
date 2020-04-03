#include <iostream>
using namespace std;




class option{
    public: 
    
    double delta;
    double gamma;
    double theta;
    double vega;
    double rho;
    
    double d(double k, double iv, double t, double p, double r);
    
       double g(double k, double iv, double t, double p, double r);

   double t(double k, double iv, double t, double p, double r);

   double v(double k, double iv, double t, double p, double r);

   double r(double k, double iv, double t, double p, double r);
    
    int type; 
    
    virtual void display(){ 
        cout<<"option";
    }
    
};


double option::d(double k, double iv, double t, double p, double r){
    
    return 3; //example
}

double option::g(double k, double iv, double t, double p, double r){
    
    return 1; //example
}

double option::t(double k, double iv, double t, double p, double r){
    
    return -2; //example
}

double option::v(double k, double iv, double t, double p, double r){
    
    return 25; //example
}

double option::r(double k, double iv, double t, double p, double r){
    
    return 3; //example
}


class underlying: public option{
	public:
	
	double strike;
	double time;
	double impliedvol;
	double price;
	double intrate; 
		
};






class stock: public underlying {
	public:
	
	stock(double k, double t, double iv, double r, double p);

  void calculate();
  void display();
	

};


void stock::calculate(){

delta=d(strike,impliedvol,time,price,intrate);

gamma=g(strike,impliedvol,time,price,intrate);

vega=v(strike,impliedvol,time,price,intrate);
        
theta=t(strike,impliedvol,time,price,intrate);
        
rho=r(strike,impliedvol,time,price,intrate);
    
}

void stock::display(){ 

cout<<"\n\nEqutiy Price :    "<<price;
cout<<"\nDays         :    "<<time;
cout<<"\nInterest Rate:    "<<intrate;
cout<<"\nImplied Vol  :    "<<impliedvol;
cout<<"\nStrike       :    "<<strike; 

cout<<"\n\nDelta:   "<<delta;
cout<<"\nGamma:   "<<gamma;
cout<<"\nVega:    "<<vega;
cout<<"\nTheta:   "<<theta;
cout<<"\nRho:     "<<rho;
    
cout<<"\n===================";
    
}

stock::stock(double k, double t, double iv, double r, double p)
{ 
    strike=k;
    time=t;
    impliedvol=iv;
    intrate=r;
    price=p; 
} 




class bond: public underlying {
	public:
    bond(double k, double t, 
    double iv, double r, double p); 
    
    
		void display() {
			cout << intrate;
		}
		
};

bond::bond(double k, double t, double iv, double r, double p){
    strike=k;
    time=t;
    impliedvol=iv;
    intrate=r;
    price=p;
}




int main() {

double price; 
double strike;
double t;
double intrate;
double vol; 

//double ytm;
//double div_yield; 

price=236.7;
t=30;
vol=.25;
strike =200; 
intrate=.03;

double step=1;

stock apple(
	strike, t,
	vol,
	intrate,
   price); 

option *o1=&apple; 

for(int i=0; i<=7; ++i){
     
     apple.strike +=step;
	    
	    o1->display();
	
	}
	
	strike=strike+step;
	
}
