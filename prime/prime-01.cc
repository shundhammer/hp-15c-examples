// Calculate prime numbers the structured way
//
// Author: Stefan Hundhammer <Stefan.Hundhammer@gmx.de>
//
// Build this with
//   make prime-01

#include <stdio.h>
#include <math.h>

int main()
{
    int candidate = 3;
    int max_candidate = 1000;

    while ( candidate <= max_candidate ) // candidate loop
    {
        int max_divisor = sqrt( (double) candidate );
        int divisor = 3;
        bool prime = true;
        
        while ( divisor <= max_divisor ) // divisor loop
        {
            if ( candidate % divisor == 0 )
            {
                prime = false;
                break;
            }

            divisor += 2;
        }

        if ( prime )
            printf( "%d\n", candidate );

        candidate += 2;
    }
}
