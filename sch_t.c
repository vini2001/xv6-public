#include "types.h"
#include "user.h"

int stdout = 1;
int stderr = 2;

int
main(int argc, char *argv[])
{

    int pid = fork();
    if(pid != 0) {
        char *argvv[] = { "hjb", "1000", "10", 0 };
        int execR = exec("hjb", argvv);
        printf(stderr, "execR: %d\n", execR);
        // printf(stderr, "Scheduler test finished p1\n");
    }else{
        char *argvv[] = { "hjb", "10", "100", 0 };
        int execR = exec("hjb", argvv);
        printf(stderr, "execR: %d\n", execR);
        // printf(stderr, "Scheduler test finished p2\n");
    }
    exit();
}