#include <stdio.h>
#include <stdlib.h>
#include "Cache.h"

int main(){
cache_t* cache = implementCache(10);

put(cache, 5, 1);
put(cache, 6, 2);

get(cache, 5);
printCache(cache);

freeCache(cache);
return 0;
}	
