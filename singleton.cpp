// usage of singleton pattern in programminglanguages, singleton pattern is only used for having only single object of the class

#include <iostream>
using namespace std;
class singleton{
	private static singleton object;
	private singleton();
	public static getInstance(){
		if(!object) object = new singleton();
		else return object;
	}
}

int main(){
	singleton s = getInstance();
	cout<<"data recieved\n";
	return 0;
}