#include <stdio.h>

// ===== Function Prototypes =====
void encodeMessage(char message[]);
void decodeMessage(char message[]);
void reverseString(char str[]);
char toggleBits(char ch);
int getLength(char str[]); // manual strlen()

int main() {
    int choice,i;
    char message[200];   // Buffer to store user message

    do {
        printf("\n=== TCS Secure Communication System ===\n");
        printf("1. Encode Message\n");
        printf("2. Decode Message\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline in buffer

        switch (choice) {
            case 1:
                printf("\nEnter the message to ENCODE: ");
                fgets(message, 200, stdin);
                

                // Remove newline manually
                for ( i = 0; message[i] != '\0'; i++) {
                    if (message[i] == '\n') {
                        message[i] = '\0';
                        break;
                    }
                }

                encodeMessage(message);
                break;

            case 2:
                printf("\nEnter the message to DECODE: ");
                fgets(message, 200, stdin);
                

                // Remove newline manually
                for (i = 0; message[i] != '\0'; i++) {
                    if (message[i] == '\n') {
                        message[i] = '\0';
                        break;
                    }
                }

                decodeMessage(message);
                break;

            case 0:
                printf("\nExiting system... Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}

/*==========================================================
   Function: getLength
   Description: Finds length of string manually
==========================================================*/
int getLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

/*==========================================================
   Function: reverseString
   Description: Reverses a string in place
==========================================================*/
void reverseString(char str[]) {
    int i,len = getLength(str);
    for (i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

/*==========================================================
   Function: toggleBits
   Description: Toggles 2nd and 5th bits of a character
   Bit positions start from 0 (LSB = bit 0)
==========================================================*/
char toggleBits(char ch) {
    ch = ch ^ (1 << 1);  // Toggle 2nd bit
    ch = ch ^ (1 << 4);  // Toggle 5th bit
    return ch;
}

/*==========================================================
   Function: encodeMessage
   Description: Encodes the given message
==========================================================*/
void encodeMessage(char message[]) {
    reverseString(message);  // Step 1: reverse
int i;
    for ( i = 0; message[i] != '\0'; i++) {
        message[i] = toggleBits(message[i]);  // Step 2: toggle bits
    }

    printf("\nEncoded Message:\n%s\n", message);
}

/*==========================================================
   Function: decodeMessage
   Description: Decodes the given message
==========================================================*/
void decodeMessage(char message[]) {
	int i;
    for ( i = 0; message[i] != '\0'; i++) {
        message[i] = toggleBits(message[i]);  // Step 1: untoggle bits
    }

    reverseString(message);  // Step 2: reverse again
    printf("\nDecoded Message:\n%s\n", message);
}

