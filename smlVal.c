#include<stdio.h>
#include<string.h>
int smlVal(char file[],int size)
{
    int digits = 0;
    int n = size;
    while(n > 0)
    {
	digits++;
	n = n / 10;
    }

    FILE *fp;
    int line = 1;
    char s[80],s1[80];
//    printf("%d",arg);
    if((fp = fopen(file,"r")) == NULL)
    {
	printf("\n****FILE NOT FOUND****\n");
	return 0;
    }
    while(fgets(s,80,fp) != NULL)
    {
	int count = 0;
	char *ins;
	strcpy(s,s1);
        for(ins = strtok(s1," \n\t");ins != NULL; ins = strtok(NULL," \n\t"))
	{
	    count++;
	    if(count == 1)
	    {
	        if(strlen(ins) != digits - 1)
		{
		    printf("\n**SML SYNTAX ERROR**\nLine No. %d Line number must be of %d characters : %s\n",line,digits-1,s);
	            return 0;
		}
	    }
	    if(count == 2)
	    {
	        if(strlen(ins) != 5)
		{
		    printf("\n**SML SYNTAX ERROR**\nLine No. %d Instruction must be of 5 characters: %s\n",line,s);
	            return 0;
		}
	    }
	    if(count > 2)
	    {
	        printf("\n**SML SYNTAX ERROR**\nLine No. %d More than two tokens in one line: %s\n",line,s);
	        return 0;
	    }
	}
	if(s[digits + 5] != '\n')                                                                                                             
	{
	    printf("\n**SML SYNTAX ERROR**\nLine No. %d Tokens misplaced: %s\n",line,s);   
	    return 0;
	}
	if(s[digits] != '+' && s[digits] != '-')
	{
	    printf("\n**SYNTAX ERROR**\nLine No. %d : First character of instruction must be '+' or '-' sign\n%s", line,s);
	    return 0;
	}
	line++;
    }
    return 1;

}
