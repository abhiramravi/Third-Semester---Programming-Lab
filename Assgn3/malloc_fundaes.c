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
    int length_of_string_1,length_of_string_2;
    int i,j;
    int min, max;
    
    string_1 = malloc(sizeof(char));
    string_2 = malloc(sizeof(char));
    
    printf("Enter the first string\n");
    gets(string_1);
    fflush;
    printf("Enter the second string\n");
    gets(string_2);
    fflush;
    
    length_of_string_1 = strlen(string_1);
    length_of_string_2 = strlen(string_2);
    
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
