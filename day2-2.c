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
        int choice = line[0] - '@';
        int outcome = line[2] - 'W';
        
        // 1 rock, 2 paper, 3 scissors
        // 1 lose, 2 draw, 3 win
        if (choice == 1 && outcome == 1) score += 3;
        if (choice == 1 && outcome == 2) score += 1+3; 
        if (choice == 1 && outcome == 3) score += 2+6;

        if (choice == 2 && outcome == 1) score += 1;
        if (choice == 2 && outcome == 2) score += 2+3;
        if (choice == 2 && outcome == 3) score += 3+6;

        if (choice == 3 && outcome == 1) score += 2;
        if (choice == 3 && outcome == 2) score += 3+3;
        if (choice == 3 && outcome == 3) score += 1+6; 
    }

    printf("%d\n", score);
    fclose(file);
    return 0;
}
