#include <iostream>
#include <pthread.h>
#include <chrono>

using namespace std;

void *thread_function(void *dummyPtr);

#define THREAD_SAYISI 6
#define N_DEGERI 5000

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

float h, x, alan, a=0, b=6;
int bolum, n=N_DEGERI, problemBoyutu=N_DEGERI/THREAD_SAYISI, SIMDIKI_THREAD = 0;

int main(){
   
   auto start = chrono::system_clock::now();
   
   int i,j;
   
   pthread_t thread_id[THREAD_SAYISI];

   h = (b-a)/n;
   
   for(i=0; i<THREAD_SAYISI; i++){
      
      pthread_create(&thread_id[i], NULL, thread_function, NULL);
   }

   for(j=0; j<THREAD_SAYISI; j++){
      
      pthread_join(thread_id[j], NULL);
   }
   
   alan = h * (((-3*b*b)+(b))/2+alan+((-3*a*a)+(a))/2);
   
   printf("\n%f\n", alan);
   
   
   auto end = chrono::system_clock::now();
   auto elapsed = end - start;
   cout << elapsed.count() << '\n';
   
   return 0;
}

void *thread_function(void *dummyPtr){
   
   printf("Thread numarasi: %ld\n", pthread_self());
   printf("Simdiki Thread: %d\n", SIMDIKI_THREAD+1);
   
   pthread_mutex_lock(&mutex1);
   
   for(bolum=a+(problemBoyutu*SIMDIKI_THREAD); bolum<(problemBoyutu*(SIMDIKI_THREAD+1)); bolum++){
   
      x = a + bolum * h;
      alan = alan + ((-3*x*x)+(x));
      
      printf("%d-%d. Bolum   x: %f   Alan: %f\n", bolum-(SIMDIKI_THREAD+1),  bolum+1-(SIMDIKI_THREAD+1), x, alan);
   }
   
   SIMDIKI_THREAD++;
   
   pthread_mutex_unlock(&mutex1);
    
   return NULL;
}
