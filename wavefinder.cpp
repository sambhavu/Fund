#include<iostream>
#include<vector>
using namespace std;


vector<double> prices 

vector<double> ma()
{
    
 int size = prices.size();
 vector<double> wave; 
 wave.clear();
 
 double count = 0;
 double value; 
 for(int i = 15; i<size; i++)
 {
     count = 0;
     value = 0;
     for(int j = i-15; j<=i; j++)
     {
         
         value += prices[j];
         count++;
     }
      
    wave.pushback_ack(value/count);
 }
 
 return wave;
    
}


int main()
{
    vector<double> wave; 
    
    wave = ma();
    
    bool found = false; 
    
    double start;
    int up; 
    int size;
    
    int ck;
    int uk;

    double position = 0;
        size = wave.size();
        start = wave.back();
        up = wave[size-1] - wave[size-2];
        
        ck = size-1; 
        uk = size-1;
        
        double max =0;
        double min = 0;
        
        if(up>0){
            while(wave[ck] >start && ck>=0)
            {
                if(wave[ck] > max){
                    max = wave[ck];
                }
                ck--;
            }
            
            if(max == start){
                
        }
        
        else{
            while(wave[uk] <start && uk>=0)
            {
                if(wave[uk] < min){
                    min = wave[uk];
                }
                uk--;
            }
            
            
        }
    
    
    return 0;
}
