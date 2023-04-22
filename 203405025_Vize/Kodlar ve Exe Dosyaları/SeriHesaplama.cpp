#include <iostream>
#include <chrono>

using namespace std;

int main(){
   
   auto start = chrono::system_clock::now();
 
   float h, x, alan, a=0, b=6, n=5000;
   int bolum;
   
   h = (b-a)/n;
   
   for(bolum=a; bolum<n; bolum++){
   
      x = a + bolum * h;
      alan = alan + ((-3*x*x)+(x));
      
      printf("%d-%d. Bolum   x: %f   Alan: %f\n", bolum, bolum+1, x, alan);
   }

   alan = h * (((-3*b*b)+(b))/2+alan+((-3*a*a)+(a))/2);
   
   printf("\n%f\n", alan);

   auto end = chrono::system_clock::now();
   auto elapsed = end - start;
   cout << elapsed.count() << '\n';
   
   return 0;
}
