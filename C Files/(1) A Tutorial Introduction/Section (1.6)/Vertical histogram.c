#include <stdio.h>
/* Exercise (1.13) - Answer book excerpt */

#define MAXHIST 15 /* Maximum length of the histogram */
#define MAXWORD 11 /* Maximum length of a word */
#define IN 1 
#define OUT 0

int main()
{
    int c, i, j, nc, state;
    int maxvalue; /* Maximum value for array wl*/
    int ovflow; /* Counter for overflow */
    int wl[MAXWORD]; /* Word length counters */

    state = OUT;
    nc = 0;
    ovflow = 0;
    for (i = 0; i < MAXWORD; ++i)
        wl[i] = 0;
    
    while ((c = getchar()) != EOF){
        if (c == ' ' || c == '\n' || c == '\t'){
            state = OUT;
            if (nc > 0)
                if (nc < MAXWORD)
                    ++wl[nc];
                else
                    ++ovflow;
            nc = 0;
        }
        else if (state == OUT){
            state = IN;
            nc = 1; /* Beginning of a new word*/
        }
        else
            ++nc;
    }

    maxvalue = 0;
    for (i = 1; i < MAXWORD; ++i){
        if (wl[i] > maxvalue)
            maxvalue = wl[i];
    }

    for (i = MAXHIST; i > 0; --i){
        for (j = 1; j < MAXWORD; ++j)
            if (wl[j] * MAXHIST / maxvalue >= i)
                printf(" * ");
            else
                printf ("  ");
        putchar ('\n');
    }
    for (i = 1; i < MAXWORD; ++i)
        printf ("%4d ", i);
    putchar('\n');
    for (i = 1; i < MAXWORD; ++i)
        printf ("%4d ", wl[i]);
    putchar('\n');
    if (ovflow > 0)
        printf("There are %d words with a length greater than or equal to %d\n", ovflow, MAXWORD);


}