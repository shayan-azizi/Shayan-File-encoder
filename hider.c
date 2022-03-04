#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILE_SIZE (1024 * 1024 )


int main ()
{

    char data [MAX_FILE_SIZE];
    int i = 0;
    FILE *fptr;

    char input[10000];
    printf ("input file name: ");
    scanf("%[^\n]%*c", input);


    fptr = fopen(input, "rb");

    
    while (!feof(fptr))
    {
        data[i++] = fgetc(fptr);
    }

    fclose(fptr);

    // data[0] = data[0] == 'G' ? 'S' : 'G';

    data[0] = ';';


    fptr = fopen(input, "wb");

    for (int j = 0; j < i-1; j++)
    {
        fputc(data[j], fptr);
    }

    fclose(fptr);

    return 0;

}