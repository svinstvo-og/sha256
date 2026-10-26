#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// input to byte arr
//uint8_t* 
uint8_t* toByteArr(char* message) {
    uint8_t *message_bytes = malloc(strlen(message));

    for (int i = 0; i < strlen(message) ; i++) {
        message_bytes[i] = (uint8_t) message[i];
        //printf("%u\n", (uint8_t) message[i]);
    }

    return message_bytes;
}

void printByteArr(uint8_t* arr[]) {
    for (int i = 0; i < sizeof(*arr) / 8; i++) {
        printf("a");
    }
}

//int[] pad(int* message[]) {}

// divide into block[]

// sigma 0-1

// Sigma 0-1

// choice 

// majority

// calc constants
    // calc initial hash values H0-H7
    // calc K0-K63

// assign words

// caclulate remaining words
// word calculation function

// for int 0-63:
    // set working variables & process iteration
// update hash values H0-H7

// base 16 encode & return

int main(int argc, char* argv[]) {
    //printf("%s\n", argv[1]);
    printByteArr(toByteArr(argv[1]));
    return 0;
}