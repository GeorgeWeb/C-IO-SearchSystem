#include "files.h"

// Create Files pointer and allocate memory
struct Files *Files_Create(char *input_source, char *output_source, size_t line_size, int case_ignore)
{
    struct Files *m_File = malloc(sizeof(struct Files));
    assert(m_File != NULL);

    m_File->input_source = input_source;
	m_File->output_source = output_source;
    m_File->line_size = line_size;
	m_File->case_ignore = case_ignore;
	
    return m_File;
};

// Destroy Files pointer and free allocated memory
void Files_Destroy(struct Files *m_File)
{
    // Check
    assert(m_File != NULL);

    // Free heap memory
    free(m_File);
}

void Close(FILE *fh)
{
	fclose(fh);
}

void Read_Std(char *line, size_t sz)
{	
	// Read from stdout	
	printf("\nEnter here: ");
	fgets(line, sz, stdin);
}

void Write_Std(char *line)
{
	// Write to stdout
	printf("\nSuch output source doesn't exist. Sorry mate. :)\nWe will try to handle this situation in a few.\n");
	printf("\nHey, that's your string, pal: %s", line);
}

// Write line(s) to file
void Write_File(FILE *ofh, char *line)
{
	// Writefile...	
	fprintf(ofh, "%s\n", line);
}

void Search_File(FILE *ifh, FILE *ofh, struct Files *m_File, char *line, char *word, char *str, size_t str_size, int case_ignore)
{
	// Read the file line by line (untill it reaches max chars for line_size)	
	
	static int line_num = 1;
	static int find_result = 0;	
	static int is_saved = 0;
	
	if(ifh)
	{
		printf("\nI just started, pal! (:\n");

		while(fgets(line, m_File->line_size, ifh) != NULL)
		{
			if(case_ignore == 1)
			{
				line = strlwr(line);
				word = strlwr(word);
			}
			
			if(strstr(line, word) != NULL) 
			{
				printf("\nA match found on line %d: %s\n", line_num, word);
				find_result++;
				// Write line to output File
				if(ofh)
				{
					Write_File(ofh, word);
					is_saved = 1;
				}
				else
				{
					Write_Std(word);
				}
			}
			
			line_num++;		
		}
		
		if(find_result == 0)
		{
			printf("\nSorry, couldn't find a match.\n");
			printf("%s", word);
		} 
		
		printf("\nTotal matches found: %d\n", find_result);
	}
	else
	{		
		if(ofh)
		{
			printf("Such input source doesn't exist. Sorry mate. :)\nBut you can enter now what you wanna add in the output source.\n");
			Read_Std(str, str_size);
			printf("%s", str);
			Write_File(ofh, str);
			is_saved = 1;
		}
		else
		{
			printf("Such input source doesn't exist. Sorry mate. :)\nBut you can type what you wanna display.\n");
			Read_Std(str, str_size);
			
			Write_Std(str);
		}
	}
	
	// Just show user that you've saved the found string in an output file
	if(is_saved == 1)
		printf("\n(Saved in output file)\n");
}

// Open and read the file -> Ouput Lines
void Operate_Files_Actions(struct Files *m_File, char *word)
{
    FILE *ifh;
	FILE *ofh;
    // Open input source
    ifh = fopen(m_File->input_source, "r");
	// Open output source
	ofh = fopen(m_File->output_source, "a+");
	
	size_t sz = 64;
	
	char *str = malloc(sizeof(char*) * sz);
	char *line = malloc(m_File->line_size);
	
	Search_File(ifh, ofh, m_File, line, word, str, sz, m_File->case_ignore);
	
	assert(line != NULL);
	free(line);
	assert(str != NULL);
	free(str);
	
	// Check if any of the files is still opened -> CLOSE
	if(ifh)
		Close(ifh);
	if(ofh)
		Close(ofh);
}