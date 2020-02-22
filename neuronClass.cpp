#include "neuronClass.h"
#include <iostream>
using std::cout;
using std::endl;

void neuron::fullweight ()
{
	for (int i=0; i<4; i++)
	{
		weights[i] = 0;
		cout << weights[i] << endl;
	}	
}

void neuron::activ(int n)
{
	activation=0;
	for (int i=0;i<4; i++)
			activation=activation+weights[i]*indata[n][i];
	cout << "the first result= "<<activation << endl;
}


void neuron::deviation(int expect)
{
	if ((activation-expect)!=0)
		error= abs(activation - expect);

}

void neuron::foo4 (int expct,int n) 
{
	int num=0;
	while (activation!=expct)
	{
		activation=0;
		for (int i=0;i<4;i++)
		{
			if (weights[i]==0)
				weights[i]=weights[i]+indata[n][i]*expct;
			activation=activation+weights[i]*indata[n][i];
			num=weights[i]*indata[n][i]+weights[i+1]*indata[n][i+1];
			if (activation > expct)
			{
				while (activation != expct)
				{
					int numb = 0;
					weights[i]=weights[i]-1;
					for (int i=0;i<4;i++)
						numb=numb+weights[i]*indata[n][i];
					activation=numb;
					}
			}
			if (i!=3)
			{
				for (int j=i+1; j<4; j++)
				{
					num=weights[i]*indata[n][i]+weights[j]*indata[n][j];
					if (num > expct)
							weights[i]=abs(weights[i]-1);
				}	
				cout<<weights[i] << endl;
			}
		}
	}
}

void neuron::show() 
{
	for (int i=0;i<4;i++)
		cout << "weights" << i << "=" <<weights[i]<< endl;
	cout<< "res= " << activation<< endl;
}

