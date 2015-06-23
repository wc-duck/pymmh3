/**
 * pymmh3 was written by Fredrik Kihlander, and is placed in the public
 * domain. The author hereby disclaims copyright to this source code.
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
	FILE* f   = fopen( "test/pg1260.txt", "rb" );
	FILE* out1 = fopen( "test/solution_hash32_seed0.txt", "wb" );
	FILE* out2 = fopen( "test/solution_hash32_seed1234ABCD.txt", "wb" );
	char buffer[2048];

	char* l;
	while( ( l = fgets( buffer, 2048, f ) ) != 0x0 )
	{
		uint32_t res1;
		uint32_t res2;
		mmh3::MurmurHash3_x86_32( l, strlen(l), 0, &res1 );
		fprintf( out1, "%s0x%08X\n", l, res1 );
		mmh3::MurmurHash3_x86_32( l, strlen(l), 0x1234ABCD, &res2 );
		fprintf( out2, "%s0x%08X\n", l, res2 );
	}

	fclose( f );
	fclose( out1 );
	return 0;
}
