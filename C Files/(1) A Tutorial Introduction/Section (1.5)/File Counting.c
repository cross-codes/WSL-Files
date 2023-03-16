#include <stdio.h>

/*Count characters in an input*/
main()
{
    double count;

    for (count = 0; getchar() != EOF; ++count)
        ;
    printf("%.0f\n", count);
}