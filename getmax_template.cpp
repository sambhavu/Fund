#include <iostream>
#include <iomanip>
using namespace std;

template<class T> 
class mypair { 
    T a, b ;
    
    public: 
    mypair( T one, T two){
      a = one; 
      b = two; 
    } 
    
    T getmax();     
};          //end of template class declaration 

template <class T> 
T mypair<T>::getmax()
{
    if(a>b){
        return a; 
    }
    else{
        return b; 
    }
}




int main()
{

    mypair<double> numbers(100,200); 
    mypair<int> numbers2(1,3); 
    mypair<float> numbers3(4123.416,164.15); 
    
    cout<<numbers.getmax() << "\n"; 
    cout<<numbers2.getmax() << "\n";
    cout<<numbers3.getmax() << "\n";
    
    return 0;
}
