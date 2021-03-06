#include <math.h>
#include "derivacao-e-integracao.h"
#include "spline.h"

double deriva(struct Spline *spl, float x, double h, int ordem){
	switch (ordem) {
		case 1:
			return (1/(2*h))*(-estimaValor(spl, x - h) + estimaValor(spl, x + h));
			break;
		case 2:
			return (1/pow(h,2))*(estimaValor(spl, x - h) - 2*estimaValor(spl, x) + estimaValor(spl, x + h));
			break;
		default:
			return (1/(2*h))*(-estimaValor(spl, x - h) + estimaValor(spl, x + h));
			
	}
}

double integra(struct Spline *spl, float a, float b, int n){
	int i;
	double h = (b-a)/n;
	double E = 0;
	for (i = 1; i < n; ++i) {
		if (i%2 == 0) {
			E += 2*estimaValor(spl, a+i*h); 
		} else {
			E += 4*estimaValor(spl, a+i*h);       
		}
	}
	return (h/3)*(estimaValor(spl, a) + E + estimaValor(spl, b));
}
