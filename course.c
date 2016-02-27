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
	
	// Initialising the allowed file formats you'll be able to read from and write to (:
	char **formats = (char**)malloc(sizeof(char*) * 256);
	
	// allocate memory for each of the objects in it
	for(int c = 0; c < 255; ++c)
	{
		formats[c] = (char*)malloc(sizeof(char) * 10);
	}
	
	formats[0] = ".txt";
	formats[1] = ".dat";
	formats[2] = ".db";
	formats[3] = ".log";
	formats[4] = ".csv";
	formats[5] = ".tsv";
	formats[6] = ".doc";
	formats[7] = ".docx";
	formats[8] = ".xls";
	formats[9] = ".xlsx";
	formats[10] = ".c";
	formats[11] = ".cpp";
	formats[12] = ".java";
	formats[13] = ".class";
	formats[14] = ".php";
	formats[15] = ".js";
	formats[16] = ".html";
	formats[17] = ".htm";
	formats[18] = ".css";
	formats[19] = ".less";
	formats[20] = ".sql";
	formats[21] = ".file";
	formats[22] = ".georgi";
	
	// , ".doc", ".docx", ".xls", ".c", ".cpp", ".java", ".class", ".georgi"
	char *formatChecker = (char*)malloc(sizeof(char) * 10);
	
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
					for(int count = 0; count < 255; ++count) 
					{
						if(strstr(argv[i+1], formats[count]) != NULL)
							formatChecker = formats[count];
					}
					
					// a comfy one-liner to check the input filename
					ifile = (strstr(argv[i+1], formatChecker) != NULL) ? argv[i+1] : "";
				}
				else
					// if not -> assign empty string
					ifile = argv[i+1] = "";
					
				printf("IFILE = %s\n", ifile);
			}
			
			// finds the occurrence of the -o arg in the whole args line. '\0' chars -not compared
			if(strstr(argv[i], "-o") != NULL)
			{			
				if(argv[i+1])
				{
					for(int count = 0; count < 255; ++count) 
					{
						if(strstr(argv[i+1], formats[count]) != NULL)
							formatChecker = formats[count];
					}
					
					// a comfy one-liner to check for output filename
					ofile = (strstr(argv[i+1], formatChecker) != NULL) ? argv[i+1] : "";
				}
				else
					// if not -> assign empty string
					ofile = argv[i+1] = "";
					
				printf("OFILE = %s\n", ofile);
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
		formatChecker = 0;
	}
	
	// free 'em all
	if(ifile != 0) printf("This particular pointer still in use");
	else free(ifile);
	if(ofile != 0) printf("This particular pointer still in use");
	else free(ofile);
	if(strToFind != 0) printf("This particular pointer still in use");
	else free(strToFind);
	if(formatChecker != 0) printf("This particular pointer still in use");
	else free(formatChecker);
	
	// free the 2D array storing our formats
	for(int k = 0; k < 255; ++k)
	{
		formats[k] = 0;
		free(formats[k]);
	}
	free(formats);
	formats = 0;
	
    // cuz' design matters (:
    printf("\n");
	
    return 0;
}