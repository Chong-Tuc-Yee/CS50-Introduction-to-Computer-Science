#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
const int BLOCK_SIZE = 512;
int is_start_new_jpeg(BYTE buffer[]);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if(argc != 2)
    {
        printf("Usage: ./recover IMAGE");
        return 1;
    }

    // Open input file
    FILE *raw_file = fopen(argv[1], "r");
    if(raw_file == NULL)
    {
        printf("Could not open file.\n");
        return 2;
    }

    BYTE buffer[BLOCK_SIZE];
    FILE *image;
    char filename[8];
    int filename_index = 0;

    while(fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        if(is_start_new_jpeg(buffer) == 1) // Current block read is start of new JPEG
        {
            if(filename_index != 0) // Found JPEG is not first JPEG, close previous jpg file
            {
                fclose(image);
            }
            sprintf(filename, "%03i.jpg", filename_index++); // Print to string with format of .jpg
            image = fopen(filename, "w");
            fwrite(buffer, 1, BLOCK_SIZE, image);
        }
        else if(filename_index > 0) // Next block is not start of JPEG, keep writing to current file
        {
            fwrite(buffer, 1, BLOCK_SIZE, image);
        }
    }
    //Close files
    fclose(raw_file);
    fclose(image);
    return 0;
}

int is_start_new_jpeg(BYTE buffer[])
{
    if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        return 1;
    }
    return 0;
}
