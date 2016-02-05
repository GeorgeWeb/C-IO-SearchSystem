#include "files.h"

// Simplicity is always great. (: Most of the time.. :D

// Define some size of the line/word/phrase/string(whatever) to be allocated later on
#ifndef LINE_SIZE
#define LINE_SIZE 256
#endif

int main(int argc, char *argv[])
{
	/** cuz' design matters (: + my eyes can't handle all the text displayed there.
	  * Not really important line at all but.. (:
	*/
	system("cls");
	
	// initialize file sources
	char *ifile;
	char *ofile;
	
	// initialize string to search and assign its value to console argument
	char *strToFind = argv[1];
	
	int case_ignore; // 1 - case ignore, everything else - case specific
	
	// allocate some mem for these 2 :)
	ifile = malloc(sizeof(char*) * 128);
	ofile = malloc(sizeof(char*) * 128);
	
	// loop through the arguments and do the checks as specified
	for(int i = 0; i < argc; i++)
	{
		// finds the occurrence of the -i arg in the whole args line. '\0' chars -not compared
		if(strstr(argv[i], "-i") != NULL)
		{
			if(argv[i+1])
			{
				// a comfy one-liner to check for input filename
				ifile = (strstr(argv[i+1],".txt") != NULL) ? argv[i+1] : "";
			}
			else
				// if not -> assign empty string
				ifile = argv[i+1] = "";			
		}
		
		// finds the occurrence of the -o arg in the whole args line. '\0' chars -not compared
		if(strstr(argv[i], "-o") != NULL)
		{			
			if(argv[i+1])
			{
				// a comfy one-liner to check for output filename
				ofile = (strstr(argv[i+1],".txt") != NULL) ? argv[i+1] : "";
			}
			else
				// if not -> assign empty string
				ofile = argv[i+1] = "";
		}
		
		// finds the occurrence of the -c arg in the whole args line. '\0' chars -not compared
		if(strstr(argv[i], "-c") != NULL)
		{
			case_ignore = 1;
		}
	}
	
	// Create Files struct pointer and allocate memory for it
	struct Files *filez = Files_Create(ifile, ofile, LINE_SIZE, case_ignore);
	
	// Handle all the operations like searching, comparing, writing(file, stdin) etc.
	Operate_Files_Actions(filez, strToFind); // str_word input_file output_file

	/* Free Heap of allocated memory * !!! VERY IMPORTANT as Kevin says :) !!! * ELSE -> We definitely get a MEMORY LEAK */
	Files_Destroy(filez);

    // cuz' design matters (:
    printf("\n");
	
    return 0;
}