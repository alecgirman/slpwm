/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/18/20 18:52:06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define VERSION 100

int main(int argc, char** argv) {
    int db_exists = 0;
    int db_entries = 0;
    int db_version = 0;

    //check if password database exists
    if (access(".pwdb", F_OK) != -1) {
        if (access(".pwdb", R_OK | W_OK) != -1) {
            db_exists = 1;
            printf("Debug: Found database file!\n");
        }

        else {
            //file exists but cannot open for read/write
            printf("Error: .pwdb file exists but cannot be opened.\n");
        }
    }

    else {
        printf("Debug: Password database does not exist!\n");
        printf("Debug: Creating database file...");
        FILE* db_file = fopen(".pwdb", "w");
        fwrite("VERSION 100\nasdf", 16, 1, db_file);
        fclose(db_file);
    }

    if (db_exists == 1) {
        //open database for reading
        FILE* db_file = fopen(".pwdb", "r");
        char fversion[64];
        int versionlen = 0;
        fgets(fversion, 64, db_file);
        
        if ((versionlen = strlen(fversion)) > 11) {
            db_version = atoi(fversion + 8);
            printf("Database version: %i\n", db_version);
        }

        else {
            printf("Error: Invalid database version header\n");
        }
    }

    return 0;
}
