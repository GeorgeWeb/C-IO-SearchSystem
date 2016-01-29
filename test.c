#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Search_in_File(char *fname, char *str)
{
	return 0;
}

//Our main function.
int main(int argc, char **argv) 
{
    //printf("argc = %d\n", argc);
	
    //for(int i = 0; i < argc; ++i)
	//{
        //printf("argv[%d] = %s\n", i, argv[i]);
    //}
	
	system("cls");
	if(argc < 3)
	{
		printf("NOT ENOUGH ARGUMENTS!");
	}
	else
	{
		if(strcmp(argv[1], "-i") == 0)
		{
			printf("\n%d\n", argc);
			printf("\nargv0 = %s\nargv1 = %s\nargv2 = %s", *argv, *argv, *argv);
		}
		else
		{
			printf("WRONG COMMAND!");
		}
	}
}