#include "types.h"
#include "user.h"

int stdout = 1;
int stderr = 2;


char* strcat(char* s1, const char* s2)
{
  char* b = s1;

  while (*s1) ++s1;
  while (*s2) *s1++ = *s2++;
  *s1 = 0;

  return b;
}

char* itoa(int val){
    int base = 10;

    static char buf[32] = {0};

    int i = 30;

    for(; val && i ; --i, val /= base)

        buf[i] = "0123456789abcdef"[val % base];

    return &buf[i+1];

}

int
main(int argc, char *argv[])
{
    if(argc < 3){
        printf(stderr, "Usage: heavyjob user_weight sys_weight\n");
        exit();
    }

    printf(stdout, "Starting heavy job...\n");
    // int weight = atoi(argv[1]);

    char dir[100] = "/hjobtest";    
    mkdir(dir);

    int user_weight = atoi(argv[1]);
    int sum = 0;
    for(int i = 0; i < user_weight*10000; i++) { for(int z = 0; z < 2000; z++) { for(int j = 0; j < 20000; j++) {
                sum += i;
                sum -= j;
    } } }

    int sys_weight = atoi(argv[2]);
    for(int i = 0; i < sys_weight*2; i++) {
        char dir[100] = "/hjobtest/";    
        strcat(dir, itoa(i));
        mkdir(dir);
        unlink(dir);
    }

    printf(stderr, "Heavy job finished\n", sum);

    mkdir(dir);

    exit();
}