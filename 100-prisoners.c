/*************************
Program Name: 100-prisoners.c
Programmer: Miguel Lock

Class: CSC-310
Instructor: Dr. John Coleman
Date: 10/02/23
Version: 1.0

EXTRA CREDIT:
1. I am using my own PRNG
2. Allows user input for the number of prisoners
3. Allows user input for the number of iterations
4. 
*************************/
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

// .31183

void swap(int *a, int *b);
void shuffle(int *array, int size);
void initialize_room(int *room, int num_prisoners);
bool prisoner_finds_number(int target, int *num_success, int *free_prisoners, int *room, int num_prisoners);
bool all_find_numbers(int *room, int num_prisoners);

int main() {
    int iterations = 0, escapes = 0, num_prisoners = 0;
    double chance_escapes;

    // prepares the rand function
    srand(time(NULL));

    while (num_prisoners < 100 || num_prisoners > 2000 || num_prisoners % 100 != 0) {
        printf("Enter the number of prisoners?\n(Suggested: 100): ");
        scanf("%d", &num_prisoners);

        if (num_prisoners < 100 || num_prisoners > 2000 || num_prisoners % 100 != 0) {
            printf("Error: Number of prisoners must be a multiple of 100 from 100-2000.\n\n");
        }
    }
    printf("\n\n");

    while (iterations > 1000000 || iterations < 1) {
        printf("How many times do you want this program to run?\n(Suggested: 1000000): ");
        scanf("%d", &iterations);

        if (iterations > 1000000 || iterations < 1) {
            printf("Error: Number of iterations must be between 1 and 1000000\n\n");
        }
    }
    printf("\n");

    int room[num_prisoners+1];
    for (int i=0; i < iterations; i++) {
        initialize_room(room, num_prisoners);
        if (all_find_numbers(room, num_prisoners)) {
            escapes++;
        }
    }
    chance_escapes = (double)escapes / iterations;

    printf("\nEscapes: %d\nIterations: %d\n", escapes, iterations);
    printf("Chance of escaping: %f", chance_escapes);

    return 0;
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
void shuffle(int *array, int size) {
    int i, j;

    for (i=size; i>0; i--) {
        j = rand() % (i);
        if (j == 0) {
            j = i;
        }
        swap(&array[i], &array[j]);
    }
}

// sets variables in room[] to values 1-num_prisoners
void initialize_room(int *room, int num_prisoners) {
    for (int i=1; i<num_prisoners+1; i++) {
        room[i] = i;
    }
    shuffle(room, num_prisoners);
}

// returns bool if prisoner finds their number
bool prisoner_finds_number(int target, int *num_success, int *free_prisoners, int *room, int num_prisoners) {
    int steps = 1;
    int temp_next = target;

    while (room[temp_next] != target) {
        steps++;
        free_prisoners[temp_next]++; // if prisoner n is in the loop: free_prisoners[n]++ for later efficiency
        if (steps > num_prisoners / 2) {
            return 0;
        }
        else { temp_next = room[temp_next]; }
    }
    free_prisoners[temp_next]++;
    *num_success += steps; // adds the number of prisoners in the loop to num_success

    return 1;
}

// returns bool if all prisoners actually escape
bool all_find_numbers(int *room, int num_prisoners) {
    int result, num_success = 0, target = 1;
    int free_prisoners[num_prisoners+1];

    for (int i=0; i<num_prisoners+1; i++) {
        free_prisoners[i] = 0;
    }

    while (num_success < num_prisoners/2) {
        result = prisoner_finds_number(target, &num_success, free_prisoners, room, num_prisoners);
        if (result == 0) {

            return 0;
        }
        while (free_prisoners[target] >= 1) {
            target += 1;
        }
    }

    return 1;
}
