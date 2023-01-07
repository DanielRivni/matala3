#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define LINE 256
#define WORD 30
int getLine(char **line)
{
    char c;
    int size = 0;
    char *s = (char *)calloc(sizeof(char), LINE);
    while ((c = getchar()) != '\n' && c != EOF)
    {
        s[size++] = c;
    }

    if (size > 0)
    {

        *line = (char *)calloc(sizeof(char), size + 1);
        strcpy(*line, s);
    }

    free(s);
    return size;
}

int getWord(char **word)
{
    char c;
    int size = 0;
    char *s = (char *)calloc(sizeof(char), WORD);
    while ((c = getchar()) != '\n' && c != '\t' && c != ' ' && c != EOF)
    {
        s[size++] = c;
    }

    if (size > 0)
    {

        *word = (char *)calloc(sizeof(char), size + 1);
        strcpy(*word, s);
    }
    free(s);
    return size;
}

int substring(char *str1, char *str2)
{
    if (strstr(str1, str2) != NULL)
    {
        return 1;
    }
    return 0;
}

char *build_str(char *str, int p, int n)
{
    char *result = malloc(sizeof(char) * (strlen(str) - n));

    memcpy(result, str, p);
    strcpy(result + p, str + p + n);
    return result;
}

int similar(char *s1, char *s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (strcmp(s1, s2) == 0)
    {
        return 1;
    }

    if (abs(len1 - len2) > 1)
    {
        return 0;
    }

    int i, diff_count = 0;
    for (i = 0; i < len1; i++)
    {
        char *new_str = build_str(s1, i, 1);
        if (strcmp(new_str, s2) == 0)
        {
            return 1;
        }
    }

    return 0;
}

int test()
{

    printf("%d\n", similar("swsystem", "ssystem"));
    printf("%d\n", similar("swsystem", "wsystem"));
    printf("%d\n", similar("swsystem", "swsyste"));
    printf("%d\n", similar("swsystem", "swsysem"));
    printf("%d\n", similar("swsystem", "swsstem"));
    printf("%d\n", similar("swsystem", "swsystem"));
    printf("%d\n", similar("swsystem", "swsstm"));
}

void print_lines(char *str)
{
    while (1)
    {
        char *line = NULL;
        int size = getLine(&line);

        if (size == 0)
        {
            break;
        }

        if (substring(line, str))
        {
            printf("%s\n", line);
        }

        free(line);
    }
}

void print_similar_words(char *str)
{
    while (1)
    {
        char *word = NULL;
        int size = getWord(&word);

        if (size == 0)
        {
            break;
        }

        if (similar(word, str))
        {
            printf("%s\n", word);
        }

        free(word);
    }
}

int main()
{

    char *findWord = NULL;
    int size = getWord(&findWord);

    if (size == 0)
    {
        printf("failed to read a word to search.\n");
        return 1;
    }

    char *option = NULL;
    size = getWord(&option);

    if (size != 1)
    {
        printf("read unknown option.\n");
        return 1;
    }

    // printf("** got the word %s, and the option %s**\n", findWord, option);

    char *emptyLine = NULL;
    size = getLine(&emptyLine); // dummy read empty line
    if (size != 0)
    {
        printf("failed to find an empty line. check your file format.\n");
        return 1;
    }

    // printf("** output **\n");

    // get first line
    if (strcmp(option, "a") == 0)
    {
        print_lines(findWord);
    }
    else
    {
        print_similar_words(findWord);
    }

    free(findWord);
    free(option);
    free(emptyLine);
    return 0;
}