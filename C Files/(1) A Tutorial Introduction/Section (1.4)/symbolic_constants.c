#include <stdio.h>

#define LOWER  0  /*Symbolic Constant is not a variable, so they do not appear in declerations*/
#define UPPER  300
#define STEP 20

/*Printing Fareheit -> Celsius Table*/
main()
{
    int fahr;
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + 20)
        printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr - 32));
}
