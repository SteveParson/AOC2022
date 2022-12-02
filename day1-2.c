#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble_sort(long arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                long tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    char line[512];
    long best_value = 0, current_value = 0;
    int best_idx = 1, current_idx = 1, all_values_idx;
    long all_values[1000000] = {0};

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
            all_values[all_values_idx] = current_value;
            all_values_idx++;
            current_value = 0;
            current_idx++;
        }
        else
        {
            current_value += atol(line);
        }
    }

    bubble_sort(all_values, all_values_idx);

    long answer;
    for (int i = 0; i != 3; i++)
    {
        answer += all_values[i];
    }

    printf("%ld\n", answer);
    fclose(file);
    return 0;
}
