#include <iostream>
#include <string>
#include<vector>
using namespace std; 


vector<double> prices = {
    1203,
    1204,
    1205,
    1202,
    1206,
    1209,
    1208,
}; 


template<typename T>
T position (T today)
{
    if(prices[today] - prices[today-1] < 0)
    {
        return 1;
    }
    else{
        return -1;
    }   
}


int main()
{
    
int size; 
size = prices.size();

double totalprofit = 0; 

for(int i = 2; i<size; ++i)
    totalprofit += (prices[i] - prices[i-1]) * position<int>(i-1);
    
std::cout<<totalprofit;    

return 0;
}
