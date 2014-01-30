#define _BSD_SOURCE
#include <eacof.h>

#include <time.h>
#include <stdio.h>
#include <sys/time.h>
#include <dirent.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

#define SYS_CLASS_POWER_SUPPLY          "/sys/class/power_supply"
#define SYS_FIELD_WATTS_LEFT            "POWER_SUPPLY_ENERGY_NOW="
#define SYS_FIELD_STATUS_DISCHARGING    "POWER_SUPPLY_STATUS=Discharging"

eacof_Sample getNewSample();
char *fileRead(const char *file);

int main() {
    int status;
    eacof_Probe *probe;

    // initialise EACOF
    status = initEACOF();
    if(status != EACOF_OK) {
        stopEACOF();
        return 1;
    }

    // create the probe that this is
    status = createProbe(&probe, 1, EACOF_DEVICE_SYSTEM_BATTERY_ALL);
    if(status == EACOF_ERR_NETWORK_SEND) {
        stopEACOF();
        return 1;
    }

    // variables for sampling
    eacof_Sample currentSample;
    eacof_Sample lastSample;
    eacof_Sample sentSample;

    // perform sampling
    // clear the initial value so the first reading is sensible
    lastSample = getNewSample();
    while(1) {
        // make a call to system-specific code to get a sample from the probe
        // TODO: Handle wrapping
        currentSample = getNewSample();
        // find out how much energy has been used since last sampling
        sentSample = lastSample - currentSample;
        // keep track of the value at present
        lastSample = currentSample;

        printf("Current sample: %lf\n", sentSample);
        // Add a sample from the probe. This will automatically
        // be sent to peers that require it.
        status = addSample(probe, sentSample);
        if(status != EACOF_OK) {
            printf("There was a problem adding the sample\n");
        }
    }

    return 0;
}

eacof_Sample getNewSample() {
    usleep(200000);

    DIR *dir;
    FILE *fp;
    struct dirent *dirent;
    char path[4096];
    char buffer[4096];
    int mismatch;
    char *data;
    int val;
    int discharging;
    double wattsLeft = 0;

    // check /sys/class/power_supply directory exists
    dir = opendir(SYS_CLASS_POWER_SUPPLY);
    if(dir == NULL) {
        return -1;
    }

    // change into the right directory for finding battery info (BAT0 in this case)
    while(1) {
        dirent = readdir(dir);
        if(strlen(dirent->d_name) > 2) {
            snprintf(path, sizeof(path), "%s/%s/type", SYS_CLASS_POWER_SUPPLY, dirent->d_name);
            data = fileRead(path);
            if(data == NULL) {
                continue;
            } else {
                mismatch = (strstr(data, "Battery") == NULL);
                free(data);
                if(mismatch) {
                    continue;
                } else {
                    break;
                }
            }
        }
    }

    snprintf(path, sizeof(path), "%s/%s/uevent", SYS_CLASS_POWER_SUPPLY, dirent->d_name);

    fp = fopen(path, "r");

    // check each line of file for charging info & watts remaining
    discharging = 0;
    while(fgets(buffer, sizeof(buffer)-1, fp) != NULL) {
        if(strstr(buffer, SYS_FIELD_STATUS_DISCHARGING)) {
            discharging = 1;
        }

        if(strstr(buffer, SYS_FIELD_WATTS_LEFT) && strlen(buffer) > (sizeof(SYS_FIELD_WATTS_LEFT) - 1)) {
            sscanf(buffer + sizeof(SYS_FIELD_WATTS_LEFT) - 1, "%d", &val);
            wattsLeft = (double)val / 1000000.0;
        }
    }
    fclose(fp);
    closedir(dir);
    if(!discharging) {
        return -1;
    }

    return (eacof_Sample)wattsLeft;
}

char *fileRead(const char *file) {
    FILE *fp;
    char buffer[4096];

    fp = fopen(file, "r");
    if(fp == NULL) {
        return NULL;
    }

    if(fgets(buffer, sizeof(buffer), fp) == NULL) {
        fclose(fp);
        return NULL;
    }

    fclose(fp);

    return strdup(buffer);
}
