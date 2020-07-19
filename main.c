#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define VERSION 100

int main(int argc, char** argv) {
    int file_status = db_fstatus();

    printf("File Status: %i\n", file_status);
    int dbver = db_fversion();

    printf("DB Version: %i\n", dbver);

    return 0;
}
