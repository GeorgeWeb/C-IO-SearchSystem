#include <stdio.h>

#ifndef SIZE
// it should actualy be 3 but won't be a problem to allocate a bit more for that particular program,
// though I know it's important to do your calculations before dynamically allocating any memory(which is what I did) but anyway.. (:
#define SIZE 10
#endif

// enum giving names to my ints for the menu "links"/choices :D
enum HELPERS
{
	EXIT = 0,
	INFORMATION = 1,
	EXAMPLES = 2
};

int main(int argc, char **argv)
{
	// The usual stuff, even though I know that the use of system is a bad practice.
	// But the thing is that I only use it for such small programs.
	system("cls");
	
	printf("|-----------------------------|\n");
	printf("|Welcome to the SUPPORT app!  |\n");
	printf("|Here's your guide, newbie. ;)|\n");
	printf("|-----------------------------|\n");
	
	printf("\n\n");
	
	// just to make that loop until this is true/mean flag is 1
	// otherwise it stops and ends. simple flag.
	int flag = 1;
	
	while(flag)
	{
		printf("Type one of the following options.\n");
		printf("0 - EXIT HELP APP\n");
		printf("1 - DISPLAY INFORMATION\n");
		printf("2 - VIEW SOME EXAMPLES\n");
		printf("Enter: ");
		
		// Read input
		char *out = (char*)malloc(sizeof(char) * SIZE);
		fgets(out, SIZE, stdin);

		// Convert to HELPERS
		enum HELPERS help = atoi(out);
		
		// Cases based on input...|
		switch(help)
		{
			case EXIT:
				printf("Well done, pal! Hope you got it. (:\n\n");
				// exit the loop (:
				flag = 0;
				// Free the Heap. Get rid of out in the mem...
				free(out);
				out = 0;
				break;
			case INFORMATION:
				printf("|------------------------------------------------------------\n");
				printf("Information...\n\n");
				printf("The find tool uses simple commands with a few arguments.}\n");
				printf("\"-i\" is for input dest. and \"o\" is for output dest. (:\n");
				printf("The additional(optional) command \"-c\" is there in case\n");
				printf("you are not aware of the type of case letters in your string.\n");
				printf("I hope that was enough informative... (:\n");
				printf("-------------------------------------------------------------\n\n\n");
				// Free the Heap. Get rid of out in the mem...
				free(out);
				out = 0;
				break;
			case EXAMPLES:
				printf("-------------------------------------------------------------\n");
				printf("Examples...\n\n");
				printf("eg 0: find mystring -i filename -o filename\n");
				printf("eg 1: find mystring -i filename -o filename -c\n");
				printf("(use commas if the string contains is formed of more phrases)\n");
				printf("eg 2: find \"mystring1 mystringN\" -i filename -o filename\n");
				printf("eg 3: find \"mystring1 mystringN\" -i filename -o filename -c\n");
				printf("eg 4: find mystring -i filename -o\n");
				printf("eg 5: find mystring -i filename -o -c\n");
				printf("eg 6: find mystring -i filename\n");
				printf("eg 7: find mystring -o filename\n");
				printf("eg 8: find mystring\n");
				printf("I hope you got these, pal. No go type 'em! ;)... (:\n");
				printf("-------------------------------------------------------------\n\n\n");
				// Free the Heap. Get rid of out in the mem...
				free(out);
				out = 0;
				break;
			default:
				printf("*** (Invalid Input)*TryAgain ***\n\n\n");
				// Free the Heap. Get rid of out in the mem...
				free(out);
				out = 0;
				break;
		}
	}

	return 0;
}