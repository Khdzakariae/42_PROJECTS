#include "minitalk.h"


void print_bits(char octee)
{
    char tmp;
    int i = 8;
    while(i--)
    {
        tmp = (octee >> i & 1) + '0';
        write(1, &tmp, 1);
    }
}
 
// 0 1 0 0 0 0 0 0
int main ()
{
    int tmp = 0;
    char c ;

    puts("------------");
    print_bits(1);
    puts("\n------------\n");
    print_bits(64);
    puts("\n------------\n");
    tmp = c >> 0 & 1;
    printf("%d", tmp);
    tmp = tmp<<0 &1 ;
    printf("%d", tmp);


}
0 0 0 0 0 0 0 1 
0 1 0 0 0 0 0 0

0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1

0 0 0 0 0 0 0 1