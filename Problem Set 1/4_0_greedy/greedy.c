#include <cs50.h>
#include <stdio.h>
#include <math.h>

//Greedy problem
// Takes in a value of change owed and 
// prints out the minimum number of 
// coins required to pay them back
// using 25c, 10c, 5c and 1c

int main(void) {
    
    float changeOwed = 0.00;
    
    do {
        //Get change owed
        printf("Change Owed: ");
        changeOwed = get_float();
    } while(changeOwed <= 0.00);
    
    //ChangeCents converted to rounded up
    //int to get rid of imprecision
    int changeCents = (int)(roundf(changeOwed * 100));
    int coins = 0;
    
    do {
        //If changeCents is greater than 25,
        // subtract 25 cents
        if(changeCents >= 25) {
            changeCents = changeCents - 25;
            coins++;
        
        //If changeCents is greater than 10,
        // subtract 10 cents
        } else if(changeCents >= 10) {
            changeCents = changeCents - 10;
            coins++;
        
        //If changeCents is greater than 5,
        // subtract 5 cents
        } else if(changeCents >= 5) {
            changeCents = changeCents - 5;
            coins++;
            
        //If changeCents is greater than 1,
        // subtract 1 cents
        } else if(changeCents >= 1) {
            changeCents = changeCents - 1;
            coins++;
        }
    } while(changeCents > 0);
    
    //Print coins needed
    printf("%d\n", coins);
    
}