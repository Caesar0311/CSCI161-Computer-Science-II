#ifndef UTILITY_H
#define UTILITY_H

/**
 * Shows all the elements of an array on the screen
 * Accepts array and its size as the parameters.
 */
void show(const int *array, int size);

/**
 * Returns the statistivs ( minimum, maximum, and average) of the array elements.
 * Accepts array and its size as the input parameters.
 * Returns the statistics through the reference parameters  minRef, maxRef, avgRef.
 */
void getStatistics(const int *array, int size, int &minRef, int &maxRef, float &avgRef);


/**
 * Sorts the given array in ascending order.
 * Accepts the array and its size as the input parameter.
 */
void sortOriginal(int *array, int size);


/**
 * Sorts the copy of a given array  in ascending order and Returns the sorted copy.
 * Leaves the original array unchanged.
 * Accepts the array and its size as the input parameter.
 */
int* sortCopy(const int *array, int size);


#endif
