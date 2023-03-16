#include <stdio.h>

int main()
{
    char s[100];
    int i, c;
    int lim = 10;

    for (i = 0; i < lim -1; ++i) {
        if ((c = getchar()) != '\n') {
            if (c != EOF) 
                s[i] = c;
        }
    }

    return 0;
}
