#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


class neuron {
	private:
	int weights[4];
	int activation=0;
	int error;
	int indata[8][4] {{0,0,0,0},{0,0,0,1},{0,1,0,0},{0,1,0,1},{0,1,1,0},{1,0,0,1},{1,0,1,0},{1,0,1,1}};
	int delt=0;
	public:
	

	
	//функция заполнения весами
	void fullweight (){
		for (int i=0; i<4; i++){
		weights[i] = 0;
		cout << weights[i] << endl;
		}
		
		}
		
	// функция активации 
	void activ(int n){
		activation=0;
		for (int i=0;i<4; i++)
		activation=activation+weights[i]*indata[n][i];
		cout << "the first result= "<<activation << endl;
	}
	
	
	//error
	void err(int expect){
		if ((activation-expect)!=0)
		error= abs(activation - expect);
		
	}
	

	//обновленные веса c помощью обучения Хебба 
	void foo4 (int expct,int n) {
	int num=0;
		while (activation!=expct){
		activation=0;
		for (int i=0;i<4;i++){
			if (weights[i]==0)
			weights[i]=weights[i]+indata[n][i]*expct;
			activation=activation+weights[i]*indata[n][i];
			
			num=weights[i]*indata[n][i]+weights[i+1]*indata[n][i+1];
			
			if (activation > expct){
			while (activation != expct){
				 int numb = 0;
				weights[i]=weights[i]-1;
				for (int i=0;i<4;i++){
				numb=numb+weights[i]*indata[n][i];
				}
			activation=numb;
			}
		}
		if (i!=3){
		for (int j=i+1; j<4; j++){
			num=weights[i]*indata[n][i]+weights[j]*indata[n][j];
			if (num > expct)
			weights[i]=abs(weights[i]-1);
		}
		
			
			cout<<weights[i] << endl;
		}
	}
		
	
		
	}
}
	void show() {
		for (int i=0;i<4;i++)
			cout << "weights" << i << "=" <<weights[i]<< endl;
			cout<< "res= " << activation<< endl;
	}
	
		
	
	
};







int main (){
	neuron my;
	my.fullweight();
	my.activ(1);
	my.err(1);
	my.foo4(1,1);
	my.show();
	
	my.activ(2);
	my.err(3);
	my.foo4(3,2);
	my.show();

	my.activ(3);
	my.err(4);
	my.foo4(4,3);
	my.show();
	
	my.activ(3);
	my.err(4);
	my.foo4(4,3);
	my.show();
	
	my.activ(4);
	my.err(5);
	my.foo4(5,4);
	my.show();
	
	my.activ(5);
	my.err(6);
	my.foo4(6,5);
	my.show();


	return 0;
	
}
