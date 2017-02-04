#include <cs50.h>
#include <stdio.h>

//Water problem
// Takes in a number of minutes 
// and prints out number of ounces
// and water bottles it's equivelent to.
// ex.
// 5 minutes = 960 ounces = 60 Water bottles

int main(void) {
    //Get minutes in shower from user
    printf("Minutes In shower: ");
    int minutes = get_int();
    //Convert minutes to ounces
    float ounces = (minutes * 1.5) * 128;
    //Print ounces used and number of water bottles would be equivalent
    printf("Ounces Of Water: %.4f\n", ounces);
    printf("Water Bottles Used: %.2f\n", ounces / 16);
}