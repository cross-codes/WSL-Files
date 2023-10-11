#include <stdio.h>
/*Counting digits, whitespaces and other characters that are not the ones mentioned previously*/
main()
{
    int c, i, nwhite, nother;
    int ndigits[10];

    nwhite = nother = 0;

    for (i = 0; i<10; ++i)
        ndigits[i] = 0;

    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++ndigits[c-'0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;
    
    printf ("digits (0, 1, 2, 3, 4, 5, 6, 7, 8, 9) = ");
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigits[i]);
    printf(", whitespaces = %d, other = %d\n", nwhite, nother);
}