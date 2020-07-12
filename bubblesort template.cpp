#include <iostream> 
#include <iomanip> 

using namespace std; 


template<class T>
void bubblesort(T arr[], int n)
{
    for(int i = 0; i < n-1; i++)
        for(int j = n-1; i<j; j--)
            if(arr[j] < arr[j-1])
                swap(arr[j], arr[j-1]); 
} 




int main() 
{
    int arr[10] = { 5, 3,6,2,8,2,4,7, 7,3};
    int n = sizeof(arr) / sizeof(arr[0]); 
    
    bubblesort<int>(arr, 10); 
    
    for(int i = 0; i<n; i++)
        cout<<arr[i]<<"\n";
        
    
    return 0;
} 
