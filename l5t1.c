/*	Andy Eleftherion
	Lab4 task1
	9-28-15
*/
#include "scanner.h"
#include "scanner.c"
#include <stdio.h>

int main(int argc, char *argv[]){
	if (argc > 1){
		freopen(argv[1], "r", stdin); 		//get data from filename
	}
	TOKEN *receiveToken = parseToken();
	if (receiveToken->type != EOF){
		printf("{<%s> %s}", token_names[receiveToken->type], receiveToken->attributes.name );
	}
	while(receiveToken->type != EOF){
		receiveToken = parseToken();
		if (receiveToken->type == EOF){
			return 0;
		}
		printf(", ");
		switch(receiveToken->type){
			case 0:
				printf("{<%s> %s}", token_names[receiveToken->type], receiveToken->attributes.name );
				break;
			case 1:
				printf("{<%s> %.0lf}", token_names[receiveToken->type], receiveToken->attributes.value );
				break;
			case 2:
				printf("{<keyword> %s}", receiveToken->attributes.name );
				break;
			case 3:
				printf("{<keyword> %s}", receiveToken->attributes.name );
				break;
			case 4:
				printf("{<assignment>}" );
				break;
			case 5:
				printf("{<lparen>}");
				break;
			case 6:
				printf("{<rparen>}");
				break;
			case 7:
				printf("{<addOp> %s}", receiveToken->attributes.name );
				break;
			case 8:
				printf("{<multOp> %s}", receiveToken->attributes.name );
				break;
			case 9:
				printf("{<semicolon>}" );
				break;
		}
	}
	return 0;
}