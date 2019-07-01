#define acc Accumulator
#define ic instructionCounter
#define ir instructionRegister
#define oc operationCode
#define op operand
#include<stdio.h>
void smlExe(char file[],int size)
{
    int Accumulator = 0;
    int instructionCounter = 0;
    int instructionRegister = 0;
    int operationCode = 0;
    int operand = 0;
    int memory[size];
    FILE *fp;
    fp = fopen(file,"r");
    printf("\n... LOADING PROGRAM ...\n"); 
    for(int i = 0;(fscanf(fp,"%d",&memory[i])) != EOF && i < size;i++)
    {
	fscanf(fp,"%d",&memory[i]);
    }
    printf("\n****PROGRAM LOADING DONE****\n");
    printf("\n****EXECUTING PROGRAM****\n");
    while(1)
    {
        ir = memory[ic++];
	oc = ir / 100;
	op = ir % 100;
	switch(oc)
	{
	    case 10: 
	        //printf("INPUT A NUMBER\n** NUMBER SHOULD NOT EXCEED FOUR DIGITS OTHERWISE IT WILL BE CROPPED **\n");
		printf("\n\t ? ");	    	
		scanf("%d",&memory[op]);
	    	while(memory[op] < -9999 || memory[op] > 9999)
		    memory[op] /= 10;
	    	break;
	    case 11:
	    	printf("\n\t = %d\n",memory[op]);
	    	break;
	    case 20:
	    	acc = memory[op];
	    	break;
	    case 21:
	    	memory[op] = acc;
	    	while(memory[op] < -9999 || memory[op] > 9999)
	            memory[op] /= 10;
	    	break;
	    case 30:
	    	acc += memory[op];
	    	break;
	    case 31:
	    	acc -= memory[op];
	    	break;
	    case 32:
	    	if(acc != 0)
	    	{
	            acc = memory[op] / acc;
	    	}
	    	else
	    	{
		    printf("\n****OOPS!!!!****\n****TRYING TO DIVIDE BY ZERO****\n");
		    return;
	    	}
	    case 33:
	    	acc *= memory[op];
	    	break;
	    case 40:
	    	ic = op;
	    	break;
	    case 41:
	    	if(acc < 0)
		    ic = op;
	    	break;
	    case 42:
	    	if(acc == 0)
		    ic = op;
	    	break;
	    case 43:
	    	return;
	    default:
	    	printf("\nInvalid operation code\n");
	    	return;
	}
    }
}
