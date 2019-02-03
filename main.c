#include<stdio.h>
int smlVal(char[],int);
void smlExe(char[], int);
void main(int arg,char* args[])
{
    if(smlVal(args[1],100))
    {
	printf("\n****NO SYNTAX ERROR -- CKECKING DONE****\n");
        smlExe(args[1],100);
    }
}
