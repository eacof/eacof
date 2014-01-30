#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <time.h>
#include <sys/time.h>
#include <stdbool.h>
#include <string.h>

#include <eacof.h>

#define NUMBER_OF_ALGORITHMS 1

#define MIN_ELEMENT_VALUE 0
#define MAX_ELEMENT_VALUE 255

#define STRINGIFIER_(exp) #exp
#define STRINGIFIER(exp) STRINGIFIER_(exp)

#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define MEDIAN_OF_THREE(X,Y,Z,memLoc) \
do { \
	if(X > Y){ \
		if(Y > Z){ \
			memLoc = Y; \
		} else if(X > Z){ \
			memLoc = Z; \
		} else { \
			memLoc = X; \
		} \
	} else { \
		if(X > Z){ \
			memLoc = X; \
		} else if(Y > Z){ \
			memLoc = Z; \
		} else { \
			memLoc = Y; \
		} \
	} \
} while(0)

#define ARRAY_NAME(SIZE) arr##SIZE
#define ARRAY_NAME_TMP(SIZE) arrTmp##SIZE
#define TYPE_NAME(SIZE) uint##SIZE##_t

#define TIMEVAL_DIFF_NAME(TYPE, SORT) SORT##TYPE##diff
#define TIMEVAL_DIFF(TYPE, SORT) long long TIMEVAL_DIFF_NAME(TYPE, SORT)
#define TIMEVAL_TRACKER_NAME(TYPE, SORT, RELATION) RELATION##SORT##TYPE##tv
#define TIMEVAL_TRACKER(TYPE, SORT, RELATION) struct timeval TIMEVAL_TRACKER_NAME(TYPE, SORT, RELATION)

#define START_MONITORING(TYPE, SORT) \
TIMEVAL_TRACKER(TYPE, SORT, START); \
TIMEVAL_TRACKER(TYPE, SORT, END); \
status = setCheckpoint(&checkpoint, EACOF_PSPEC_ALL, 1, EACOF_DEVICE_CPU_ALL); \
if(status != EACOF_OK){ \
	fprintf(stderr, "Error setting checkpoint.\n"); \
	exit(1); \
} \
gettimeofday(&TIMEVAL_TRACKER_NAME(TYPE, SORT, START), 0); \
status = sampleCheckpoint(checkpoint, &initialSample); \
if(status != EACOF_OK){ \
	fprintf(stderr,"Error sampling checkpoint before.\n"); \
	exit(1); \
}

