#include <stdio.h>
/* To print lines that have a length larger than 80 characters*/

#define BARRIER 80
#define MAXLINE_LENGTH 100
#define COUNT 100

int getlength(char line[], int maxline_length);


main()
{ 
    int len; /* Current line length */
    char line[MAXLINE_LENGTH]; /* Current input line */
    char satisfy[COUNT]; /* Lines that satisfy the given criteria */
    int i, end, j;

    i = 0;
    end = 0;

    while ((len = getlength(line, MAXLINE_LENGTH)) > 0)  /* Don't put > BARRIER, because this condition will cease the loop useless.*/
        if (len > BARRIER)
            printf("%s\n", line);
}


int getlength(char s[], int lim)
{
    int c, i;

    for (i = 0; i < (lim - 1) && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}