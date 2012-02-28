/*************************************************************
This is the program to merge two arrays by alternate characters
Author : Abhiram R : CS10B060
Date - 19.8.2011
***************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{  
    char* string_1;
    char* string_2;
    char* number;
    int length_of_string_1,length_of_string_2;
    int i,j;
    int min, max;
    
    number = malloc(20*sizeof(int));
    printf("Enter the lengths of the strings to be inputted in the same line\n");
    fgets(number,20,stdin);   
    sscanf(number,"%d %d",&length_of_string_1,&length_of_string_2);
    
    /* Allocating memory to each string */
    string_1 = malloc((length_of_string_1+2) * sizeof(char));
    string_2 = malloc((length_of_string_2+2) * sizeof(char));
    
    printf("Enter the first string\n");
    fgets(string_1,(length_of_string_1+2) * sizeof(char),stdin);
    fflush;
    printf("Enter the second string\n");
    fgets(string_2,(length_of_string_2+2) * sizeof(char),stdin);
    fflush;
    
    /* Input taken. Algorithm execution below */   
    if(length_of_string_1>length_of_string_2)
    {
        min = length_of_string_2;
        max = length_of_string_1;
    }
    else
    {
        min = length_of_string_1;
        max = length_of_string_2;
    }
    
    for( i=0;i<min;i++)
    {
        printf("%c",string_1[i]);
        printf("%c",string_2[i]);
    }
    if( max == length_of_string_1)
    {
        for( i=min;i<max;i++)
        {
            printf("%c", string_1[i]);
        }
    }
    else if ( max == length_of_string_2)
    {
        for( i=min;i<max;i++)
        {
            printf("%c", string_2[i]);
        }      
    }
    printf("\n");    
}
