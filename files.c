#include "files.h"
#include <assert.h>

// Create Files pointer and allocate memory
struct Files *Files_Create(char *filename, int line_size)
{
    struct Files *m_File = malloc(sizeof(struct Files));
    assert(m_File != NULL);

    m_File->filename = filename;
    m_File->line_size = line_size;

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

// Output File Data line by line
void Print_Data(FILE *fh, char *line, struct Files *m_File)
{
    static int i = 0; // not gonna use it outside of this function...
    // Go through every line with line's max chars = line_size
    while (fgets(line, m_File->line_size, fh) != NULL)
    {
        printf("Line %d: %s", i+1, line);
        i++;
    }
}

// Open and read the file -> Ouput Data(Print_Data());
void Read_File(struct Files *m_File)
{
    FILE *fh;
    // Open file
    fh = fopen(m_File->filename, "r");
    //check if file exists
    if (fh == NULL)
    {
        printf("Such file does not exists %s", m_File->filename);
		// -> READ FILE NAME FROM STDIN IMPLEMENTATION.
        return 0; // !!! Do not return 0; when implementation is done.
    }
    //read line by line and allocate specific memory
    char *line = malloc(m_File->line_size);
    // Print File data
    Print_Data(fh, line, m_File);
    // free heap memory
    free(line);
}

// Open and read the file -> Ouput Data(Print_Data());
void Write_File(struct Files *m_File)
{
    FILE *fh;
    // Open file
    fh = fopen(m_File->filename, "r");
    //check if file exists
    if (fh == NULL)
    {
        printf("Such file does not exists %s", m_File->filename);
		// -> FILE CREATION IMPLEMENTATION.
        return 0; // !!! do not return 0; when implementation is done.
    }
    
	// Writefile...
}
