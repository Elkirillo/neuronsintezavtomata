#include "neuronClass.h"

int main (){
	neuron my;
	my.fullweight();
	my.activ(1);
	my.deviation(1);
	my.foo4(1,1);
	my.show();
	
	my.activ(2);
	my.deviation(3);
	my.foo4(3,2);
	my.show();

	my.activ(3);
	my.deviation(4);
	my.foo4(4,3);
	my.show();
	
	my.activ(3);
	my.deviation(4);
	my.foo4(4,3);
	my.show();
	
	my.activ(4);
	my.deviation(5);
	my.foo4(5,4);
	my.show();
	
	my.activ(5);
	my.deviation(6);
	my.foo4(6,5);
	my.show();
	
	return 0;
}
