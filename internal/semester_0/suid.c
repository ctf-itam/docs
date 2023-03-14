#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    // Check user ID
    if (getuid() != 0) {
        printf("You are not root!");
    }

    // Set UID bit
    setuid(0);
    // Check user ID
    if (getuid() != 0) {
        printf("You are not root!");
    } else {
        printf("You are root!");
    }
}