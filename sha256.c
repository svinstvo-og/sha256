#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

struct arr {
    size_t len;
    uint8_t messageBytes[];
};

// convert input message to byte arr
uint8_t* toByteArr(char* message) {
    uint8_t *message_bytes = malloc(strlen(message));

    for (int i = 0; i < strlen(message) ; i++) {
        message_bytes[i] = (uint8_t) message[i];
    }

    return message_bytes;
}

void printByteArr(uint8_t arr[], size_t len) {
    for (int i = 0; i < len; i++) {
        printf("%hhu ", arr[i]);
    }
    printf("\n");
}

// function takes in byte arr, checks its len, and padds
// it so it is a multiple of 512 bits (512/8 = 64 bytes)
struct arr* pad(uint8_t* rawMessage, size_t len) {
    // find how much bytes we need to append to pad message
    uint8_t bytesToPad = 64 - len;
    bytesToPad = bytesToPad % 64;

    // if we cant fit message size (8 bytes + 1 0x80 byte), round up padding
    if (bytesToPad < 9) bytesToPad += 64;
    unsigned long paddedLen = len + bytesToPad;

    printf("raw message size in bytes %zu\n", len);
    printf("bytes to pad: %hhu\n", bytesToPad);
    
    // len variable + arr length in bytes * 8 bits
    struct arr* pPaddedBytes = malloc(sizeof(size_t) + paddedLen * 8);

    pPaddedBytes->len = paddedLen;

    // copy bytes from raw message
    for (int i = 0; i < len; i++) {
        pPaddedBytes->messageBytes[i] = rawMessage[i];
    }

    // add 0x80 byte to mark end of message
    pPaddedBytes->messageBytes[len] = 0x80; // 1000 0000

    // populate remaining bytes with zeros
    if (bytesToPad > 1) {
        for (int i = len+1; i < paddedLen; i++) {
            pPaddedBytes->messageBytes[i] = 0;
        }
    }
    
    // todo adequately make size 8 bytes instead of 1
    pPaddedBytes->messageBytes[paddedLen-1] = len;

    return pPaddedBytes;
}

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
    if (argc < 2) {
        printf("pass the message to hash, dumbass\n");
        return 0;
    }
    if (strlen(argv[1]) > 255) {
        printf("for now message is capped to 255 chars :(\n");
        return 0;
    }
    //printf("%s\n", argv[1]);
    uint8_t *pMessageBytes = toByteArr(argv[1]);

    printByteArr(pMessageBytes, strlen(argv[1]));

    struct arr *pPaddedBytes = pad(pMessageBytes, strlen(argv[1])); 

    printByteArr(pPaddedBytes->messageBytes, pPaddedBytes->len);

    // free(pMessageBytes);
    // printf("%s", pMessageBytes);
    return 0;
}