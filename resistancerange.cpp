#include<algorithm>
#include <iostream>
#include <string>



double fractional(double high, low, close)
{
    return (.67 * (high + low + close));
}
    
    
    
int main()
{
  
  double high, low, close; 
  
  double Y; 
  Y = fractional(high,low,close);
  
  double R1; 
  double S1; 
  double buy; 
  
  R1 = Y - low; 
  S1 = Y - high;
  buy = Y-close; 
  
  
  
  return 0;
  
  
}
