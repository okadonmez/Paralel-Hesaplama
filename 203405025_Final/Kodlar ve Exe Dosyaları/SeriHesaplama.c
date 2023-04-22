#include <stdio.h>

#define fonksiyon_parca_sayisi 16

float x[fonksiyon_parca_sayisi] = {0.2, 0.4, 0.6, 0.8,
		       						 1, 1.2, 1.4, 1.6, 
		     					   1.8, 2, 2.2, 2.4, 
		     					   2.6, 2.8, 3, 3.2};
float fx[fonksiyon_parca_sayisi] = {};
float a[fonksiyon_parca_sayisi] = {0.67, 1.24, 2.10, 3.39, 
		     					   5.25, 7.83, 11.28, 15.74, 
		    					  21.35, 28.25, 36.59, 46.52,
		    					  58.18, 71.71, 87.25, 104.95};
float b[fonksiyon_parca_sayisi+1] = {};
float c[fonksiyon_parca_sayisi+1] = {};
float d[fonksiyon_parca_sayisi+1] = {};
float h[fonksiyon_parca_sayisi+1] = {};
float alfa[fonksiyon_parca_sayisi+1] = {};
float l[fonksiyon_parca_sayisi+1] = {};
float u[fonksiyon_parca_sayisi+1] = {};
float z[fonksiyon_parca_sayisi+1] = {};

void main(){
	
	int i;

	//1. Kisim
	for(i=0; i<fonksiyon_parca_sayisi-1; i++){

		h[i] = x[i+1] - x[i];
		
		printf("h%d: %.1f,   x%d----%.1f----x%d,   x0----%.1f----x%d\n",i,h[i],i,x[i]-x[i-1],i+1,x[i],i+1);
	}
	
	//2. Kisim
	for(i=1; i<fonksiyon_parca_sayisi-1; i++){
		
		alfa[i] = ((3/h[i])*(a[i+1]-a[i])) - ((3/h[i-1])*(a[i]-a[i-1]));
	}
	
	//3. Kisim
	l[0] = 1.0;
	u[0] = 0.0;
	z[0] = 0.0;
	
	//4. Kisim
	for(i=1; i<fonksiyon_parca_sayisi-1; i++){
		
		l[i] = (2*(x[i+1]-x[i-1])) - (h[i-1]*u[i-1]);
		u[i] = h[i] / l[i];
		z[i] = (alfa[i]-h[i-1]*z[i-1]) / l[i];
	}
	
	//5. Kisim
	l[fonksiyon_parca_sayisi] = 1.0;
	z[fonksiyon_parca_sayisi] = 0.0;
	c[fonksiyon_parca_sayisi] = 0.0;
	
	//6. Kisim
	for(i=fonksiyon_parca_sayisi-1; i>-1; i--){
		
		c[i] = z[i] - (u[i]*c[i+1]);
		b[i] = ((a[i+1]-a[i]) / h[i]) - ((h[i]*(c[i+1]+(2*c[i]))) / 3);
		d[i] = (c[i+1]-c[i]) / (3*h[i]);
	}
	
	//7. Kisim
	for(i=0; i<fonksiyon_parca_sayisi-1; i++){
		
		fx[i] = a[i] + b[i]*(x[i]-x[i]) + c[i]*(x[i]-x[i])*(x[i]-x[i]) + d[i]*(x[i]-x[i])*(x[i]-x[i])*(x[i]-x[i]);	
		
		printf("\ni= %d --> a: %.2f,  b: %.2f,  c: %.2f,  d: %.2f  f(%.1f)= %.2f",i,a[i],b[i],c[i],d[i],x[i],fx[i]);	
	}
}
