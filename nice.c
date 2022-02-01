#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
  int priority, pid;
  if(argc < 3){
    printf(2,"Usage: nice pid priority\n");
    exit();
  }
  pid = atoi(argv[1]);
  priority = atoi(argv[2]);
  if (priority < 1 || priority > 10){
    printf(2,"The priority must be a number from 1 to 10!\n");
    exit();
  }
  change_priority(pid, priority);
  exit();
}
