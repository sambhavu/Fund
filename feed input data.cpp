#include<algorithm> 
#include<cmath> 
#include<vector> 
#include<iostream> 
using namespace std;


class underlying{
 public:
     underlying(); 
     vector<double> FEED; 
     void input(double data);
}; 

underlying::underlying()
{ 
FEED.resize(3);
} 


void underlying::input(double data){ 
    FEED[0]=FEED[1]; 
    FEED[1]=FEED[2];
    FEED[3]=data; 


} 



class X{ 
   public:
       double data(); 
}; 

double X::data(){

return 202.34499; 
} 



int main() 
{ 

   underlying equity; 
   X NYSE
   equity.input(NYSE.data()); 
   
return 0; 
} 

