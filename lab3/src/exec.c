#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <getopt.h>

int main()
{
     pid_t child_pid = fork();
    if(child_pid != 0){
        execl("sequential_min_max", " ", "1", "80", NULL);
    }
    else
        return 0;
}