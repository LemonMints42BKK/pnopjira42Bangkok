#include <iostream>
#include <typeinfo>
#include <exception>

class Parent {public: virtual ~Parent(void){}};
class Child1: public Parent {};
class Child2: public Parent {};

int main (void){
	Child1 a;		//Referance valued
	Parent *b = &a;	//Implicit upcast -> OK

	//Explicit downcast -> suspense -> OK!
	Child1 * c = dynamic_cast<Child1 *>(b);
	if(c == NULL){
		std::cout << "Conversion is NOT OK!" << std::endl;
	} else {
		std::cout << "Conversion is OK!" << std::endl;
	}

	//Explicit downcast -> suspense -> NOT OK!
	try{
		Child2 & d = dynamic_cast<Child2 &>(*b);
		std::cout << "Conversion is OK!" << std::endl;
		(void)d;
	} catch (std::bad_cast &bc){
		std::cout << "Conversion is NOT OK! " << bc.what() << std::endl;
		return 0;
	}
	return (0);
}