/*
 * =====================================================================================
 * /
 * |     Filename:  overflow.c
 * |
 * |  Description:  
 * |
 * |      Version:  1.0
 * |      Created:  01/04/2014 09:46:48 AM
 * |     Revision:  none
 * |     Compiler:  gcc
 * `-. .--------------------
 *    Y
 *    ,,  ,---,
 *   (_,\/_\_/_\     Author:   Pablo González de Aledo (), pablo.aledo@gmail.com
 *     \.\_/_\_/>    Company:  Universidad de Cantabria
 *     '-'   '-'
 * =====================================================================================
 */

#include <stdio.h>


void my_strcpy(char dest[], const char source[]) {
	int i = 0;
	while (1) {
		dest[i] = source[i];
		if (dest[i] == '\0') break;
		i++;
	}
}

int my_strcmp(char* s1, char* s2)
{
    while(*s1 && (*s1==*s2))
        s1++,s2++;
    return *(unsigned char*)s1-*(unsigned char*)s2;
}

int main(int argc, const char *argv[])
{

	char password_buffer[10];
	int access = 0;
	my_strcpy(password_buffer, argv[1]);

	if(!my_strcmp(password_buffer, "passwd"))
		access = 1;

	if( access )
		printf("\e[32m Access Granted \e[0m\n");
	else 
		printf("\e[31m Access Denied \e[0m\n");

	return 0;
	
}

