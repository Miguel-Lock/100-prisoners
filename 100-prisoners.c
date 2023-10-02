/*************************
Program Name: 100-prisoners.c
Programmer: Miguel Lock

Class: CSC-310
Instructor: Dr. John Coleman
Date: 9/22/23
Version: 1.0
*************************/

#include <stdio.h>
#include <stdbool.h> //for boolean
#include <time.h>
#include <stdlib.h>
#define NUM_PRISONERS 2

// .31183

void swap(int *a, int *b);
void shuffle(int *array, int size);
void initialize_room(int *room);
bool prisoner_finds_number(int target, int *num_success, int *free_prisoners, int *room);
bool all_find_numbers(int *room);


int main() {
    int iterations = 0, escapes = 0;
    int room[NUM_PRISONERS+1];
    double chance_escapes;
    int num_prisoners = 0;

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

    for (int i=0; i < iterations; i++) {
        initialize_room(room);
        if (all_find_numbers(room)) {
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
void initialize_room(int *room) {
    for (int i=1; i<NUM_PRISONERS+1; i++) {
        room[i] = i;
    }
    shuffle(room, NUM_PRISONERS);
}

// returns bool if prisoner finds their number
bool prisoner_finds_number(int target, int *num_success, int *free_prisoners, int *room) {
    int steps = 1;
    int temp_next = target;

    while (room[temp_next] != target) {
        steps++;
        free_prisoners[temp_next]++; // if prisoner n is in the loop: free_prisoners[n]++ for later efficiency
        if (steps > NUM_PRISONERS / 2) {
            return 0;
        }
        else { temp_next = room[temp_next]; }
    }
    free_prisoners[temp_next]++;
    *num_success += steps; // adds the number of prisoners in the loop to num_success

    return 1;
}

// returns bool if all prisoners actually escape
bool all_find_numbers(int *room) {
    int result, num_success = 0, target = 1;
    int free_prisoners[NUM_PRISONERS+1] = { 0 };

    while (num_success < NUM_PRISONERS/2) {
        result = prisoner_finds_number(target, &num_success, free_prisoners, room);
        if (result == 0) {
            return 0;
        }
        while (free_prisoners[target] >= 1) {
            target += 1;
        }
    }

    return 1;
}