#define END_MONITORING(TYPE, SORT) \
status = sampleCheckpoint(checkpoint, &postSample); \
if(status != EACOF_OK){ \
	fprintf(stderr,"Error sampling checkpoint after.\n"); \
	exit(1); \
} \
gettimeofday(&TIMEVAL_TRACKER_NAME(TYPE, SORT, END), 0); \
TIMEVAL_DIFF(TYPE, SORT) = (TIMEVAL_TRACKER_NAME(TYPE, SORT, END).tv_sec - TIMEVAL_TRACKER_NAME(TYPE, SORT, START).tv_sec)*1000000LL + TIMEVAL_TRACKER_NAME(TYPE, SORT, END).tv_usec - TIMEVAL_TRACKER_NAME(TYPE, SORT, START).tv_usec; \
printf("td: %lld %f\n", TIMEVAL_DIFF_NAME(TYPE, SORT), postSample - initialSample); \
fprintf(fp, "%lld,%f,%s,%s\n", TIMEVAL_DIFF_NAME(TYPE, SORT), postSample - initialSample, #SORT, STRINGIFIER(TYPE)); \
status = deleteCheckpoint(&checkpoint); \
if(status != EACOF_OK){ \
	fprintf(stderr,"Error deleting checkpoint after.\n"); \
	exit(1); \
}

#define SWAP(x, y, SIZE) do { TYPE_NAME(SIZE) swapTemp##SIZE = x; x = y; y = swapTemp##SIZE; } while(0)


#define outputArray(arr, numElements, SIZE) \
do { \
	for(size_t outputArrCurrIdx = 0; outputArrCurrIdx < numElements; outputArrCurrIdx++){ \
		printf("%" PRIu##SIZE "\n", arr[outputArrCurrIdx]); \
	} \
} while(0)

#define fillArray(SIZE, numElements) \
do { \
	for(size_t fillArrCurrIdx = 0; fillArrCurrIdx < numElements; fillArrCurrIdx++){ \
		ARRAY_NAME(SIZE)[fillArrCurrIdx] = rand() % (MAX_ELEMENT_VALUE + 1); \
	} \
 \
 	if(NUMBER_OF_ALGORITHMS > 1){ \
		memcpy(ARRAY_NAME_TMP(SIZE), ARRAY_NAME(SIZE), numElements * sizeof(TYPE_NAME(SIZE))); \
	} \
} while(0)

#define copyArray(fromSize, toSize, numElements) \
do { \
	for(size_t copyArrCurrIdx = 0; copyArrCurrIdx < numElements; copyArrCurrIdx++){ \
		ARRAY_NAME(toSize)[copyArrCurrIdx] = (TYPE_NAME(toSize))ARRAY_NAME(fromSize)[copyArrCurrIdx]; \
		if(NUMBER_OF_ALGORITHMS > 1){ \
			ARRAY_NAME_TMP(toSize)[copyArrCurrIdx] = (TYPE_NAME(toSize))ARRAY_NAME(fromSize)[copyArrCurrIdx]; \
		} \
	} \
} while(0)

#define bubbleSort(arr, numElements, SIZE)\
do { \
	size_t lastSwapped; \
	size_t newLastSwapped; \
	do { \
		newLastSwapped = 0; \
		for(size_t bubbleSortCurrIdx = 1; bubbleSortCurrIdx < numElements; bubbleSortCurrIdx++){ \
			if(arr[bubbleSortCurrIdx-1] > arr[bubbleSortCurrIdx]){ \
				SWAP(arr[bubbleSortCurrIdx-1], arr[bubbleSortCurrIdx], SIZE); \
				newLastSwapped = bubbleSortCurrIdx; \
			} \
		} \
		lastSwapped = newLastSwapped; \
	} while( lastSwapped > 0 ); \
} while(0)

#define insertionSort(arr, numElements, SIZE) \
do { \
	TYPE_NAME(SIZE) valueToInsert; \
	size_t holePos; \
 \
	for(size_t insertionSortCurrIdx = 1; insertionSortCurrIdx < numElements; insertionSortCurrIdx++){ \
		valueToInsert = arr[insertionSortCurrIdx]; \
		holePos = insertionSortCurrIdx; \
		while(holePos > 0 && valueToInsert < arr[holePos-1]){ \
			arr[holePos] = arr[holePos-1]; \
			holePos--; \
		} \
		arr[holePos] = valueToInsert; \
	} \
} while(0)

#define iterativeQuicksort(arr, numElements, SIZE) \
do { \
	if(numElements > 1){ \
		size_t stackPtr = 0; \
		size_t left = 0; \
		size_t right = numElements - 1; \
		size_t pivotIdx; \
		size_t pivotNewIdx; \
		TYPE_NAME(SIZE) pivotValue; \
		size_t storeIdx; \
		qsStack[++stackPtr] = left; \
		qsStack[++stackPtr] = right; \
		while(stackPtr){ \
			right = qsStack[stackPtr--]; \
			left = qsStack[stackPtr--]; \
			if(left < right && right < numElements){ \
				MEDIAN_OF_THREE(left, (left+right)/2, right, pivotIdx); \
				pivotValue = arr[pivotIdx]; \
				SWAP(arr[right], arr[pivotIdx], SIZE); \
				storeIdx = left; \
				for(size_t qsIdx = left; qsIdx < right; qsIdx++){ \
					if(arr[qsIdx] < pivotValue){ \
						SWAP(arr[storeIdx], arr[qsIdx], SIZE); \
						storeIdx++; \
					} \
				} \
				SWAP(arr[storeIdx], arr[right], SIZE); \
				pivotNewIdx = storeIdx; \
				if(pivotNewIdx - 1 > left){ \
					qsStack[++stackPtr] = left; \
					qsStack[++stackPtr] = pivotNewIdx - 1; \
				} \
				if(pivotNewIdx + 1 < right){ \
					qsStack[++stackPtr] = pivotNewIdx + 1; \
					qsStack[++stackPtr] = right; \
				} \
			} \
		} \
	} \
} while(0)

int compareuint8_t(const void *a, const void *b){
	if( *(uint8_t*)a < *(uint8_t*)b){
		return -1;
	} else if( *(uint8_t*)a == *(uint8_t*)b){
		return 0;
	} else {
		return 1;
	}
}
int compareuint16_t(const void *a, const void *b){
	if( *(uint16_t*)a < *(uint16_t*)b){
		return -1;
	} else if( *(uint16_t*)a == *(uint16_t*)b){
		return 0;
	} else {
		return 1;
	}
}
int compareuint32_t(const void *a, const void *b){
	if( *(uint32_t*)a < *(uint32_t*)b){
		return -1;
	} else if( *(uint32_t*)a == *(uint32_t*)b){
		return 0;
	} else {
		return 1;
	}
}
int compareuint64_t(const void *a, const void *b){
	if( *(uint64_t*)a < *(uint64_t*)b){
		return -1;
	} else if( *(uint64_t*)a == *(uint64_t*)b){
		return 0;
	} else {
		return 1;
	}
}

#define wrapQsort(arr, numElements, SIZE) \
do { \
	qsort(arr, numElements, SIZE / 8, compareuint##SIZE##_t); \
} while(0)

#define bottomUpMergeSort(arr, numElements, SIZE) \
do { \
	for(size_t width = 1; width < numElements; width *= 2){ \
		for(size_t msIdx = 0; msIdx < numElements; msIdx += 2*width){ \
			size_t iLeft = msIdx; \
			size_t iRight = MIN(msIdx+width, numElements); \
			size_t iEnd = MIN(msIdx+2*width, numElements); \
			size_t i0 = iLeft; \
			size_t i1 = iRight; \
			for(size_t msInnerIdx = i0; msInnerIdx < iEnd; msInnerIdx++){ \
				if(i0 < iRight && (i1 >= iEnd || msResultArr[i0] <= msResultArr[i1])){ \
					msWorkArr[msInnerIdx] = msResultArr[i0]; \
					i0++; \
				} else { \
					msWorkArr[msInnerIdx] = msResultArr[i1]; \
					i1++; \
				} \
			} \
		} \
		msTmpArrPtr = msResultArr; \
		msResultArr = msWorkArr; \
		msWorkArr = msTmpArrPtr; \
	} \
} while(0)

#define countingSort(arr, numElements, SIZE) \
do { \
	size_t bucketIdx = 0; \
	size_t arrFillIdx = 0; \
	for(size_t csIdx = 0; csIdx < numElements; csIdx++){ \
		csBuckets[arr[csIdx]]++; \
	} \
	while(bucketIdx <= MAX_ELEMENT_VALUE){ \
		while(csBuckets[bucketIdx]){ \
			arr[arrFillIdx++] = (TYPE_NAME(SIZE))bucketIdx; \
			csBuckets[bucketIdx]--; \
		} \
		bucketIdx++; \
	} \
} while(0)

#define ASSERT_ARRAY_IS_SORTED(arr, numElements, SIZE) \
do { \
	TYPE_NAME(SIZE) lastVal = 0; \
	bool arrIsSorted = true; \
	for(size_t sortedCheckIdx = 0; sortedCheckIdx < numElements; sortedCheckIdx++){ \
		if(arr[sortedCheckIdx] < lastVal){ \
			arrIsSorted = false; \
			break; \
		} else { \
			lastVal = arr[sortedCheckIdx]; \
		} \
	} \
	if(arrIsSorted){ \
		printf("Sorted\n"); \
	} else { \
		printf("Not sorted\n"); \
	} \
} while(0)

#define performSort(sortName, numElements, SIZE) \
do { \
	printf("%s %d\n", #sortName, SIZE); \
	size_t *qsStack; \
	TYPE_NAME(SIZE) *msArr0; \
	TYPE_NAME(SIZE) *msArr1; \
	TYPE_NAME(SIZE) *msResultArr; \
	TYPE_NAME(SIZE) *msWorkArr; \
	TYPE_NAME(SIZE) *msTmpArrPtr; \
	size_t *csBuckets; \
	if(strcmp(#sortName "\n", "iterativeQuicksort\n") == 0){ \
		qsStack = (size_t*) malloc(numElements * sizeof(size_t)); \
	} \
	if(strcmp(#sortName "\n", "bottomUpMergeSort\n") == 0){ \
		msArr0 = ARRAY_NAME(SIZE); \
		msArr1 = (TYPE_NAME(SIZE)*) malloc(numElements * sizeof(TYPE_NAME(SIZE))); \
		msResultArr = msArr0; \
		msWorkArr = msArr1; \
	} \
	if(strcmp(#sortName "\n", "countingSort\n") == 0){ \
		csBuckets = (size_t*) calloc(MAX_ELEMENT_VALUE - MIN_ELEMENT_VALUE + 1, sizeof(size_t)); \
	} \
	START_MONITORING(TYPE_NAME(SIZE), sortName); \
	sortName(ARRAY_NAME(SIZE), numElements, SIZE); \
	END_MONITORING(TYPE_NAME(SIZE), sortName); \
	if(strcmp(#sortName "\n", "iterativeQuicksort\n") == 0){ \
		free(qsStack); \
	} \
	if(strcmp(#sortName "\n", "bottomUpMergeSort\n") == 0){ \
		ARRAY_NAME(SIZE) = msResultArr; \
		free(msWorkArr); \
	} \
	if(strcmp(#sortName "\n", "countingSort\n") == 0){ \
		free(csBuckets); \
	} \
	if(NUMBER_OF_ALGORITHMS > 1){ \
		memcpy(ARRAY_NAME(SIZE), ARRAY_NAME_TMP(SIZE), numElements * sizeof(TYPE_NAME(SIZE))); \
	} \
} while(0)

// THE TYPE OF SORT IS SPECIFIED HERE
#define testDataType(SIZE, numElements) \
do { \
	performSort(bottomUpMergeSort, numElements, SIZE); \
} while(0)

#define CREATE_ARRAYS(SIZE) \
	TYPE_NAME(SIZE) *ARRAY_NAME(SIZE) = (TYPE_NAME(SIZE)*) malloc(numElements * sizeof(TYPE_NAME(SIZE))); \
	TYPE_NAME(SIZE) *ARRAY_NAME_TMP(SIZE); \
	if(NUMBER_OF_ALGORITHMS > 1){ \
		ARRAY_NAME_TMP(SIZE) = (TYPE_NAME(SIZE)*) malloc(numElements * sizeof(TYPE_NAME(SIZE))); \
	}

#define FREE_ARRAYS(SIZE) \
	free(ARRAY_NAME(SIZE)); \
	if(NUMBER_OF_ALGORITHMS > 1){ \
		free(ARRAY_NAME_TMP(SIZE)); \
	}

#define runExperiment(numElements) \
do { \
	fillArray(8, numElements); \
	copyArray(8, 16, numElements); \
	copyArray(8, 32, numElements); \
	copyArray(8, 64, numElements); \
 \
	testDataType(64, numElements); \
	testDataType(32, numElements); \
	testDataType(16, numElements); \
	testDataType(8, numElements); \
} while(0)

int main(int argc, char* argv[]){
	// suggested number of elements (for similar run times of 5-7 seconds per sort):
	// counting sort: 200,000,000 (is memory limited - would need an arry of ~4,000,000,000 elements (24+GB RAM) to take 5-7s)
	// qsort: 100,000,000
	// merge sort: 60,000,000
	// quick sort: 2,000,000
	// insertion sort: 200,000
	// bubble sort: 50,000
	size_t numElements = argc < 2 ? 1 : atoi(argv[1]);
	size_t numIterations = argc < 3 ? 1 : atoi(argv[2]);
	// seed the RNG
	srand(time(NULL));

	int status;
	eacof_Checkpoint *checkpoint;
	eacof_Sample initialSample;
	eacof_Sample postSample;

	// initialise EACOF
	status = initEACOF();
	if(status != EACOF_OK) {
		stopEACOF();
		return 1;
	}

	// specify somewhere to store the data
	FILE *fp;
	fp = fopen("sort-output-file.csv", "a");

	// create the arrays to use
	CREATE_ARRAYS(8);
	CREATE_ARRAYS(16);
	CREATE_ARRAYS(32);
	CREATE_ARRAYS(64);

	// run the experiment
	for(size_t currentIteration = 0; currentIteration < numIterations; currentIteration++){
		runExperiment(numElements);
	}

	// free and close everything
	FREE_ARRAYS(8);
	FREE_ARRAYS(16);
	FREE_ARRAYS(32);
	FREE_ARRAYS(64);

	fclose(fp);
	stopEACOF();

	return 0;
}
