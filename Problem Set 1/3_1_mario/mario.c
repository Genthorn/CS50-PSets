#include <cs50.h>
#include <stdio.h>

//The harder version of the mario problem
//Creates a pyramid based on a height
//ex:
//     ##  ##
//    ###  ###
//   ####  ####
// height = 3

int main(void) {
    //Initialize height to zero
    int height = 0;
    
    //Keep asking for so long as the user does not
    //enter a height greater than 0 and lesser than 23
    do {
        //Get height from user
        printf("Height: ");
        height = get_int();
        
        if(height == 0) { return 0; }
    } while(height < 1 || height > 23);
    
    //Repeat for every level of height
    for(int y = 0; y < height; y++) {
        //Calculates the number of spaces needed
        //before the #s on the left and prints them
        for(int x = 0; x < (height - y)-1; x++) {
            printf(" ");
        }
        
        //Calculates the number of #s needed for
        //this height's left side and print them
        for(int x = 0; x < y + 1; x++) {
            printf("#");
        }
        
        //Print the two spaces before the right
        //side of the pyramid
        printf("  ");
        
        //Calculates the number of #s needed for
        //this height's right side and print them
        for(int x = 0; x < y + 1; x++) {
            printf("#");
        }
        
        //Prints new line before next level of height
        printf("\n");
    }
}