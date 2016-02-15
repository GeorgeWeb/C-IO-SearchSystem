// Use heading guard to make sure we define that header ONLY ONCE.
#ifndef FILES_HGUARD
#define FILES_HGUARD

// Preproccessor definitions...
#ifndef LINE_SIZE
#define LINE_SIZE 256
#endif

// Including all the libs we need... 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct datatypes declaration
struct Files
{
	// Just declaring structs's members right here
    char *input_source;
	char *output_source;	
    size_t line_size;
	int case_ignore;
};

// Functions' bodies declarations (:
struct Files *Files_Create(char *input_source, char *output_source, size_t line_size, int case_ignore);
void Files_Destroy(struct Files *m_File);
void Search_File(FILE *ifh, FILE *ofh, struct Files *m_File, char *line, char *word, char *str, size_t str_size, int case_ignore);
void Operate_Files_Actions(struct Files *m_File, char *word);
void Close(FILE *fh);
void Read_Std(char *line, size_t sz);
void Write_Std(char *line);

// End the heading guard statement -> so what's written in it is only executed if the header's defined(mean always in this case)
#endif