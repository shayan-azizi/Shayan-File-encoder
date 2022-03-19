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

    std :: string argument = argv[1];
    
    if (argument == "--help" || argument == "-h")
    {
        printf("\n");
        std :: cout << "Usage: file-encode [OPTION] ... [FILE]" << std :: endl;
        std :: cout << "XOR 0.x60 Encode or Decode FILE, Enter the file adress and then your file will be encrypted." << std :: endl;
        std :: cout << "Mandatory arguments to long options are mandatory for short options too." << std :: endl;
        std :: cout << "    -d, --decode        decode the file" << std :: endl;
        std :: cout << "    -h, --help          Desplay this " << std :: endl;


        return 0;

    }

    bool flag = false;

    if (argument[0] == '-') 
    {
        flag = true;
    }


    try
    {
        fptr = fopen (argv[1], "rb");
        if (! fptr)
        {
            throw argv[1];
        }

    }

    catch (char* fileName)
    {
        if (flag == false)
        {
            std :: cout << fileName << " is not valid file adress" << std :: endl;
        }

        else
        {
            std::cout << fileName << " command not found!" << std::endl;
            std::cout << "File-Encode: Use --help for more information." << std::endl;
        }

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
