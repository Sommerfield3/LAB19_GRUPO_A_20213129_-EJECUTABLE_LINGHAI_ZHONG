/*1. Utilizando Functores, elabore una clase que calcule la ecuación de regresión lineal
simple (y = a + bc) de un conjunto de pares de datos (x, y) almacenados en un
vector, retorne como parte del resultado los valores de a y b. Apóyese en functores
para calcular las diferentes sumatorias que pueden presentarse.*/
/*Apellidos y Nombres: Zhong Callasi, Linghai Joaquin*/
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
class RegresionLinealSimple{
private:
	vector<float> x;
	vector<float> y;
	vector<float> xy;
	vector<float> xpow2;
	float sumatoriaX;
	float sumatoriaY;
	float sumatoriaXY;
	float sumatoriaXpow2;
public:
	float operator()(vector<float> a){
		float sumatoria=0;
		int tam1=a.size();
		for (int i=0;i<tam1;i++){
			sumatoria+=a[i];
		}
		return sumatoria;
	}
	void valores(vector<vector<float>> paresOrdenados){
		x.clear();
		y.clear();
		xy.clear();
		xpow2.clear();
		int tamVector=paresOrdenados.size();
		for (int i=0;i<tamVector;i++){
			x.push_back(paresOrdenados[i][0]);
			y.push_back(paresOrdenados[i][1]);
			xy.push_back(x[i]*y[i]);
			xpow2.push_back(x[i]*x[i]);
		}
		RegresionLinealSimple operac;/*Usando functores para las sumatorias.*/
		sumatoriaX=operac(x);
		sumatoriaY=operac(y);
		sumatoriaXY=operac(xy);
		sumatoriaXpow2=operac(xpow2);
	}
	tuple<float,float> regresionSimple(vector<vector<float>> paresOrdenados){
		int n=paresOrdenados.size();
		this->valores(paresOrdenados);
		float a;
		float b;
		b=((n*sumatoriaXY)-(sumatoriaX*sumatoriaY))/((n*sumatoriaXpow2)-((sumatoriaX)*(sumatoriaX)));
		a=(sumatoriaY/n)-(b*(sumatoriaX/n));
		return make_tuple(a,b);
	}
};
int main(int argc, char *argv[]) {
	tuple<float,float> resultado;
	RegresionLinealSimple Regresion;
	vector<vector<float>> paresOrdenados{{1,2},{2,3},{2,4},{3,4},{4,4},{4,6},{5,5},{6,7}};
	resultado=Regresion.regresionSimple(paresOrdenados);
	cout<<"Para la lista de pares ordenados: {";
	int tam=paresOrdenados.size();
	for (int i=0;i<tam;i++){
		if (tam==1){
			cout<<paresOrdenados[i][0]<<", "<<paresOrdenados[i][1];
		}
		else if (i==(tam-1)){
			cout<<"{"<<paresOrdenados[i][0]<<", "<<paresOrdenados[i][1]<<"}";
		}
		else{
			cout<<"{"<<paresOrdenados[i][0]<<", "<<paresOrdenados[i][1]<<"}, ";
		}
	}
	cout<<"}"<<endl;
	cout<<"Valores de su ecuación de regresión lineal simple (y=a+bx): "<<endl<<endl;
	cout<<"Valor de 'a': "<<get<0>(resultado)<<endl;
	cout<<"Valor de 'b': "<<get<1>(resultado);
	return 0;
}

