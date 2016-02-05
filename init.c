/*  Andy Eleftherion
	C Test
	1-28-16
	I spent way too much time on setup() because I forgot to malloc Settings and kept getting seg fault error.
	Generally, I spent a lot of time trying to remember the proper syntax from memory, having to remember all the syntax in 
	a short amount of time is very unrealistic and does not represent how well someone knows a programming language
	It gets very frustrating spending 5 minutes trying to remember something that I can look up in a few seconds, and takes away
	brain power that can be used to actually solve the problem.


*/
#include "init.h"

/*
	Takes a file pointer and returns a point to a string that contains exactly 1 line from the file.
	Will automatically allocate the appropriate amount of space.
*/

char* getLine(FILE *input)
{
	int size = 0;
	int length = 128;
	char *line = malloc(length);
	char *temp;
	char next;

	while((next = fgetc(input)) != '\n' && feof(input) == 0)
	{
		//expand size
		if(size >= length-1)
		{
			length += 128;
			temp = malloc(length);
			strcpy(temp, line);
			free(line);
			line = temp;
		}

		line[size] = next;
		size++;
	}

	line[size] = 0;

	return line;
}

Node* findNode(char *name, Node *list)
{
	/*
		ADD YOUR CODE HERE
		
		Name will be the name of the node you're looking for.
		Search list for a node with the same name and return a pointer to that node.
		If you cannot find the node return NULL
	*/
		//while ( != NULL){

		//}
	
	return 0;
	
}

void setup(int argc, char *argv[], Settings *set)
{
	/*
		ADD YOUR CODE HERE
		
		Check the arguments from argv, there are 5 possible flags
		-i <input file>		Name of the file you're reading from
		-o <output file>	Name of the file you're writing to, by default overwrite the file
		-a 					If specified append to the end of output file
		-f <frequency>		Number of nodes before you print, if 0 only print after each cycle
		-c <cycles>			Number of times you'll go through all the nodes
		
		Settings.input will contain the file pointer for the input file, defaults to standard input
		Settings.output will contain the file pointer for the output file, defaults to standard out
		Settings.printFrequency will contain how often you print during each cycle, defaults to 9
		Settings.cycles will contain how many cycles your program will execute, defaults to 1
	*/
	int i = 1;
	int append = 0;
	set = malloc(sizeof(Settings));
	char *outputFile;
	int cFlag = 0;
	int oFlag = 0;
	int aFlag = 0;
	int fFlag = 0;
	int iFlag = 0;


	do{
		if((!iFlag) && (strcmp(argv[i],"-i")==0)){
			if (i < argc-1){
				printf("set -i\n");
				set->input = fopen(argv[i+1], "r");
				if (set->input == NULL)
					fprintf(stderr, "File doesn't exist\n");
				else{
					iFlag = 1;
				}
				i++;
			}
		}
		else if((!oFlag) && (strcmp(argv[i],"-o")==0)){
			if (i < argc-1){
				printf("set -o\n");
				//set->output = fopen(argv[i+1], "w");
				outputFile = (char *) malloc(sizeof(argv[i+1]));
				outputFile = argv[i+1];
				oFlag = 1;
				i++;
			}
		}
		else if((!cFlag) && (strcmp(argv[i],"-c")==0)){
			if (i < argc-1){
				printf("set -c\n");
				unsigned short cycle;
				cycle = atoi(argv[i+1]);
				printf("%d\n", cycle);
				if (cycle < 1 )
					fprintf(stderr, "cycles must be greater than 0\n" );
				else
				{
					set->cycles = cycle;
					cFlag = 1;
				}
				//set->cycles = (unsigned short)argv[i+1];
				i++;
			}
		}
		else if((!fFlag) && (strcmp(argv[i],"-f")==0)){
			if (i < argc-1){
				printf("set -f\n");
				unsigned short frequency;
				frequency = atoi(argv[i+1]);
				printf("%d\n", frequency);
				if (frequency < 0 || frequency > 2 )
					fprintf(stderr, "frequency must be 0, 1, or 2 only\n" );
				else
				{
					set->printFrequency = frequency;
					fFlag = 1;
				}
			}
		}
		else if((!aFlag) && (strcmp(argv[i],"-a")==0)){
			printf("set -a\n");
			aFlag = 1;
			append = 1;
		}
		i++;
	} while (i <= argc-1);
	if (oFlag){
		printf("in oFlag\n");
		//((append) && (set->output != NULL)){
		if (append)
			set->output = fopen(outputFile, "a");
		else
			set->output = fopen(outputFile, "w");
		if (set->output == NULL)
			fprintf(stderr, "File doesn't exist\n");
		else{}
	}

}


int loadNodes(FILE *input, Node *list, NodeList *order)
{
	/*
		ADD YOUR CODE HERE
		
		Read the rest of the file
		
		Check the first character of each line and proceed accordingly
		If the first letter == INPUT_CAESAR then create a new node that implement a Caesar Cipher 
			and add it to the node list
		If the first letter == INPUT_REPLACE then create a new node that replaces the specified character
			and add it to the node list
		If the first letter == INPUT_ORDER then check to see if a node with the specified name exists 
			and add it to the end of order
			
		Remember to check:
			You are not beyond the maximum number of nodes
			You get the correct input
			You truncate the name of a node if it is too long
			
		If the input is incorrect print to standard error
	*/
	FILE file;
	char *line;
	line = getLine(&file);
	while (line != 0){
		line = getLine(&file);
	}
	return 0;
}

void runTelephone(char *msg, Settings *set, NodeList *order)
{
	/*
		ADD YOUR CODE HERE
		
		Simulate the game of telephone.
		
		Run for the required number of cycles.
		For each cycle apply the action from each node in the correct order.
		Print out update messages where appropriate.
	*/
		int i;
	for (i = 0; i < set->cycles; i++){
		//apply the actions from the node in the correct order

	}
	
	
}

int main(int argc, char *argv[])
{
	/*
		ADD YOUR CODE HERE
		
		Create you variables.
		
		Use the function setup to get the flags from the command line.
		
		Get the first line of the input, this is your message you're modifying.
		
		Print out the message before modification.
		
		Call runTelephone.
		
		Print out the final message.
	*/
		Settings *settings; 
		setup(argc, argv, settings);
		//char *message = getLine(settings->input);
		//printf("Original message is %s\n", message);

		NodeList *list = (NodeList *) malloc(sizeof( NodeList *));
		//runTelephone(message, settings, list);
		//printf("decoded message is %s\n", message);


	return 0;
}

