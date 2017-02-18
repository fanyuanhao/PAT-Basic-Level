#include <stdio.h>
 int main() {
     int a[10];
     int i;
     for( i = 0; i < 10; i++ ) {
         scanf( "%d", &a[i] );
     }
 
     int min;
     for( i = 0; i < 10; i++ ) {
         if( i != 0 && a[i] != 0 ) {
             min = i;
             break;
         }
     }
     printf( "%d", min );
     a[min]--;
    for( i = 0; i < 10; i++ ) {
         for( ; a[i] > 0; a[i]-- ) {
             printf( "%d", i );
         }
     }
     return 0;
 }
