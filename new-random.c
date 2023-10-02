#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Mersenne Twister parameters
#define MT_N 624
#define MT_MATRIX_A 0x9908B0DFUL
#define MT_UPPER_MASK 0x80000000UL
#define MT_LOWER_MASK 0x7FFFFFFFUL

static unsigned long mt[MT_N];
static int mti = MT_N + 1;

// Initialize the generator with a seed
void init_genrand(unsigned long s) {
    mt[0] = s & 0xFFFFFFFFUL;
    for (mti = 1; mti < MT_N; mti++) {
        mt[mti] = (1812433253UL * (mt[mti - 1] ^ (mt[mti - 1] >> 30)) + mti);
        mt[mti] &= 0xFFFFFFFFUL;
    }
}

// Generate a random unsigned long
unsigned long genrand_int32(void) {
    int mt_m = 397;
    unsigned long y;
    static unsigned long mag01[2] = {0x0UL, MT_MATRIX_A};

    if (mti >= MT_N) {
        int kk;

        if (mti == MT_N + 1)  // Initialize with a default seed if not already initialized
            init_genrand(5489UL);

        for (kk = 0; kk < MT_N - mt_m; kk++) {
            y = (mt[kk] & MT_UPPER_MASK) | (mt[kk + 1] & MT_LOWER_MASK);
            mt[kk] = mt[kk + mt_m] ^ (y >> 1) ^ mag01[y & 0x1UL];
        }
        for (; kk < MT_N - 1; kk++) {
            y = (mt[kk] & MT_UPPER_MASK) | (mt[kk + 1] & MT_LOWER_MASK);
            mt[kk] = mt[kk + (mt_m - MT_N)] ^ (y >> 1) ^ mag01[y & 0x1UL];
        }
        y = (mt[MT_N - 1] & MT_UPPER_MASK) | (mt[0] & MT_LOWER_MASK);
        mt[MT_N - 1] = mt[mt_m - 1] ^ (y >> 1) ^ mag01[y & 0x1UL];
        mti = 0;
    }

    y = mt[mti++];
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9D2C5680UL;
    y ^= (y << 15) & 0xEFC60000UL;
    y ^= (y >> 18);

    return y;
}

int main() {
    // Seed the generator with the current time
    unsigned long seed = (unsigned long)time(NULL);
    init_genrand(seed);

    // Generate and print random numbers
    printf("%lu\n", genrand_int32());

    return 0;
}
