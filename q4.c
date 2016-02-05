#include <stdio.h>
void q4( int *A )
{
    int counter = 15;   // start from LSB, assuming that index is 0 to 15
    do{
        
        if ( A[counter] == 1 && counter > 0 )  // if number is 1 and it is not the MSB
        {
            while( counter >= 0 ) // iterate through the rest of the number flipping the zeros to ones and visa versa
            {
                counter--;
                A[counter] = (1 - A[counter] );
            }
        }
        else
        {
            counter--;
        }
    } while ( counter >= 0 );  // iterate till we reach the end of the number at the MSB

}

int main()
{
    int array[16] = {1,1,1,0,0,0,0,0,0,0,0,0,1,0,0,0};
    q4(array);
    for (int i = 0; i < 16; i++)
    {
        printf("%d", array[i]);
    }
}