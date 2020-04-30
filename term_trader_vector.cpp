#include<algorithm> 
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


class algortrade{
    public:
       
       int today;
       int tradeid;

       void algotrade();
       void trade(int x);
       void enter_buy(int t);
       void close_buy(int id, int t); 

       vector<int> ifopen;
       vector<int> entertime; 

       vector<double> entervalue;
       vector<double> volume;

       vector<int> closetime
       vector<doube> closevalue; 
       vector<double> profit; 


     

} 

void algotrade::algotrade(){
     tradeid=0;
}


void algotrade::trade(int x)
{
today=x;

//buyconditions example
if(FEED[today]-FEED[today-1]<0)
{
   enter_buy(today);
}


for(int i=0;i<=tradeid; i++)
{
   if(ifopen(i)==1){
      //enter conditions
       close_buy(int tradeid, int today);
     } 


}


}





int main()
{

const int SIZE = 50;

algotrade u;

for(int i=1;i<=SIZE; i++)
     u.trade(i);

return 0;
}
