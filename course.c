#include "files.h"

// Simplicity is always great. :)

int main(int argc, char *argv[])
{
	system("cls");
	
	if((strcmp(argv[2], "-i") == 0) && (strcmp(argv[4], "-o") == 0))
	{
		// Create Files struct pointer and allocate memory for it
		struct Files *filez = Files_Create(argv[3], argv[5], 64);
		
		Operate_Files_Actions(filez, argv[1]); // str_word input_file output_file
		
		/* * Free Heap of allocated memory * !!! VERY IMPORTANT as Kevin says :) !!! * ELSE We get MEMORY LEAK */
		Files_Destroy(filez);
	}
	else
		printf("WRONG COMMAND!");

    // design matters :)
    printf("\n");

    return 0;
}