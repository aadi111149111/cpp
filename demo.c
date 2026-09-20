#include <stdio.h>
void main()
{
    int num = 5;
for(int i=0;i<5;i++)
{
    for (int k=0; k< num-i; k++ )
    {
        printf(" ");
    }
    for(int j=0 ; j<= i-1 ;j++)
    {
        printf("* ");
    }
    printf("\n");

}
}