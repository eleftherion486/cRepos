/*	Andy Eleftherion
	Lab4 task2
	9-28-15
*/
#include "scanner2.h"
#include "scanner2.c"
#include <stdio.h>

int main(int argc, char *argv[]){

	char **trans_table;
	FILE *trans_in_file = fopen(argv[1], "r");

	if (trans_in_file == NULL)
	  return(-1);

	scan_init(trans_in_file, &trans_table);

	int not_end = 0;
	while (not_end)
	  display_token(scan(trans_table));
}