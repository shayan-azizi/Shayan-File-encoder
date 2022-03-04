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

    fptr = fopen (argv[1], "rb");

    while (!feof (fptr))
    {
        data[i++] = fgetc(fptr);
    }

    fclose (fptr);

    for (char c : data)
    {
        data[counter] = char(int(data[counter]) - 31);
        counter++;
    }

    data[0] = char(int(data[0]) + 31);

    fptr = fopen (argv[1], "wb");

    for (int j = 0; j < i - 1; j++)
    {
        fputc (data[j], fptr);
    }

    fclose (fptr);

    return 0;

}