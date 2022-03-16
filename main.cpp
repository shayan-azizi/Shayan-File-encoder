#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>

#define MAX_FILE_SIZE (1024 * 1024)

int main (int argc, char **argv)
{
    char data [MAX_FILE_SIZE];
    int counter = 0;
    int i = 0;
    FILE *fptr;


    try
    {
        fptr = fopen (argv[1], "rb");
        if (! fptr)
        {
            throw argv[1];
        }
    }
    catch(char* fileName)
    {
        std :: cout << fileName << " is not valid file adress" << std :: endl;
        return 1;

    }


    while (!feof (fptr))
    {
        data[i++] = fgetc(fptr);
    }

    fclose (fptr);

    fptr = fopen (argv[1], "wb");

    for (int j = 0; j < i - 1; j++)
    {
        fputc ((data[j] ^ 0x60), fptr);
    }

    fclose (fptr);

    return 0;

}
