#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(){
    char *fn = "/tmp/XYZ"; // harmless file writable by real user who runs the program
    char buffer[60];
    FILE *fp;
    scanf("%50s", buffer); // Read some user data from stdin
    if(!access(fn, W_OK)){ // Make sure real user who runs this program indeed has write permission to /tmp/XYZ. access() uses real uid for permission check
        fp = fopen(fn, "a+"); // Only if permission check passed, open the file for append. fopen() uses effective uid for permission check
        fwrite("\n", sizeof(char), 1, fp); // Change the opened file
        fwrite(buffer, sizeof(char), strlen(buffer), fp);
        fclose(fp);
    }else
        printf("No permission\n");
        
    return 0;
}
