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
#define NUM_PRISONERS 100


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

    for (i=size-1; i>1; i--) {
        j = rand() % (i);
        if (j == 0) { j = i; }
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

bool prisoner_finds_number(int target, int *num_success, int *free_prisoners, int *room) {
    int steps = 1;
    int temp_next = target;

    while (room[temp_next] != target) {
        steps++;
        free_prisoners[temp_next]++;
        if (steps > 50) {
            return 0;
        }
        else { temp_next = room[temp_next]; }
    }
    free_prisoners[temp_next]++;
    *num_success += steps;

    return 1; // would return 1 if it works
}


bool all_find_numbers(int *room) {
    int result, num_success = 0, target = 1;
    int free_prisoners[NUM_PRISONERS+1] = { 0 };

    while (num_success < 50) {
        result = prisoner_finds_number(target, &num_success, free_prisoners, room);
        if (result == 0) { return 0; }
        while (free_prisoners[target] < 1) {
            target = target += 1;
        }
    }

    return 1;
}

int main() {
    int iterations = 1000000, escapes = 0;
    int room[NUM_PRISONERS+1];
    bool prisoners_are_free;
    double chance_escapes;

    // prepares the rand function
    srand(time(NULL));

    for (int i=0; i < iterations; i++) {
        initialize_room(room);
        
        if (all_find_numbers(room)) { escapes++; }
    }
    
    chance_escapes = (double)escapes / iterations;

    printf("\nEscapes: %d\nIterations: %d\n", escapes, iterations);
    printf("Percentage chance of escapes: %f", chance_escapes);

    return 0;
}