#include <iostream>
#include <omp.h>
#include <chrono>

using namespace std;

#define THREAD_SAYISI 6
#define ELEMAN_SAYISI 5

int main(){
   
   auto start = chrono::system_clock::now();

   float h, x, alan, a=0, b=6;
   int bolum, n=5000, tid;
   
   h = (b-a)/n;
  
   #pragma omp parallel shared(alan) num_threads(THREAD_SAYISI)
   {
      tid = omp_get_thread_num();
      printf("Thread %d\n",tid);
      
      #pragma omp for schedule(static,ELEMAN_SAYISI)
      for(bolum=a; bolum<n; bolum++){
   	 
         x = a + bolum * h;
         alan = alan + ((-3*x*x)+(x));
      
         printf("%d-%d. Bolum   x: %f   Alan: %f\n", bolum, bolum+1, x, alan);
      
      }
   }
   
   alan = h * (((-3*b*b)+(b))/2+alan+((-3*a*a)+(a))/2);
   
   printf("\n%f\n", alan);
   
   
   auto end = chrono::system_clock::now();
   auto elapsed = end - start;
   cout << elapsed.count() << '\n';
   
   return 0;
}
