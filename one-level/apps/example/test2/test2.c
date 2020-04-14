#include "usertraps.h"
#include "misc.h"
#include "os/memory_constants.h"

void main (int argc, char *argv[])
{
  sem_t s_procs_completed; // Semaphore to signal the original process that we're done
  int* invalidAddress;

  if (argc != 2) { 
    Printf("Usage: %s <handle_to_procs_completed_semaphore>\n"); 
    Exit();
  } 

  // Convert the command-line strings into integers for use as handles
  s_procs_completed = dstrtol(argv[1], NULL, 10);
  invalidAddress = MEM_MAX_VIRTUAL_ADDRESS - 4;

  // Now print a message to show that everything worked
  Printf("Attempting to access past MAX Virtual Address (%d): test2\n", getpid());

  // Signal the semaphore to tell the original process that we're done
  if(sem_signal(s_procs_completed) != SYNC_SUCCESS) {
    Printf("test2 (%d): Bad semaphore s_procs_completed (%d)!\n", getpid(), s_procs_completed);
    Exit();
  }

  Printf("Attempting to access address: %d\n", invalidAddress);
  Printf("Accessing the value...", * (invalidAddress));
  Printf("test2 (%d): Done!\n", getpid());
}