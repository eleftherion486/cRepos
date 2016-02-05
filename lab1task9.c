/**
* Name: Andy Eleftherion
* Lab/task: Lab 1 Task 9
* Date: 08-31-15
**/
#include <stdio.h>

typedef union message_content // allows for interpretation
{
	char _254_chars[254];
	unsigned short _127_shorts[127];
	struct // see a struct
	{
		char name[32];
		time_t creat_t;
		unsigned short size;
		unsigned short inode_ref;
	} fd;
} MESSAGE_CONTENT;

typedef struct message
{
	unsigned short message_type; // how to read the message
	MESSAGE_CONTENT message; // 254 bytes of some content
} MESSAGE; // 256 bytes in total

MESSAGE message_buffer[1024];
