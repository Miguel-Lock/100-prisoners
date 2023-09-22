/*************************
Program Name: HW5.c
Programmer: Miguel Lock

Class: CSC-310
Instructor: Dr. John Coleman
Date: 9/22/23
Version: 1.0
*************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 20


// sets sequential values in the array, starting at 1
void set_values(int *array) {
    for (int i=0; i<SIZE; i++)
        array[i] = i+1;
}


// prints the array in a pretty format
void print_arr(int *array) {
    printf("[ ");
    for (int i=0; i<SIZE - 1; i++) {
        printf("%d, ", array[i]);
    }
    printf("%d ]\n", array[SIZE-1]);
}


// swaps two ints
// must pass in *a and *b by address using the & operator
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


// shuffles the array from indeces 1-size
// array[0] stays the same
void shuffle(int *array, int size) {
    int i, j;

    for (i=size-1; i>1; i--) {
        j = rand() % (i);
        if (j == 0) { j = i; }
        swap(&array[i], &array[j]);
    }
}


// shuffles the array in the opposite direction
// functionally identical to shuffle(array)
void opp_shuffle(int *array) {
    int i, j, temp;

    for (i=0; i<SIZE-2; i++) {
        j = i + rand() % (SIZE - i);
        swap(&array[i], &array[j]);
    }
}


int main() {
    int array[SIZE];
    set_values(array); // sets array values to sequential 1-SIZE

    srand(time(NULL)); // prepares the rand function

    printf("Sorted Array:\n");
    print_arr(array); // prints the sorted array

    shuffle(array, SIZE); // randomly shuffles array contents
    printf("Array, shuffled by method shuffle(array):\n");
    print_arr(array);


    return 0;
}