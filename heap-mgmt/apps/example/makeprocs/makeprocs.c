#include "usertraps.h"
#include "misc.h"


void main (int argc, char *argv[])
{
    int *one, *two, *three, *four;

    Printf("Malloc Tests:\n");
    Printf("Malloc size 10.\n");
    one = malloc(10);
    Printf("Malloc size 100.\n");
    two = malloc(100);
    Printf("Malloc size 1000.\n");
    three = malloc(1000);
    Printf("Malloc size 15.\n");
    four = malloc(15);

    Printf("mfree Tests:\n");
    Printf("Free 10.\n")
    mfree(one);
    Printf("Free 100.\n")
    mfree(two);
    Printf("Free 1000.\n")
    mfree(three);
    Printf("Free 15.\n")
    mfree(four);

    Printf("Malloc and mfree tests complete");
  
}
