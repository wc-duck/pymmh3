/**
 * pymmh3 was written by Fredrik Kihlander and enhanced by Swapnil Gusani, and is placed in the public
 * domain. The authors hereby disclaim copyright to this source code.
 *
 * This is a hacky program to generate hashes to test against in the unittests.
 *
 * Ie, this code was used to generate the solution-files!
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "MurmurHash3.h"
namespace mmh3 {
#include "MurmurHash3.inc"
}

int main( int argc, const char** argv )
{
    FILE* f    = fopen( "test/pg1260.txt", "rb" );
    FILE* out1 = fopen( "test/solution_hash32_seed0.txt", "wb" );
    FILE* out2 = fopen( "test/solution_hash32_seed1234ABCD.txt", "wb" );
    FILE* out3 = fopen( "test/solution_hash128_x86_seed0.txt", "wb" );
    FILE* out4 = fopen( "test/solution_hash128_x86_seed1234ABCD.txt", "wb" );
    FILE* out5 = fopen( "test/solution_hash128_x64_seed0.txt", "wb" );
    FILE* out6 = fopen( "test/solution_hash128_x64_seed1234ABCD.txt", "wb" );
    char buffer[2048];

    char* l;
    while( ( l = fgets( buffer, 2048, f ) ) != 0x0 )
    {
        int32_t res1;
        int32_t res2;
        uint32_t res3[4];
        uint32_t res4[4];
        uint32_t res5[4];
        uint32_t res6[4];
        mmh3::MurmurHash3_x86_32( l, strlen(l), 0, &res1 );
        fprintf( out1, "%s%d\n", l, res1 );
        mmh3::MurmurHash3_x86_32( l, strlen(l), 0x1234ABCD, &res2 );
        fprintf( out2, "%s%d\n", l, res2 );
        mmh3::MurmurHash3_x86_128( l, strlen(l), 0, res3 );
        fprintf( out3, "%s0x%08X%08X%08X%08X\n", l, res3[3], res3[2], res3[1], res3[0] );
        mmh3::MurmurHash3_x86_128( l, strlen(l), 0x1234ABCD, res4 );
        fprintf( out4, "%s0x%08X%08X%08X%08X\n", l, res4[3], res4[2], res4[1], res4[0] );
        mmh3::MurmurHash3_x64_128( l, strlen(l), 0, res5 );
        fprintf( out5, "%s0x%08X%08X%08X%08X\n", l, res5[3], res5[2], res5[1], res5[0] );
        mmh3::MurmurHash3_x64_128( l, strlen(l), 0x1234ABCD, res6 );
        fprintf( out6, "%s0x%08X%08X%08X%08X\n", l, res6[3], res6[2], res6[1], res6[0] );
    }

    fclose( f );
    fclose( out1 );
    fclose( out2 );
    fclose( out3 );
    fclose( out4 );
    fclose( out5 );
    fclose( out6 );
    return 0;
}
