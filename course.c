// Again gettin' that nice hell of a header here (:
#include "files.h"
// Simplicity is always great. (: Most of the time.. :D

// Define some size of the line/word/phrase/string(whatever) to be allocated later on
#ifdef LINE_SIZE // Very bad name, not long enough, too general, etc..
  static const int line_sz = LINE_SIZE;
#else
  static const int line_sz = 256; // default value
#endif

/**
  * PLEASE, I need a Destructive feedback on the whole thing!
  * I know it will take time but will also give me a better understanding on what should I improve in my aproaches etc.
**/

int main(int argc, char **argv)
{	
	// initialize file sources AND assign.. nothing to them (make them empty strings)
	char *ifile = (char*)malloc(sizeof(char*) * line_sz);
	char *ofile = (char*)malloc(sizeof(char*) * line_sz);
	
	// initialize string to search and assign its value to console argument
	char *strToFind = (char*)malloc(sizeof(char) * line_sz);
	
	// 1 - case ignore, everything else - case specific
	int case_ignore;
	
	// Playin' around with args size in order to achieve full functionality and informativity of the program
	if(argc < 2)
	{
		printf("|--------------------------------------------------------------------------|\n");
		printf("|The command need more arguments. You have at enter at least 4 of these. (:|\n");
		printf("|--------------------------------------------------------------------------|\n");
		printf("|Type help in the console in order execute/run the support application.    |\n");
		printf("|That one will teach you how to use the features of the program. (:        |\n");
		printf("|--------------------------------------------------------------------------|\n");
	}
	else
	{
		ifile = "";
		ofile = "";
		
		strToFind = argv[1];		
		
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
		struct Files *filez = Files_Create(ifile, ofile, line_sz, case_ignore);
		
		// Handle all the operations like searching, comparing, writing(file, stdin) etc.
		Operate_Files_Actions(filez, strToFind); // str_word input_file output_file

		/* Free Heap of allocated memory * !!! VERY IMPORTANT as Kevin says :) !!! * ELSE -> We definitely get a MEMORY LEAK */
		Files_Destroy(filez);
		ifile = 0;
		ofile = 0;
		strToFind = 0;
	}

	// free 'em all
	if(ifile != 0) printf("This particular pointer still in use");
	else free(ifile);
	if(ofile != 0) printf("This particular pointer still in use");
	else free(ofile);
	if(strToFind != 0) printf("This particular pointer still in use");
	else free(strToFind);
	
    // cuz' design matters (:
    printf("\n");
	
    return 0;
}