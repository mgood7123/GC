#include "gc.h"

void foo(void) {
	char * a = malloc(1);
	printf("%p\n", a);
}

void tgc_start2(tgc_t *gc, void *stk) {
  gc->bottom = stk;
  gc->paused = 0;
  gc->nitems = 0;
  gc->nslots = 0;
  gc->mitems = 0;
  gc->nfrees = 0;
  gc->maxptr = 0;
  gc->items = NULL;
  gc->frees = NULL;
  gc->minptr = UINTPTR_MAX;
  gc->loadfactor = 0.9;
  gc->sweepfactor = 0.5;
}


int main(void)
{
	Garbage_Collector_Shutdown();
	int a;
	//tgc_start2(&Garbage_Collector_Program, &a);
	for (int i = 0, i < 1, i++) {
		foo();
	}
	printf("I AM IN MAIN, THIS SHOULD BE PRINTING\n");
	Garbage_Collector_Dump_Mem(stdout);
	Garbage_Collector_Shutdown();
	return 0;
}
