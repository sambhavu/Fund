#include<cmath>
#include<algorithm>
#include<iostream>

using namespace std; 

class fund{ 

public: 

void Europe(); 
void showEurope(double capital);

};

void fund::showEurope(double capital) 
{
   std::cout<<"Fund Capital: Europe: "<<capital<<"/n";
}

void fund::Europe(){ 

double capital = 100;
double profit= 0; 

double equityr = .05; 
double optionsr = .8; 
double bondsr = .03; 
double fxr = .05; 

double equity = 0; 
double options =0; 
double bonds = 0;
double  fx = 0;

int tradingdays= 100; 
 
for(int i = 0; i<tradingdays; ++i) {
      equity = capital*(1+equityr); 
      capital=equity;
      bonds=capital*(1+bondsr);
      capital=bonds;
      fx = capital*(1+fxr);
      capital=fx;
      options = captial*(1+optionsr);
      capital=options;
    }

showEurope(capital); 

}

int main(){ 

fund int; 
int.Europe(); 
int.showEurope();

return 0; 
} 
