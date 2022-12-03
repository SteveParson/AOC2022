#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    char line[512];
    int score = 0;

    while (fgets(line, sizeof(line), file))
    {
        int elf1 = line[2] - 'W';
        int elf2 = line[0] - '@';

        // 1 rock, 2 paper, 3 scissors
        score += elf1;

        if (elf1 == elf2)
            score += 3;

        if ((elf1 == 1 && elf2 == 3) || (elf1 == 2 && elf2 == 1) || (elf1 == 3 && elf2 == 2))
            score += 6;
    }

    printf("%d\n", score);
    fclose(file);
    return 0;
}
