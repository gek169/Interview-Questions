#!/usr/local/bin/tcc -run -b
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char** argv){
	if(argc < 2){
		puts("usage: ./fizzbuzz.c [iterations]");
		return 1;
	}

	{
	unsigned long i;
	unsigned long n_iterations = strtoul(argv[1],0,0);
		if(n_iterations < 1){
			puts("[You entered a number less than one, so this does not run!]");
		}
		for(i=1; i <= n_iterations; i++){
			if(i%15 == 0) {puts("fizzbuzz"); continue;}
			if(i%3 == 0) {puts("fizz"); continue;}
			if(i%5 == 0) {puts("buzz"); continue;}
			printf("%lu\n", i);
		}
	}
	return 0;
}
