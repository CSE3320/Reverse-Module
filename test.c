#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main( int argc, char *argv[] ) 
{
    char result[256] = {0};

    int fd = open( "/dev/reverse", O_RDWR );

    if ( fd < 0 ) 
    { 
        perror( "Error: Reverse" );
        return -1;
    }

    printf( "Input : %s\n", argv[1] );

    write( fd, argv[1], strlen( argv[1] ) );
    read ( fd, result, strlen( argv[1] ) );

    printf( "Output: %s\n", result );

    close( fd );

    return 0;
}
