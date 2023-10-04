/*************************
Program Name: 100-prisoners.c
Programmer: Miguel Lock

Class: CSC-310
Instructor: Dr. John Coleman
Date: 10/03/23
Version: 1.0

Chance: .31183
Extra Credit:
1. Allows user input for the number of prisoners
2. Allows user input for the number of iterations
3. Added my own PRNG (mersene twister) (source: chatGPT)
4. Optimized program (If a prisoner finds their number in a chain
of 20 numbers, all prisoners find their number)

Questions:
1. How to show extra credit
2. Is line at //QUESTION: IS THIS WHAT I WANT HERE correct?
3. Is my answer correct for 2000 prisoners and 10000 iterations?
*************************/
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

// for mersene twister
#define MT_N 624
#define MT_MATRIX_A 0x9908B0DFUL
#define MT_UPPER_MASK 0x80000000UL
#define MT_LOWER_MASK 0x7FFFFFFFUL

//for mersene twister
static unsigned long mt[MT_N];
static int mti = MT_N + 1;

int get_num_prisoners();
int get_num_iterations();
void swap(int *a, int *b);
void shuffle(int array[], int size);
void initialize_room(int room[], int num_prisoners);
bool prisoner_finds_number(int target, int *num_success, int free_prisoners[], int room[], int num_prisoners);
bool all_find_numbers(int room[], int num_prisoners);
unsigned long genrand_int32(void);
void init_genrand(unsigned long s);


int main() {
    int num_prisoners, iterations, escapes = 0;
    double chance_escapes;

    init_genrand((unsigned long)time(NULL)); //seeds mersene twister

    num_prisoners = get_num_prisoners();
    int room[num_prisoners+1];

    iterations = get_num_iterations();

    // runs simulation "iterations" times, to see the chance of the prisoners escaping
    for (int i=0; i < iterations; i++) {
        initialize_room(room, num_prisoners);
        if (all_find_numbers(room, num_prisoners)) {
            escapes++;
        }
    }
    chance_escapes = (double)escapes / iterations;

    // displays results
    printf("\nEscapes: %d\nIterations: %d\n", escapes, iterations);
    printf("Chance of escaping: %f", chance_escapes);

    return 0;
}


// gets user input for num_prisoners
// 100 < num_prisoners < 2000, && num_prisoners is multiple of 100
int get_num_prisoners() {
    int num_prisoners = 0;
    while (num_prisoners < 100 || num_prisoners > 2000 || num_prisoners % 100 != 0) {
        printf("Enter the number of prisoners?\n(Suggested: 100): ");
        scanf("%d", &num_prisoners);

        if (num_prisoners < 100 || num_prisoners > 2000 || num_prisoners % 100 != 0) {
            printf("Error: Number of prisoners must be a multiple of 100 from 100-2000.\n\n");
        }
    }
    printf("\n\n");

    return num_prisoners;
}

// gets user input for iterations
// 1 < iterations < 10000000
int get_num_iterations() {
    int iterations = 0;
    while (iterations > 10000000 || iterations < 1) {
        printf("How many times do you want this program to run?\n(Suggested: 1000000): ");
        scanf("%d", &iterations);

        if (iterations > 10000000 || iterations < 1) {
            printf("Error: Number of iterations must be between 1 and 10000000\n\n");
        }
    }
    printf("\n");

    return iterations;
}

// swaps two ints
// must pass in *a and *b by address using the & operator
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// shuffles the array from index 1-size
// array[0] stays the same
void shuffle(int array[], int size) {
    int i, j;
    for (i=size; i>0; i--) {
        // gets random number from 1-i
        j = genrand_int32() % i;
        if (j == 0) {
            j = i;
        }
        swap(&array[i], &array[j]);
    }
}

// sets variables in room[] to values 1-num_prisoners, starting at room[1]
void initialize_room(int room[], int num_prisoners) {
    for (int i=1; i<num_prisoners+1; i++) {
        room[i] = i;
    }
    shuffle(room, num_prisoners);
}

// returns bool if prisoner (target) finds their number
// increments free_prisoners (ADD MORE TO DESCPTION)
bool prisoner_finds_number(int target, int *num_success, int free_prisoners[], int room[], int num_prisoners) {
    int steps = 1, temp_next = target;

    while (room[temp_next] != target) {
        steps++;
        free_prisoners[temp_next]++; //if prisoner[temp_next] is in the loop: documents so that prisoner isn't checked for again

        // returns 0 if prisoner did not find their number in the alloted number of steps
        if (steps > num_prisoners / 2) { //QUESTION: IS THIS WHAT I WANT HERE
            return 0;
        } else {
            temp_next = room[temp_next];
        }
    }
    free_prisoners[temp_next]++;
    *num_success += steps; //adds the number of prisoners found in the loop to num_success

    return 1;
}

// returns bool indicating if all prisoners escape
bool all_find_numbers(int room[], int num_prisoners) {
    int num_success = 0, target = 1, free_prisoners[num_prisoners+1];

    // initializes contents of free_prisoners to 0
    for (int i=0; i<num_prisoners+1; i++) {
        free_prisoners[i] = 0;
    }

    while (num_success < num_prisoners/2) { //QUESTION: IS THIS WHAT I WANT HERE
        //if prisoner doesn't find their number: return 0
        if (!prisoner_finds_number(target, &num_success, free_prisoners, room, num_prisoners)) {
            return 0;
        }
        //calculates next target prisoner
        while (free_prisoners[target] >= 1) {
            target += 1; 
        }
    }

    return 1;
}


// Initialize the generator with a seed
// Part of mersene twister
void init_genrand(unsigned long s) {
    mt[0] = s & 0xFFFFFFFFUL;
    for (mti = 1; mti < MT_N; mti++) {
        mt[mti] = (1812433253UL * (mt[mti - 1] ^ (mt[mti - 1] >> 30)) + mti);
        mt[mti] &= 0xFFFFFFFFUL;
    }
}

// Generate a random unsigned long
// Part of mersene twister
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