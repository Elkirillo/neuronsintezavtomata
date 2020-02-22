#pragma once 

class neuron 
{
	private:
		int weights[4];
		int activation=0;
		int error;
		int indata[8][4] {{0,0,0,0},{0,0,0,1},{0,1,0,0},{0,1,0,1},{0,1,1,0},{1,0,0,1},{1,0,1,0},{1,0,1,1}};
		int delt=0;
	public:	
		//метод заполнения весами 
		void fullweight ();	
		//метод активации
		void activ(int n);
		//метод подсчета отклонения
		void deviation(int expect);
		//метод обучения весов с помощью модели "Хебба"
		void foo4 (int expct,int n);
		//функция вывода весов
		void show();
};
