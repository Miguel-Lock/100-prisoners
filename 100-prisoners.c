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

int NUM_PRISONERS = 100;

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

void initialize_room() {
    // this would initialize a room90 size num_prisoners
    /*
    // pass room[] into function by reference
    for i in num_prisoners:
        room[i] = i;
    shuffle(room[])
    return void;
    */
}

bool prisoner_finds_number(int id) {
    int steps = 0;

    // if steps > 50, return 0

    // takes the room stuff
    // passes back array of 51 where arr[0] is number of prisoners on his loop
    // this only runs if prisoner_finds == 1
    return 0; // would return 1 if it works
}

bool all_find_numbers() {
    int num_success = 0; //count of numbeer of prisoners that found their numbers
    int prisoners_remaining[NUM_PRISONERS];
    
    for (i=-; i < NUM_PRISONERS; i++) {
        prisoners_remaining[i] = i;
    }

    //prisoners_remaining will be fed into prisoner_finds_number, 
    //all prisoners who find their number will be set to 0. That is how we
    //determine which prisoner we should check for next. Lateron, might 

    //something with prisoner_finds_number()
    // if num_successful_prisoner > 50: return true
}

int main() {
    int iterations = 1;

    // int num_prisoners = userinput, must be multiple of 100. bool stop = num_prisoners mod 100, if stop = 0 we have a valid value.

    for (i=0; i < iterations, i++) {
        bool prisoners_are_free;
        // initialize room[] size NUM_PRISONERS
        int room[NUM_PRISONERS];
        initialize_room(); //pass in room[] by reference

        bool prisonsers_are_free = all_find_numbers();
    }

    return 0;
}