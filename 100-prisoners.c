/*************************
Program Name: 100-prisoners.c
Programmer: Miguel Lock

Class: CSC-310
Instructor: Dr. John Coleman
Date: 9/13/23
Version: 1.0
*************************/

#include <stdio.h>
#include <stdbool.h> //for boolean
#include <time.h>
#include <stdlib.h>
#define NUM_PRISONERS 100

/*
Functions:
1. Initialize room with random permutation of 1-100 (length 101 array, index 1-100 have numbers 1-100)
2. Given a prisoner number and the room, determine if the prisoner finds their number in a most 50 steps
3. Given a room, determine if all prisoners find their numbers

run the last function on a large number (ex: 100,0000) of randomly chosen rooms, and estimate the probabiliy that all prisoners find their number


Extra credit:
 - Find a clever way to implement the third funcion above that doesn't simply call the second funciton in a nieve loop
     - Hint: if a prisoner finds their nmber in a chain of 20 numbers, all of the other prisoners on the chain will find their number
     - Self hint: if >50 prisoners find their number, every prisoner has found their number
 - Implement your own random number generator, a better on ethan the standard library rand()
     - Alternatively, find a way to use the Mersenne Twistor using code that you include with your project
 - Investigate what happens as the number of prisoners tends to infinity.
     - Ex: exompile a tabl of values for 100, 200, 300, ..., 2000
 - Anything else I can think of in C and clearly related to the project    


______
cout << "How many times would you like to simulate the 100 prisoner problem?\n>"
cout << "do you want more to try a custom number of prisoners? (y/n)\n>"
if y:
cout << "How many prisoners are we talking about?\n>"
*/

// swaps two ints
// must pass in *a and *b by address using the & operator
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// shuffles the array
void shuffle(int *array, int size) {
    int i, j, temp;

    for (i=size-1; i>1; i--) {
        j = rand() % (i+1);
        swap(&array[i], &array[j]);
    }
}

// sets variables in room[] to values 1-num_prisoners
void initialize_room(int *room) {
    for (int i=0; i<NUM_PRISONERS; i++) {
        room[i] = i;
    }
    shuffle(room, NUM_PRISONERS);
}

bool prisoner_finds_number(int target, int *num_success, int *prisoners_remaining, int *room) {//(int id) {
    int steps = 1;
    int temp_next = target;

    while (room [temp_next] != target) {
        steps++;
        prisoners_remaining[temp_next]++;
        if (steps > 50) { return 0; }
        else { temp_next = room[temp_next]; }
    }

    return 1; // would return 1 if it works
}


// IDEA FOR MORE EFFICIENCY: FOUND ITEMS IN ROOM ARE SET TO 0. THEN 
// ITEMS 

bool all_find_numbers(int *room) {
    int num_success = 0; //count of numbeer of prisoners that found their numbers
    int fail = 1;

    int prisoners_remaining[NUM_PRISONERS+1];
    
    for (int i=1; i < NUM_PRISONERS+1; i++) {
        prisoners_remaining[i] = i;
    }

    int free_prisoners[NUM_PRISONERS+1] = { 0 }; // if prisoner 2 was freed, free_prisoners[2] = 1;

    int target = 1;

    while (num_success < 50) {
        int result = prisoner_finds_number(target, &num_success, prisoners_remaining, room);
        if (result = 0) { fail = 1; }
        //set target value
        for (int i=0; i<NUM_PRISONERS/2; i++) {
            //target = 
        }
    }


    //prisoners_remaining will be fed into prisoner_finds_number, 
    //all prisoners who find their number will be set to 0. That is how we
    //determine which prisoner we should check for next. Lateron, might 

    //something with prisoner_finds_number()
    // if num_successful_prisoner > 50: return true
}

int main() {
    int iterations = 1;
    int room[NUM_PRISONERS];
    int escapes = 0;


    // int num_prisoners = userinput, must be multiple of 100. bool stop = num_prisoners mod 100, if stop = 0 we have a valid value.

    for (int i=0; i < iterations; i++) {
        printf("1");

        bool prisoners_are_free;
        initialize_room(room);

        bool prisonsers_are_free = all_find_numbers(room);
        if (prisoners_are_free) { escapes++; }
    }

    return 0;
}