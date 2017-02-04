#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Easier version of the initials problem
// Takes in a Name without special characters
// and returns the initials
// ex.
// Ted Manson: TM
// Gary Henson Brantley: GHB

int main(void) {
    string fullName;
    
    do {
        //Get the name from the user
        fullName = get_string();
    } while(fullName == NULL);
    
    char *names;
    //Get first of names before space
    names = strtok(fullName, " ");
        
    while (names != NULL) {
        //Print first letter of current name
        printf("%c", toupper(names[0]));
        //Move to next name in fullName
        names = strtok(NULL, " ");
    }
        
    printf("\n");
}