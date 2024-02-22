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

void extensionChange(char* str, int length)
{
    int pointPosition = length;
    for( int i = length -1; i >= 0; i--)
    {
        if(str[i] == '/')
        {
            break;
        }
        if(str[i] == '.')
        {
            pointPosition = i;
            break;
        }
    }
    strcpy(&str[pointPosition], ".html");
}

int main()
{
    char name_in[] = "input.txt";
    char name_out[] = "output.txt";

    char* str = malloc(BUFFER);
    size_t strLength = getLineFromFile(name_in, str);

    extensionChange(str, strLength);
    
    writeToFile(name_out, str);

    free(str);

    return 0;
}