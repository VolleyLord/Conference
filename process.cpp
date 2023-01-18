#include "processing.h"
#include <iostream>
using namespace std;

int process(conf_prog* array[], int size, int big)
{
	int ds = 0;
	for (int i = 0; i < size; i++) {		
		if (array[i]->finish.min - array[i]->start.min > ds)
			ds = (array[i]->finish.min - array[i]->start.min);
		big = ds;
	}

	return big;
}
int processe(conf_prog* array[], int size)
{
	int res = 0;
	int big = 0;
	

		for (int i = 0; i < size; i++) {
			if (array[i]->finish.min - array[i]->start.min > big) {
				big = array[i]->finish.min - array[i]->start.min;
				res = big;
			}
		}
		
	return res;
}