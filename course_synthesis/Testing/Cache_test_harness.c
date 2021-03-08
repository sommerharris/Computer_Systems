#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> 
#include <unistd.h>
#include "Cache.h"

clock_t start, end;
double cpu_time_used;

void* task1(){
          for ( int i = 0; i < 1; i++){	
            printf("Running task1: %d\n", i);
            cache_t* cache = implementCache(10);
            put(cache, 5, 1);
            put(cache, 6, 2);
            printCache(cache);
            freeCache(cache);
          }
          return NULL;
}

void* task2(){
          for ( int i = 0; i < 1; i++){	
            printf("Running task2: %d\n", i);
            cache_t* cache = implementCache(10);
            put(cache, 5, 1);
            put(cache, 6, 2);
            printCache(cache);
            freeCache(cache);
          }
          return NULL;
}


int main(){
    //clock
    start = clock();
    //thread IDs
    pthread_t threadIDs[2];

    pthread_create(&threadIDs[0], NULL, task1, NULL);
    pthread_create(&threadIDs[1], NULL, task2, NULL);
    
    pthread_join(threadIDs[0], NULL);
    pthread_join(threadIDs[1], NULL);
    //clock end
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%f\n", cpu_time_used);
    return 0;
}	
