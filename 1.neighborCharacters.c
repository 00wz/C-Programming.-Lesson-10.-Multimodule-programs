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

void swap(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void swapNeighborCharacters(char* str, int length)
{
    char* leftChar = NULL;
    for(int i = 0; i < length; i++)
    {
        if(str[i] == ' ')
        {
            continue;
        }

        if(leftChar == NULL)
        {
            leftChar = &str[i];
        }
        else
        {
            swap(leftChar, &str[i]);
            leftChar = NULL;
        }
    }
}

int main()
{
    char name_in[] = "input.txt";
    char name_out[] = "output.txt";

    char* str = malloc(BUFFER);
    size_t strLength = getLineFromFile(name_in, str);

    swapNeighborCharacters(str, strLength);
    
    writeToFile(name_out, str);

    free(str);

    return 0;
}