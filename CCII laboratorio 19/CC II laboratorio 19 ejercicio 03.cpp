/*3. Utilizando Functores y el método std::sort, elabore una clase Elementos con dos
atributos de números enteros a y b. Genere una lista de 20 elementos de esta clase
Elementos con valores aleatorios tanto para a y b. Mediante el método std::sort
ordénelos de la forma en que un Objeto al ser comparado con un segundo se tenga
la desigualdad : obj1.a < obj2.b . El método std::sort debe de trabajar con un
objeto Functores. De ser necesario, investigue como realizar este procedimiento
que dependa de un objeto del tipo Functores.*/
/*Apellidos y Nombres: Zhong Callasi, Linghai Joaquin*/
#include <iostream>
#include<cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;
class Elementos{
public:
	int a;
	int b;
	void operator()(Elementos &m, Elementos &n){
		int numero1=m.a;
		int numero2=n.b;
		vector<int> menorAmayorB;
		menorAmayorB.push_back(numero1);
		menorAmayorB.push_back(numero2);
		sort(menorAmayorB.begin(),menorAmayorB.end());
		m.asignarAtributos(menorAmayorB[0],m.b);
		n.asignarAtributos(n.a,menorAmayorB[1]);
	}
	void asignarAtributos(int x, int y){
		a=x;
		b=y;
	}
	void imprimirAtributos(){
		cout<<"{"<<a<<", "<<b<<"}";
	}
};
int main(int argc, char *argv[]) {
	srand(time(0));
	vector<Elementos> ElementosLista(20);
	int t=ElementosLista.size();
	for (int j=0;j<t;j++){
		int val1=rand()%1000; /*Se le coloca "%1000" para darle un rango de números de entre 0 a 999 solo por darle un rango.*/
		int val2=rand()%1000;
		ElementosLista[j].asignarAtributos(val1,val2);
	}
	cout<<"Lista inicial: "<<endl;
	for (int i=0;i<t;i++){
		if (t==1){
			ElementosLista[i].imprimirAtributos();
		}
		else if (i==0){
			cout<<"{";
			ElementosLista[i].imprimirAtributos();
		}
		else if (i==(t-1)){
			ElementosLista[i].imprimirAtributos();
			cout<<"}";
		}
		else{
			ElementosLista[i].imprimirAtributos();
			cout<<", ";
		}
	}
	int total=(t-1);
	while (total>0){
		Elementos functAplic;
		for (int s=0;s<total;s++){
			ElementosLista[s](ElementosLista[s],ElementosLista[s+1]);
		}
		total--;
	}
	cout<<endl<<"Lista con el orden requerido: "<<endl;
	for (int i=0;i<t;i++){
		if (t==1){
			ElementosLista[i].imprimirAtributos();
		}
		else if (i==0){
			cout<<"{";
			ElementosLista[i].imprimirAtributos();
		}
		else if (i==(t-1)){
			ElementosLista[i].imprimirAtributos();
			cout<<"}";
		}
		else{
			ElementosLista[i].imprimirAtributos();
			cout<<", ";
		}
	}
	return 0;
}

