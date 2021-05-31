#!/usr/local/bin/tcc -run -b
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long *list = NULL;
int *num_successors = NULL;
int *list_nexts = NULL;
int n_elem = 0;
int most_successors = 0;

int main(int argc, char** argv){
	if(argc < 2){
		puts("Usage: ./lis 3 7 9 2 1 3");
		puts("the largest increasing subsequence will be displayed.");
		return 1;
	}
	n_elem = argc -1;
	/*allocate lists.*/
	list = 				calloc(1, sizeof(long long) * n_elem);
	num_successors = 	calloc(1, sizeof(int) * n_elem);
	list_nexts = 		calloc(1, sizeof(int) * n_elem);
	if(!list || !num_successors || !list_nexts){
		puts("Malloc failed.");
		return 1;
	}
	{int i;for(i=0; i < n_elem; i++){
		list[i] = strtoll(argv[i+1], NULL, 0);
	}}

	/*find longest increasing subsequence for all elements.*/
	{int i;
		for(i=n_elem-1; i >= 0; i--){ /*For this starting node...*/
			int j; 
			/*We calloc'd, but I like to be explicit.*/
			list_nexts[i] = 0; num_successors[i] = 0;
			for(j=i+1; j < n_elem; j++){ /*Check all nodes following this one.*/
				if(list[j] > list[i] && /*j'th element is a valid successor.*/
					num_successors[i] <= num_successors[j]){ /*j'th element has a longer series of successors than our current successor.*/
						list_nexts[i] = j; /*Assign successor index.*/
						num_successors[i] = 1 + num_successors[j]; /*Makes sense, right?*/
					}
			}
			if(num_successors[i] > num_successors[most_successors]){
				most_successors = i;
			}
		}
	}
	printf("\n%d elements, the longest increasing subsequence is:\n", n_elem);
	{int i;
		for(i = most_successors;;){
			printf("\n%lld", list[i]);
			i = list_nexts[i];
			if(i == 0) break; /*End of program.*/
		}
	}
	puts("End of list!");
	free(list);
	free(list_nexts);
	free(num_successors);
	return 0;
}
