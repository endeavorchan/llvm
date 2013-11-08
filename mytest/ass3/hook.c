#include <stdio.h>
#include <malloc.h>
#include <stdint.h>
#include <inttypes.h>

static int64_t counter  = 0 ;

void malloc_hook(void *p,int64_t num) {
	printf("The memory is %p\n", p);
	printf("The number is %ld\n",num);
	counter += num;
}


void free_hook(void *p) {
	printf("The memory is %p\n", p);
	int64_t mem_size = malloc_usable_size(p);
	printf("Deallocating %zd\n",malloc_usable_size(p));
	printf("%" PRId64 "\n", mem_size);
	counter -= mem_size;
}
