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
    
    int type; 
    
    virtual void display(){ 
        cout<<"option";
    }
    
};


double option::d(double k, double iv, double t, double p, double r){
    
    return .3; //example
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

		void display() {
		
			delta= d(strike, impliedvol, time, price, intrate);
         cout<<delta;
		}
	
};


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
	stock apple(240, 30, .2,.03,236.7); 
	
	option o; 

	option *o1 = &apple;
	

	o1->display(); 
	
	
	
	
}
