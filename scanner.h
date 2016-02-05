#ifndef SCANNER_H_
#define SCANNER_H_
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