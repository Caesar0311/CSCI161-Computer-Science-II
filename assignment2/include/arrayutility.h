#ifndef __ARRAYUTILITY_HEADER__
#define __ARRAYUTILITY_HEADER__

/**
 * Shows all the elements of an array on the screen
 * Accepts array and its size as the parameters.
 */
void show(const int *array, int size);


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
