#include "usertraps.h"
#include "misc.h"

#define HELLO_WORLD "hello_world.dlx.obj"
#define TEST1 "test1.dlx.obj"
#define TEST2 "test2.dlx.obj"
#define TEST3 "test3.dlx.obj"

void main (int argc, char *argv[])
{
    int i = 0;
    int child;

    if(argc != 1){
     Printf("Need Zero inputs just created one child proccess.\n");
	 Exit();
    }

    Printf("Original MakeProcs PID: %d.\n", getpid());

    child = fork();
    if(child != 0){
     Printf("I am Parent proccess, id: %d, value i:%d\n", getpid(), i);
     Printf("Child proccess, id: %d\n", child);

	}else{
     i=99795;
     Printf("Child proccess here with and id: %d and i: %d\n", child, i);
	}

    Printf("MakeProcs: %d is done now and forking worked.\n", getpid());
 }
