#ifndef FILES_HGUARD
#define FILES_HGUARD

#include <stdio.h>
#include <stdlib.h>

// Struct datatypes declaration
struct Files
{
    char *filename;
    int line_size;
};

// Functions declarations
struct Files *Files_Create(char *filename, int line_size);
void Files_Destroy(struct Files *m_File);
void Print_Data(FILE *fh, char *line, struct Files *m_File);
void Read_File(struct Files *m_File);

#endif
