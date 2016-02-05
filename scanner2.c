/*	receives a string and determines
	token type and creates token
	and returns pointer to token
*/
#include "scanner2.h"
#include <stdio.h>



TOKEN* parseToken(){
  character = '\0';
	scanf(" %c", &character);
	returnToken = nullToken;
	switch (character) {
    case '\0':
      returnToken.type = -1;
      break;
		case 'a'...'z':
			ungetc(character, stdin);	//put first char back in stream
			scanf(" %19[a-zA-Z]", charArray);

			if(!strcmp(charArray, "repeat")){
				returnToken.type = REPEAT;
			}
			else if(!strcmp(charArray, "print")){
				returnToken.type = PRINT;
			}
			else{
				returnToken.type = ID;
			}
			returnToken.attributes.name = charArray;
  			break;
 		case '0'...'9':
 			returnToken.type = NUMBER;
 			ungetc(character, stdin);
 			scanf(" %lf", &returnToken.attributes.value);
  			break;
  		case '=':
  			returnToken.type = ASSIGN;
  			returnToken.attributes.name = "";
  			break;
  		case ';':
  			returnToken.type = SEMICOLON;
  			returnToken.attributes.name = "";
  			break;
  		case '(':
  			returnToken.type = LPAREN;
  			returnToken.attributes.name = "";
  			break;
  		case ')':
  			returnToken.type = RPAREN;
  			returnToken.attributes.name = "";
  			break;
  		case '+':
  		case '-':
  			returnToken.type = ADDOP;
  			returnToken.attributes.name = &character;
  			break;
  		case '*':
  		case '%':
  		case '/':
  			returnToken.type = MULTOP;
  			returnToken.attributes.name = &character;
  			break;
 		default:
 			break;
	}
	return &returnToken;
}



void scan_init(FILE (*trans_in_file), char ***trans_table){



}

TOKEN scan(char **trans_table){

}

void display_token(TOKEN displayToken){

}