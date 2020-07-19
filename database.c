#include "database.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define VERSION 100

int db_fstatus() {
    //if password database exists
    if (access(".pwdb", F_OK) != -1) {
        //check if database file is readable and writable (use & for and?)
        if (access(".pwdb", R_OK | W_OK) != -1) {
            //open database for reading
            FILE* rfile = fopen(".pwdb", "r");

            //get the version number - check file validity
            char fversion[64];
            int versionlen = 0;
            fgets(fversion, 64, rfile);
            fclose(rfile);
            
            //if the first word of the version line is VERSION
            if (strncmp(fversion, "VERSION", 7) == 0) {
                if (atoi(fversion + 8) > VERSION) {
                    return 3;
                }
                
                return 0;
            }

            //if the version number does not meet the criteria
            return 2;
        }

        return 1;
    }

    return -1;
}

FILE* db_fopenr() {
    FILE* file = fopen(".pwdb", "r");
    return file;
}

int db_fversion() {
    //get the version number - check file validity
    FILE* file = fopen(".pwdb", "r");
    char fversion[64];
    fgets(fversion, 64, file);
    fclose(file);
    return atoi(fversion + 8);
}
