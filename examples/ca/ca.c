#define CENTRAL_AUTHORITY (1)
#include <eacof.h>

int main(void) {
	int status;

    initEACOF();

    status = eacof_initStorage();
    if(status) {
    	eacofLogError("CA Init", status, "Problem initialising storage");
    	return 1;
    }
    // TODO: Handle errors here

    eacof_listenOnDefault();

    while(1) {
    	eacof_acceptConnections();
    }

    return 0;
}
