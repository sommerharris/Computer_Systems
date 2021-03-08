#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Cache.c"

clock_t start, end;
double cpu_time_used;

int main(){
start = clock();
cache_t* cache = implementCache(10);

put(cache, 5, 1);
put(cache, 6, 2);
get(cache, 5);
get(cache, 6);
get(cache, 7);
get(cache, 8);
get(cache, 5);
printCache(cache);

freeCache(cache);
end = clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("%f\n", cpu_time_used);
return 0;
}	