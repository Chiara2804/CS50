#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

typedef uint8_t BYTE;

#define BLOK_SIZE 512
#define FILE_NAME_SIZE 8

bool is_start_new_jpeg(BYTE buffer[]);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    //open the memory card file
    FILE *infile = fopen(argv[1], "r");
    //check if it can find the file
    if (infile == NULL)
    {
        printf("File not found\n"); //errore message
        return 1;
    }

    //variables
    BYTE buffer[BLOK_SIZE]; //512bytes into a buffer
    int file_index = 0;
    bool have_found_first_jpg = false;
    FILE *outfile;
    while (fread(buffer, BLOK_SIZE, 1, infile))
    {
        if (is_start_new_jpeg(buffer))
        {
            if (!have_found_first_jpg)
            {
                have_found_first_jpg = true;
            }
            else
            {
                fclose(outfile);
            }
            char filename[FILE_NAME_SIZE];
            sprintf(filename, "%03i.jpg", file_index++);
            outfile = fopen(filename, "w");
            if (outfile == NULL)
            {
                return 1;
            }
            fwrite(buffer, BLOK_SIZE, 1, outfile);
        }
        else if (have_found_first_jpg)
        {
            //keep on writing the previous file
            fwrite(buffer, BLOK_SIZE, 1, outfile);
        }
    }
    fclose(outfile);
    fclose(infile);
}

bool is_start_new_jpeg(BYTE buffer[])
{
    return buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;
}
