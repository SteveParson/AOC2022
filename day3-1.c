#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strip(char *line)
{
    int size = strlen(line) - 1;
    if (*line && line[size] == '\n')
        line[size] = '\0';
}

int get_priority(char c)
{
    return (c >= 'a' && c <= 'z') ? c - 96 : c - 64 + 26;
}

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    char line[512];
    int score = 0;

    while (fgets(line, sizeof(line), file))
    {
        strip(line);
        int count1[255] = {0};
        int count2[255] = {0};
        int len = strlen(line);

        for (int i = 0; i < len; i++)
        {
            int j = len - i - 1;
            int priority1 = get_priority(line[i]);
            int priority2 = get_priority(line[j]);
            count1[priority1]++;
            count2[priority2]++;

            if (count1[priority1] > 0 && count2[priority1] > 0)
            {
                score += priority1;
                break;
            }

            if (count1[priority2] > 0 && count2[priority2] > 0)
            {
                score += priority2;
                break;
            }
        }
    }
    printf("%d\n", score);
    fclose(file);
    return 0;
}