// Calculate prime numbers with GOTOs, emulating HP-15C style
//
// Author: Stefan Hundhammer <Stefan.Hundhammer@gmx.de>
//
// This is a bit simplistic since it requires the starting number to be an odd
// number, and it fails for the first prime numbers 2 and 3.
//
// Build this with
//   make prime-03

#include <stdio.h>
#include <math.h>

int main()
{
    int reg_0 = 3; // candidate
    int max_candidate = 100;

LBL_A: // candidate_loop
    int reg_1 = sqrt( (double) reg_0 ); // max_divisor
    int reg_2 = 3; // divisor

LBL_0: // divisor_loop
    if ( reg_0 % reg_2 == 0 ) // not a prime number
        goto LBL_1; // next_candidate

    reg_2 += 2;

    if ( reg_2 <= reg_1 )
        goto LBL_0; // divisor_loop

    // if we made it over all the possible divisors, this must be a prime
    printf( "%d\n", reg_0 );

LBL_1: // next_candidate
    reg_0 += 2;

    if ( reg_0 <= max_candidate )
        goto LBL_A; // candidate_loop
}
