#include "usertraps.h"
#include "misc.h"

#define HELLO_WORLD "hello_world.dlx.obj"
#define TEST1 "test1.dlx.obj"
#define TEST2 "test2.dlx.obj"
#define TEST3 "test3.dlx.obj"

void main (int argc, char *argv[])
{
    int i;
    int child;

    if(argc != 1){
     Printf("Need Zero inputs just created one child proccess.\n");
	 Exit();
    }

    Printf("Original MakeProcs PID: %d.\n", getpid());

    child = fork();
    if(child != 0){
     Printf("Parent proccess, id: %d\n", getpid());
     Printf("Child proccess, id: %d\n", child);
	}else{
     Printf("Child proccess here with and id: %d\n", child);
	}

    Printf("MakeProcs: %d is done now and forking worked.\n", getpid());
 }
