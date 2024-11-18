#include <stdio.h>
int getMax ( int x , int y ) ;
int getMin ( int , int );
main ()
{
     int  a , b , theMax , theMin ;
     scanf ( "%d%d", & a , & b ) ;
     theMax = getMax ( a , b ) ;
     theMin = getMin ( a , b ) ;
     printf ( "%d > %d \n", theMax , theMin );
}
int getMax ( int x , int y )
{
     if ( x > y )
            return x ;
     else 
            return y ;
}
int getMin ( int x , int y )
{
     if ( x > y )
            return y ;
     else 
            return x ;
}