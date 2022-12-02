#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char line[512];
    long best_value = 0, best_idx = 1, current_value = 0, current_idx = 1;

    FILE *file = fopen(argv[1], "r");

    while (fgets(line, sizeof(line), file))
    {
        if (line[0] == '\n')
        {
            if (current_value >= best_value)
            {
                best_value = current_value;
                best_idx = current_idx;
            }
            current_idx++;
            current_value = 0;
        }
        else
        {
            current_value += atol(line);
        }
    }

    printf("%ld\n", best_idx);
    fclose(file);
    return 0;
}