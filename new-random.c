#include <stdio.h>
#include <openssl/rand.h>

int main() {
    if (RAND_status() == 0) {
        printf("Error: OpenSSL random number generator not properly seeded.\n");
        return 0;
    }

    unsigned char random_data[32]; // Adjust the size as needed
    if (RAND_bytes(random_data, sizeof(random_data)) != 1) {
        printf("Error: Failed to generate random bytes.\n");
        return 0;
    }

    printf("Random Data: ");
    for (int i = 0; i < sizeof(random_data); i++) {
        printf("%02X", random_data[i]);
    }
    printf("\n");

    return 0;
}
