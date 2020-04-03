#include <iostream>
using namespace std;

class option{
    public: 
    double delta; 
    double vega; 
    
    virtual void display(){ 
        cout<<"option";
    }
    
};

class underlying: public option{
	public:
		
};

class stock: public underlying {
	public:
		void display() {
			cout << "\nstock";
		}
};

class bond: public underlying {
	public:
		void display() {
			cout << "\nbond";
		}
};

int main() {
	stock apple, microsoft;
	bond german10, fed10; 
	
	option o; 

	option *o1 = &apple;
	option *o2 = &microsoft; 
	option *o3 = &german10; 
	option *o4 = &fed10;

	o1->display(); 
	o2->display();
	o3->display();
	o4->display();
	
	
	
	
}
