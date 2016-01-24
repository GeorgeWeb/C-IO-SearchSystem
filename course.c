#include "files.h"

int main(int argc, char **argv[])
{
    // Create Files struct pointer and allocate memory for it
    struct Files *nums = Files_Create("nums.txt", 64);

    /* TEST OUTPUTS */
    printf("nums.txt is at memory location %p:\n", nums);
    printf("nums.txt memory location size: %d\n\n", sizeof(nums));
    /* END OF TEST OUTPUTS */

    // Read from file and Print data
    Read_File(nums);
    // Destroy file pointer to clean up heap memory
    Files_Destroy(nums);

    // design matter
    printf("\n");

    return 0;
}