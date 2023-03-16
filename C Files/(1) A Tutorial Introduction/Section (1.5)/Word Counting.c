#include <stdio.h>

#define IN 1 /* Inside a word */
#define OUT 0 /* Outside a word */

/* Count Lines, Words and Characters in an input */
main()
{
    int c, nw, nl, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF){
        nc++;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state == IN;
            ++nw;
        }
    }
    printf ("%d %d %d\n", nl, nw, nc);
}