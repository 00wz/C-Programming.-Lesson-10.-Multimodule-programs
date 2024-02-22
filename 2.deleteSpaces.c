#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER 1000

size_t getLineFromFile(char fileName[], char strIn[])
{
    FILE* file = fopen(fileName , "r");
    fscanf(file, "%[^\n]", strIn);
    fclose(file);
    return strlen(strIn);
}

void writeToFile(char fileName[], char strOut[])
{
    FILE* file = fopen(fileName, "w");
    fprintf(file, "%s\n", strOut);
    fclose(file);
}

void deleteSpaces(char* srs, char* dst, int length)
{
    int dstIdx = 0;
    for(int srsIdx = 0; srsIdx < length; srsIdx++)
    {
        if( (srs[srsIdx] == ' ') && (((srsIdx - 1) < 0) || srs[srsIdx - 1] == ' ') )
        {
            continue;
        }
        dst[dstIdx] = srs[srsIdx];
        dstIdx++;
    }
    if(dstIdx < length)
    {
        dst[dstIdx] = '\0';
    }
}

int main()
{
    char name_in[] = "input.txt";
    char name_out[] = "output.txt";

    char* str = malloc(BUFFER);
    size_t strLength = getLineFromFile(name_in, str);

    char* newStr = malloc(strLength);
    deleteSpaces(str, newStr, strLength);
    
    writeToFile(name_out, newStr);

    free(str);
    free(newStr);

    return 0;
}