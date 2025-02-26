#include <stdio.h>

#include "genericList.c"

void funcFree(void * data){
	free(data);
}

int main(){
	int *val = malloc(sizeof(int));
	funcFree(val);




	printf("\nyay");
}