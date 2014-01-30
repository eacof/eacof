#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <eacof.h>

void swap (int *a, int *b);
int fill(int NumbersA[], int NumbersB[], int NumbersC[], int NumbersD[], int n);
int sort(int NumbersA[], int NumbersB[], int NumbersC[], int NumbersD[], int n);
int bubbleSort(int Numbers[], int n);
int quickSort(int Numbers[], int first, int last);
int heapSort(int Numbers[], int n);
int insertionSort(int Numbers[], int n);
void siftDown(int Numbers[], int root, int bottom);

int main(int argc, char* argv[]) {
    int n;

    if(argc <= 1) {
        printf("Usage:\n\tsort n\n");
        exit(1);
    }

    n = atoi(argv[1]);

    // Create four arrays to hold n integers
    int NumbersA[n];
    int NumbersB[n];
    int NumbersC[n];
    int NumbersD[n];

    // initialise EACOF
    if(initEACOF() != EACOF_OK) {
        stopEACOF();
        fprintf(stderr, "Unable to init EACOF\n");
        return 1;
    }

    // sort each copy of the array using a different algorithm
    sort(NumbersA, NumbersB, NumbersC, NumbersD, n);

    return 0;
}


/**
    Helper function for swapping values
*/
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}


/**
    Fills the four arrays with n pseudo-random integers
*/
int fill(int NumbersA[], int NumbersB[], int NumbersC[], int NumbersD[], int n) {
    srand(time(NULL));

    for(int i = 0; i < n; i++) {
        int num = rand() % 10000;

        /* Sets the ith element to a pseudo-random integer from 0-10000 */
        NumbersA[i] = num;
        NumbersB[i] = num;
        NumbersC[i] = num;
        NumbersD[i] = num;
    }

    return 0;
}


/**
    Control the sorting of the Numbers arrays with different algorithms
*/
int sort(int NumbersA[], int NumbersB[], int NumbersC[], int NumbersD[], int n) {
    eacof_Checkpoint *checkpoint;
    eacof_ProcessSpecifier processSpecifier = 0;
    eacof_Device sampledDevice = EACOF_DEVICE_SYSTEM_BATTERY_ALL;
    eacof_Sample before, after;

    printf("\nFilling array with %d random integers", n);
    printf("\nSorting %d integers:", n);

    while(1) {

        // fill arrays with n pseudo-random integers
        fill(NumbersA, NumbersB, NumbersC, NumbersD, n);

        // create a checkpoint
        if(setCheckpoint(&checkpoint, processSpecifier, sampledDevice) != EACOF_OK) {
            fprintf(stderr,"Error setting checkpoint.\n");
            exit(1);
        }

        // quick sort
        if(sampleCheckpoint(checkpoint, &before) != EACOF_OK) {
            fprintf(stderr,"Error sampling checkpoint.\n");
            exit(1);
        }
        printf("\n\nStarting Quick Sort");
        quickSort(NumbersA, 0, n-1);
        if(sampleCheckpoint(checkpoint, &after) != EACOF_OK) {
            fprintf(stderr,"Error sampling checkpoint.\n");
            exit(1);
        }
        printf("\nQuick Sort - %lf Joules", after - before);

        // heap sort
        printf("\n\nStarting Heap Sort");
        if(sampleCheckpoint(checkpoint, &before) != EACOF_OK) {
            fprintf(stderr,"Error sampling checkpoint.\n");
            exit(1);
        }
        heapSort(NumbersB, n);
        if(sampleCheckpoint(checkpoint, &after) != EACOF_OK) {
            fprintf(stderr,"Error sampling checkpoint.\n");
            exit(1);
        }
        printf("\nHeap Sort - %lf Joules", after - before);

        // insertion sort
        printf("\n\nStarting Insertion Sort");
        if(sampleCheckpoint(checkpoint, &before) != EACOF_OK) {
            fprintf(stderr,"Error sampling checkpoint.\n");
            exit(1);
        }
        insertionSort(NumbersC, n);
        if(sampleCheckpoint(checkpoint, &after) != EACOF_OK) {
            fprintf(stderr,"Error sampling checkpoint.\n");
            exit(1);
        }
        printf("\nInsertion Sort - %lf Joules", after - before);

        // bubble sort
        if(sampleCheckpoint(checkpoint, &before) != EACOF_OK) {
            fprintf(stderr,"Error sampling checkpoint.\n");
            exit(1);
        }
        printf("\n\nStarting Bubble Sort");
        bubbleSort(NumbersD, n);
        if(sampleCheckpoint(checkpoint, &after) != EACOF_OK) {
            fprintf(stderr,"Error sampling checkpoint.\n");
            exit(1);
        }
        printf("\nBubble Sort - %lf Joules\n", after - before);

        // delete the checkpoint
        if(deleteCheckpoint(&checkpoint) != EACOF_OK) {
            fprintf(stderr,"Error deleting checkpoint.\n");
            exit(1);
        }
    }

    return 0;
}


/**
    Sort the numbers using Bubble Sort - worst case O(n^2)
*/
int bubbleSort(int Numbers[], int n) {
    for(int i = (n - 1); i > 0; i--) {
        for(int j = 1; j <= i; j++) {
            if(Numbers[j-1] > Numbers[j]) {
                swap(&Numbers[j-1], &Numbers[j]);
            }
        }
    }

    return 0;
}


/**
    Sort the numbers using Quick Sort  - worst case O(n^2)
*/
int quickSort(int Numbers[], int first, int last) {
    int pivot, i, j;

    if(first < last) {
        pivot = first;
        i = first;
        j = last;

        while(i < j) {
            while((Numbers[i] <= Numbers[pivot]) && (i < last)) {
                i++;
            }

            while(Numbers[j] > Numbers[pivot]) {
                j--;
            }

            if(i < j) {
                swap(&Numbers[i], &Numbers[j]);
            }
        }

        swap(&Numbers[pivot], &Numbers[j]);

        quickSort(Numbers, first, j-1);
        quickSort(Numbers, j+1, last);

    }

    return 0;
}


/**
    Sort the numbers using Heap Sort - worst case O(nlogn)
*/
int heapSort(int Numbers[], int n) {
    int i;

    for(i = (n / 2); i >= 0; i--) {
        siftDown(Numbers, i, n - 1);
    }

    for(i = n - 1; i >= 1; i--) {
        swap(&Numbers[0], &Numbers[i]);
        siftDown(Numbers, 0, i-1);
    }

    return 0;
}


/**
    siftDown is used during Heap Sort
*/
void siftDown(int Numbers[], int root, int bottom) {
    int maxChild = root * 2 + 1;

    if(maxChild < bottom) {
        int otherChild = maxChild + 1;

        maxChild = (Numbers[otherChild] > Numbers[maxChild]) ? otherChild : maxChild;
    } else if(maxChild > bottom) {
        return;
    } else if(Numbers[root] >= Numbers[maxChild]) {
        return;
    }

    swap(&Numbers[root], &Numbers[maxChild]);

    siftDown(Numbers, maxChild, bottom);
}


/**
    Sort the numbers using Insertion Sort - worst case O(n^2)
*/
int insertionSort(int Numbers[], int n) {
    int val;

    for(int i = 0; i < n; i++) {
        int j;
        val = Numbers[i];

        for(j = i - 1; j >= 0; j--)
        {
            if(Numbers[j] <= val) {
                break;
            }
            Numbers[j + 1] = Numbers[j];
        }

        Numbers[j + 1] = val;
    }

    return 0;
}
