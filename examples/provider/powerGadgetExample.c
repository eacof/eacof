#if defined __APPLE__ && defined __MACH__

#include <eacof.h>

#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <IntelPowerGadget/EnergyLib.h>

void initPowerGadget(int *numMsrs, int *pwrMsrId, char *pwrMsrName);
eacof_Sample getNewSample(int pwrMsrIdz);

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
    status = createProbe(&probe, 1, EACOF_DEVICE_CPU_ALL);
    if(status == EACOF_ERR_NETWORK_SEND) {
        stopEACOF();
        return 1;
    }

    // variables for the power gadget
    int numMsrs = 0;
    int pwrMsrId;
    char pwrMsrName[1024];

    // init the power gadget
    initPowerGadget(&numMsrs, &pwrMsrId, pwrMsrName);

    // variables for sampling
    eacof_Sample sample;

    // perform sampling
    // clear the initial value so the first reading is sensible
    sample = getNewSample(pwrMsrId);
    while(1) {
        // make a call to system-specific code to get a sample from the probe
        // TODO: Handle wrapping
        sample = getNewSample(pwrMsrId);

        printf("Current sample: %lf\n", sample);
        // Add a sample from the probe. This will automatically
        // be sent to peers that require it.
        status = addSample(probe, sample);
        if(status != EACOF_OK) {
            printf("There was a problem adding the sample\n");
        }
    }

    return 0;
}

void initPowerGadget(int *numMsrs, int *pwrMsrId, char *pwrMsrName) {
    IntelEnergyLibInitialize();

    GetNumMsrs(numMsrs);

    // find the position of the power register
    for(int i = 0; i < *numMsrs; i++) {
        int funcID;

        GetMsrFunc(i, &funcID);

        if (funcID == MSR_FUNC_POWER) {
            *pwrMsrId = i;
            GetMsrName(i, pwrMsrName);
        }
    }
}

eacof_Sample getNewSample(int pwrMsrId) {
    usleep(200000);
    //usleep(2000000);
    ReadSample();

    int nData;
    double data[3];
    GetPowerData(0, pwrMsrId, data, &nData);

    return (eacof_Sample)data[1]; // Joules since last sample
}

#else

#include <stdio.h>

int main() {
    printf("Only builds on OS X :(\n");

    return 0;
}

#endif // #if defined __APPLE__ && defined __MACH__
