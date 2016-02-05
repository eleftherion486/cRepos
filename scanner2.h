#include <stdio.h>
#ifndef SCANNER2_H_
#define SCANNER2_H_																						  7
char *token_names[] = {"identifier", "number", "printStmp","repeatStmt","assignStmt","lparen","rparen","addOp","multOp","semicolon"};
typedef enum {ID,NUMBER, PRINT, REPEAT, ASSIGN, LPAREN, RPAREN, ADDOP, MULTOP, SEMICOLON } TOKEN_TYPE;

typedef struct token {
	TOKEN_TYPE type;
 	union {
 		char *name;
 		double value;
 	} attributes;
} TOKEN;

TOKEN returnToken;
TOKEN nullToken;
char character;
char charArray[20];

#endif

extern TOKEN* parseToken();
extern void scan_init(FILE (*trans_in_file), char ***trans_table);
extern TOKEN scan(char **trans_table);
extern void display_token(TOKEN displayToken);