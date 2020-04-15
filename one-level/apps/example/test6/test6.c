#include "usertraps.h"
#include "misc.h"
#include "os/memory_constants.h"

void main (int argc, char *argv[])
{
  sem_t s_procs_completed; // Semaphore to signal the original process that we're done
  int* invalidAddress;
  int i;

  if (argc != 2) { 
    Printf("Usage: %s <handle_to_procs_completed_semaphore>\n"); 
    Exit();
  } 

  // Convert the command-line strings into integers for use as handles
  s_procs_completed = dstrtol(argv[1], NULL, 10);
  invalidAddress = MEM_MAX_VIRTUAL_ADDRESS - MEM_PAGESIZE - 3;

  // Now print a message to show that everything worked
  Printf("Looping a large number to create simultaneous processes (%d): test6\n", getpid());

  for (i = 0; i < 123456; i++) {
    //just looping
  }


  // Signal the semaphore to tell the original process that we're done
  if(sem_signal(s_procs_completed) != SYNC_SUCCESS) {
    Printf("test6 (%d): Bad semaphore s_procs_completed (%d)!\n", getpid(), s_procs_completed);
    Exit();
  }

  Printf("Completed successfully, looped through a big number\n %d!\n", *invalidAddress);
  Printf("TEST6 (%d): Done here!\n", getpid());
}
