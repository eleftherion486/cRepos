#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Andy Eleftherion

void usageDisplay(){
	printf("Usage: sub fromChar toChar srcFile destFile\n");
	exit(0);
}

int main(int argc, char *argv[])
{
	FILE *input;
	FILE *output;
	int outputFileNum = 0;
	char *fromChar = malloc(1);
	char *toChar = malloc(1);
	int i = 1;
	if (argc < 3)
		usageDisplay();
	fromChar = argv[i];
	i++;
	toChar = argv[i];
	i++;

	while( i <= argc - 1){
		if(strcmp(argv[i], "-f")==0){
			if (argv[i+1] == NULL)
				usageDisplay();
			else{
				input = freopen(argv[i+1], "r", stdin);
				if (input == NULL){
					fprintf(stderr, "File doesn't exist\n");
					exit(0);
				}
				i++;
			}
		}
		else if(strcmp(argv[i], "-o")==0){
			if (argv[i+1] == NULL)
				usageDisplay();
			else{
				outputFileNum = i+1;
				i++;
			}
		}
		else{
			usageDisplay();
		}
		i++;
	}

	if (outputFileNum > 0){
		output = freopen(argv[outputFileNum], "w", stdout);
		if (output == NULL){
			fprintf(stderr, "Can not create file\n");
			exit(0);
		}
	}

	if (input != stdin)
		input = stdin;

	char next;
	while((next = fgetc(input)) != '\n' && feof(input) == 0)
	{
		if (next == *fromChar)
			next = *toChar;
		printf("%c", next);
	}

	return 0;
}