#include <stdio.h>

char characters[] = {'\0', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int numCharacters = sizeof(characters) / sizeof(char);

int main() {
    long indices[] = {0, 0, 0, 0, 0, 0, 0, 0};  // Update the size of this array according to the desired combination length

    while (1) {
        for (int i = 0; i < sizeof(indices) / sizeof(long); i++) {
            putchar(characters[indices[i]]);
        }
        putchar('\n');

        int carry = 1;
        for (int i = sizeof(indices) / sizeof(long) - 1; i >= 0; i--) {
            indices[i] += carry;
            carry = indices[i] / numCharacters;
            indices[i] %= numCharacters;
        }

        if (carry > 0) {
            // Overflow, reset indices
            for (int i = 0; i < sizeof(indices) / sizeof(long); i++) {
                indices[i] = 0;
            }
        }
    }

    return 0;
}
