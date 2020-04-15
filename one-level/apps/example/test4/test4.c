#include "usertraps.h"
#include "misc.h"
#include "os/memory_constants.h"

int test4Helper(int x) {
    if (x == 0) {
        return x;
    }

    return (1 + test4Helper(x - 1));
}



void main (int argc, char *argv[])
{
  sem_t s_procs_completed; // Semaphore to signal the original process that we're done
  int x;

  if (argc != 2) { 
    Printf("Usage: %s <handle_to_procs_completed_semaphore>\n"); 
    Exit();
  } 

  // Convert the command-line strings into integers for use as handles
  s_procs_completed = dstrtol(argv[1], NULL, 10);

  // Now print a message to show that everything worked
  Printf("Attempting to grow the user function call stack larger than one page (%d): test4\n", getpid());

  x = test4Helper(1025);
  Printf("Called %d times\n", x);

  // Signal the semaphore to tell the original process that we're done
  if(sem_signal(s_procs_completed) != SYNC_SUCCESS) {
    Printf("test4 (%d): Bad semaphore s_procs_completed (%d)!\n", getpid(), s_procs_completed);
    Exit();
  }

  Printf("Completed successfully, call stack grew larger than one page\n");
  Printf("TEST4 (%d): Done!\n", getpid());
}