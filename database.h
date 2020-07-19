#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

/* db_isvalid
 * Returns the status of the database file, opening the file
 * for reading if it is valid.  The opened file can be accessed
 * in the argument, rfile.
 *
 * Arguments
 * ----------
 *  rfile: An uninitialized file pointer object.
 *
 * Return values
 * -------------- 
 *  -1: File does not exist
 *   0: File exists and is valid
 *   1: File exists but cannot read or write
 *   2: File exists but contains an invalid header
 *   3: File exists but is built with an incompatible version
*/
int db_fstatus();

/* db_fopenr
 * Opens the database for reading without checking for errors.
 * This should only be called if db_isvalid returns 0.
 *
 * NOTE: This function is not in use at the moment due to 
 * various segmentation faults that happen when passing file
 * pointers around.
*/
FILE* db_fopenr();

/* db_fversion 
 * Returns the version of the password database being read
 *
 * Versions are a 3 digit integer so that
 * version 1.2.3 = 123
*/
int db_fversion();

#endif
