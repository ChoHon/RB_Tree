#include <stdio.h>
#include <string.h>

void main() {
    char *bug = NULL;

    strcpy(bug, "debug");
    printf("bug is %s \n", bug);

    return;
}
