#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, string argv[]) {
    
    //Check if there is only one argument after ./vigenere
    if(argc != 2) {
        printf("Please enter correct arguments: ./vigenere <key>(string)\n");
        return 1;
    }
    
    //Check if all chars in the key argument are alphabetical
    for(int i = 0; i < strlen(argv[1]); i++) {
        if(isalpha(argv[1][i]) == false) {
            printf("Please enter correct arguments: ./vigenere <key>(string)\n");
            return 1;
        }
    }
    
    //Set key variable to key argument
    string key = argv[1];
    
    //Get plaintext to encipher
    printf("plaintext: ");
    string enciphered = get_string();
    
    //Array of the alphabet to use as place to grab letters based on their alphabetical index     
    char alpha[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
   
    //Index of the current char being used in the key variable
    int keyIndex = 0;
    
    //For loop to go over every char in the plaintext string ("enciphered")
    for(int i = 0; i < strlen(enciphered); i++) {
        
        //Get the alphabetical index of the current char in the key variable        
        int keyAlphaIndex = 0;
        if(islower(key[keyIndex])) {
            keyAlphaIndex = (26 - (26 - (key[keyIndex]-97)));
        } else if(isupper(key[keyIndex])) {
            keyAlphaIndex = (26 - (26 - (key[keyIndex]-65)));
        }
        
        //Get the alphabetical index of the current char in the plaintext variable ("enciphered")
        int alphaIndex = 0;
        if(islower(enciphered[i])) {
            //Subtracts 97 (lower a in ascii) from current char, then subtracts 26 and 
            //then 26 again to flip it and than adds key and mods 26
            alphaIndex = ((26 - (26 - (enciphered[i]-97))) + keyAlphaIndex) % 26;
            enciphered[i] = alpha[alphaIndex];
        } else if(isupper(enciphered[i])) {
            //Subtracts 65 (upper 'A' in ascii) from current char, then subtracts 26 and 
            //then 26 again to flip it and than adds key and mods 26
            alphaIndex = ((26 - (26 - (enciphered[i]-65))) + keyAlphaIndex) % 26;
            enciphered[i] = toupper(alpha[alphaIndex]);
        }
        
        //Increment keyIndex if it is not at the end but if it is then loop back to place 0
        if(isalpha(enciphered[i])) {
            if(keyIndex >= strlen(key)-1) {
                keyIndex = 0;   
            } else {
                keyIndex++;
            }
        }
    }
        
    printf("ciphertext: %s\n", enciphered);
}