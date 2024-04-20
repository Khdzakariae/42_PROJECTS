#include <stdio.h>
#include <string.h>

typedef struct
{
    char *name;
    char *number;
}   person;

int main ()
{
    person peple[3];

    peple[0].name = "zaki";
    peple[0].number = "0664419721";
    peple[1].name = "hamza";
    peple[1].number = "0610106334";
    peple[2].name = "ahmed";
    peple[2].number = "0620304050";
    int i = 0;
    while(i < 3)
    {
        if (strcmp(peple[i].name, "hamza") == 0)
        {
            printf("%s\n", peple[i].number);
            return(0);
        }
        i++;
    }
    puts("not fond \n");
}