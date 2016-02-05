#include "files.h"

// Simplicity is always great. :)

#define LINE_SIZE 64

int main(int argc, char *argv[])
{
	system("cls");
	
	char *ifile;
	char *ofile;
	
	char *strToFind = argv[1];
	
	int caseMatter = 0; // 1 - case specific, 0 - case ignore
	
	for(int i = 0; i < argc; i++)
	{
		if(strstr(argv[i], "-i"))
		{
			printf("\n%d\n", i);
			//ifile = malloc(sizeof(char*));
			if(argv[i+1])
			{
				ifile = (strstr(argv[i+1],".txt")) ? argv[i+1] : "";
			}
			else
				ifile = argv[i+1] = "";
			printf("%s ", ifile);
		}
		
		if(strstr(argv[i], "-o"))
		{
			printf("\n%d\n", i);
			if(argv[i+1])
			{
				ofile = (strstr(argv[i+1],".txt")) ? argv[i+1] : "";
			}
			else
				ofile = argv[i+1] = "";
			printf("%s", ofile);
		}
		
		if(strstr(argv[i], "-c"))
		{
			printf("\n%d\n", i);
		}
		else
			printf("\n%d\n", i);
	}
	
	// Create Files struct pointer and allocate memory for it
	struct Files *filez = Files_Create(ifile, ofile, 64);
	
	//
	Operate_Files_Actions(filez, strToFind); // str_word input_file output_file

	/* Free Heap of allocated memory * !!! VERY IMPORTANT as Kevin says :) !!! * ELSE We get MEMORY LEAK */
	Files_Destroy(filez);

    // design matters :)
    printf("\n");

    return 0;
}