/*************************
Program Name: HW5.c
Programmer: Miguel Lock

Class: CSC-310
Instructor: Dr. John Coleman
Date: 9/22/23
Version: 2.0
*************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 5
#define TIMES 10000000


// sets sequential values in the array, starting at 1
void set_values(int *array) {
    for (int i=0; i<SIZE; i++)
        array[i] = i+1;
}


// sets all values in arr2d to 0;
void set_zero_2d(int arr2d[SIZE][SIZE]) {
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            arr2d[i][j] = 0;
        }
    }
}


// prints the array in a pretty format
void print_arr(int *array) {
    printf("[ ");
    for (int i=0; i<SIZE - 1; i++) {
        printf("%d, ", array[i]);
    }
    printf("%d ]\n", array[SIZE-1]);
}


// prints the 2d array as a matrix
void print2DArray(int rows, int cols, int arr[SIZE][SIZE]) {
    for (int i = 0; i < rows; i++) {
        printf("[ ");
        for (int j = 0; j < cols; j++) {
            printf("%d", arr[i][j]);
            if (j < cols - 1) {
                printf(", ");
            }
        }
        printf(" ]\n");
    }
}


// swaps two ints
// must pass in *a and *b by address using the & operator
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


// shuffles the array
void shuffle(int *array, int arr2d[SIZE][SIZE]) {
    int i, j, temp;

    for (i=SIZE-1; i>1; i--) {
        j = rand() % (i);
        if (j == 0) { j = i; }
        swap(&array[i], &array[j]);
    }

    // adds counter to 2d array for randomness-verification
    for (i=0; i<SIZE; i++) {
        arr2d[array[i]-1][i] += 1;
    }  
}

// shuffles the array in the opposite direction
// functionally identical to shuffle(array)
void opp_shuffle(int *array, int arr2d[SIZE][SIZE]) {
    int i, j, temp;

    for (i=0; i<SIZE-2; i++) {
        j = i + rand() % (SIZE - i);
        swap(&array[i], &array[j]);
    }

    // adds counter to 2d array for randomness-verification
    for (i=0; i<SIZE; i++) {
        arr2d[array[i]-1][i] += 1;
    }
}


int main() {
    int array[SIZE]; // this is the array I will be shuffling
    set_values(array); // sets array values to sequential 1-SIZE

    int count_arr[SIZE][SIZE]; //create 2d array to later certify randomness
    set_zero_2d(count_arr); // sets all vlaues in count_arr to 0

    srand(time(NULL)); // prepares the rand function

    // print the sorted array
    printf("Sorted Array:\n");
    print_arr(array);

    // shuffles array TIMES times, keeps counter in count_arr
    for (int i=0; i<TIMES; i++) {
        shuffle(array, count_arr);
    }
    // print final sorted array and matrix count_arr
    printf("Array, sorted by shuffle:\n");
    print_arr(array);
    printf("Array frequency chart:\n");
    print2DArray(SIZE, SIZE, count_arr);
    set_zero_2d(count_arr); // sets all vlaues in count_arr to 0

    // shuffles array TIMES times, keeps counter in count_arr
    for (int i=0; i<TIMES; i++) {
        opp_shuffle(array, count_arr);
    }
    // print final sorted array and matrix count_arr
    printf("Array, sorted by opp_shuffle:\n");
    print_arr(array);
    printf("Array frequency chart:\n");
    print2DArray(SIZE, SIZE, count_arr);
    set_zero_2d(count_arr); // sets all vlaues in count_arr to 0

    return 0;
}