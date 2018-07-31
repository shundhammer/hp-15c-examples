// Calculate prime numbers with GOTOs
//
// Author: Stefan Hundhammer <Stefan.Hundhammer@gmx.de>
//
// This is a bit simplistic since it requires the starting number to be an odd
// number, and it fails for the first prime numbers 2 and 3.
//
// Build this with
//   make prime-02

#include <stdio.h>
#include <math.h>

int main()
{
    int candidate = 3; // Reg 0
    int max_candidate = 100;

candidate_loop: // LBL 0
    int max_divisor = sqrt( (double) candidate ); // Reg 1
    int divisor = 3; // Reg 2
    
divisor_loop: // LBL 1
    if ( candidate % divisor == 0 ) // not a prime number
        goto next_candidate;

    divisor += 2;

    if ( divisor <= max_divisor )
        goto divisor_loop;

    // if we made it over all the possible divisors, this must be a prime
    printf( "%d\n", candidate );

next_candidate: // LBL 2
    candidate += 2;

    if ( candidate <= max_candidate )
        goto candidate_loop;
}
