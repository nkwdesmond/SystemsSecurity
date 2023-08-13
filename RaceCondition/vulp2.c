#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(){
    char *fn = "/tmp/XYZ"; // harmless file writable by real user who runs the program
    char buffer[60];
    FILE *fp;
    scanf("%50s", buffer); // Read some user data from stdin
    printf("%d\n",access(fn, W_OK)); // Make sure real user who runs this program indeed 
    printf("%s\n",strerror(errno));
}
