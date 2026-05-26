#include <stdio.h>
#include <stdlib.h>
int main() {
    
    // malloc(size);
    // void * 
    // GV 

    int *p;
    p = (int *)malloc(sizeof(int));

    *p = 20;

    printf("%d \n",*p);

    // ---------------------------

    // calloc(size , size);
    // void *
    // 0 init

    int *c = calloc(1,sizeof(int));

    *c = 30;

    printf("%d \n",*c);


    if (c != NULL || p!= NULL)
    {
        printf("Deleted\n");
        free(c);
        free(p);
    }


    printf("%d\n",*p);
    printf("%d\n",*c);
    

    return 0;
}   
