#include <stdio.h>
#include <stdbool.h> //for boolean


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
    // this would initialize a room
    // room array would be shared via reference
}

bool find_number(int id) {
    // takes the room stuff
    // passes back array of 51 where arr[0] is number of prisoners on his loop
    // this only runs if prisoner_finds == 1
    return 0; // would return 1 if it works
}


int main() {
    char name[10] = "Miguel";
    int age = 18;

    printf("Hello, %s. You are %i years old.", name, age);

    return 0;
}