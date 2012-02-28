/*****************************************************************
This is the solution to the second question in the problem statement
Author : Abhiram R : CS10B060   
Date : 21.8.2011
*****************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int* array_1;
    int* array_2;
    int* array_3;
    int length;
    char* gen_string;
    int i;
    
    printf("Enter the length of the arrays to be inputted\n");
    fgets(gen_string, sizeof(int), stdin);
    sscanf(gen_string, "%d", &length);
    
    array_1 = malloc((length)*sizeof(int));
    array_2 = malloc((length)*sizeof(int));
    array_3 = malloc((length)*sizeof(int));
    
    printf("Enter the array elements of each array\n");
    for(i=0;i<length;i++)
    {
        scanf("%d",&array_1[i]);
        fflush;
    }
    for(i=0;i<length;i++)
    {
        scanf("%d",&array_2[i]);
        fflush;
        array_3[i] = array_1[i] * array_2[i];
    }
    printf("The required array is \n");
    for(i=0;i<length;i++)
    {
        printf("%d ", array_3[i]);
    }
    printf("\n");
    
    
}
