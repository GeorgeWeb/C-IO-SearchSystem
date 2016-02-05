#ifndef FILES_HGUARD
#define FILES_HGUARD

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

// Struct datatypes declaration
struct Files
{
    char *input_source;
	char *output_source;	
    int line_size;
};

struct Files *Files_Create(char *input_source, char *output_source, int line_size);
// Functions declarations
void Files_Destroy(struct Files *m_File);
void Search_File(FILE *ifh, FILE *ofh, struct Files *m_File, char *line, char *word, char *str, size_t str_size);
void Operate_Files_Actions(struct Files *m_File, char *word);
void Close(FILE *fh);
void Read_Std(char *line, size_t sz);
void Write_Std(char *line);


#endif
