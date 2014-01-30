#define _BSD_SOURCE
#include <eacof.h>

#include <time.h>
#include <sys/time.h>
#include <unistd.h>

int main(void) {
    eacof_Checkpoint *checkpoint;
    int status;
    eacof_Sample sample;

    status = initEACOF();
    if(status != EACOF_OK) {
        stopEACOF();
        return 1;
    }

    while(1) {
        status = setCheckpoint(&checkpoint, EACOF_PSPEC_ALL, 1, EACOF_DEVICE_SYSTEM_BATTERY_ALL);
        if(status != EACOF_OK) {
            printf("Failed to create a checkpoint\n");
            stopEACOF();
            return 1;
        }
        printf("Created checkpoint\n");

        for(int sampleNum = 0; sampleNum < 10; sampleNum++) {
            status = sampleCheckpoint(checkpoint, &sample);
            if(status != EACOF_OK) {
                printf("Failed to sample a checkpoint\n");
                stopEACOF();
                return 1;
            }
            printf("Sample %d: %lf\n", sampleNum, sample);

            usleep(1000000);
        }

        status = deleteCheckpoint(&checkpoint);
        if(status != EACOF_OK) {
            printf("Failed to delete a checkpoint\n");
            stopEACOF();
            return 1;
        }
        printf("Deleted checkpoint\n");

        usleep(1000000);
    }

    stopEACOF();

    return 0;
}
