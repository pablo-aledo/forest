/*
 * =====================================================================================
 * /
 * |     Filename:  divzero_offset.c
 * |
 * |  Description:  
 * |
 * |      Version:  1.0
 * |      Created:  08/06/2014 04:12:03 AM
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


int main() {
	int a;
	if(a == 10) return 1;
	int b = 10/(a - 1);
	return 0;
}
