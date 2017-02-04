#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Caesar cypher problem
// Takes in a plaintext and shifts
// each character by a int called a key 

int main(int argc, string argv[]) {
    if(argc == 2 && atoi(argv[1]) >= 0) {
        //Convert string key to an int
        int key = atoi(argv[1]);
        
        //Get plaintext from user
        printf("plaintext: ");
        string enciphered = get_string();
        
        //Create alphabet to get a letter by it's alphabetical index
        char alpha[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        
        //See if current char is upper or lower case and perform c = (p + key) % 26
        // on it
        for(int i = 0; i < strlen(enciphered); i++) {
            if(islower(enciphered[i])) {
                //Subtracts 97 (lower a in ascii) from current char, then subtracts 26 and 
                //then 26 again to flip it and than adds key and mods 26
                int alphaIndex = ((26 - (26 - (enciphered[i]-97))) + key) % 26;
                enciphered[i] = alpha[alphaIndex];
            } else if(isupper(enciphered[i])) {
                //Subtracts 65 (upper A in ascii) from current char, then subtracts 26 and 
                //then 26 again to flip it and than adds key and mods 26
                int alphaIndex = ((26 - (26 - (enciphered[i]-65))) + key) % 26;
                enciphered[i] = toupper(alpha[alphaIndex]);
            }
        }
        
        printf("ciphertext: %s\n", enciphered);
    } else {
        printf("Please enter correct arguments: ./caesar <key>\n");
        return 1;
    }
}