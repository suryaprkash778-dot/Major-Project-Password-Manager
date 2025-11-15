#include "encryption.h"

void xor_encrypt(char *str, char key) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] ^= key;
    }
}
