/**********************************************************************
This is the definition for all operations on polynomials
Author - Abhiram R -  CS10B060  
Date - 12.8.11
***********************************************************************/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"polynomial.h"

polynomial polynomial_construct( int k, double coefficients[] )
{
    polynomial poly_1;
    int i;
    poly_1.n = k;   
    poly_1.coeff = (double*) malloc((k+1)*sizeof(double));
    for(i=0;i<=poly_1.n;i++)
    {
        poly_1.coeff[i] = coefficients[i];  
    }    
    return poly_1;
}
void polynomial_print( polynomial q )
{
    int i;
    for(i=0;i<=q.n;i++)
    {
        printf("%.2f x^%d",q.coeff[i],i);
        if(i!=q.n) printf(" + ");
        else printf("\n");
    }
}
double polynomial_evaluate( polynomial p, double x )
{
    double value=0;
    int i;
    for(i=0;i<=p.n;i++)
    {
        value+= pow(x,i)*(p.coeff[i]);
    }
    return value;
}
polynomial polynomial_add( polynomial p, polynomial q )
{
    int min,max;
    int i;
    if(p.n>q.n) 
    {
        min = q.n;
        max = p.n;
    }
    else
    {
        min = p.n;
        max = q.n;
    }
    double coefficients[max+1];
    for(i=0;i<=min;i++)
    {
        coefficients[i] = p.coeff[i] + q.coeff[i];
    }
    if(max = p.n)
    { 
        for(i=min+1;i<=max;i++)
        {
            coefficients[i] = p.coeff[i];
        }
    }    
    if(max = q.n)
    {
        for(i=min+1;i<=max;i++)
        {
            coefficients[i] = q.coeff[i];
        }
    }
    polynomial sum = polynomial_construct(max, coefficients);    
    return sum;
}
polynomial polynomial_sub( polynomial p, polynomial q )
{
    int min,max;
    int i;
    if(p.n>q.n) 
    {
        min = q.n;
        max = p.n;
    }
    else
    {
        min = p.n;
        max = q.n;
    }
    double coefficients[max+1];
    for(i=0;i<=min;i++)
    {
        coefficients[i] = p.coeff[i] - q.coeff[i];
    }
     if(max = p.n)
    { 
        for(i=min+1;i<=max;i++)
        {
            coefficients[i] = p.coeff[i];
        }
    }    
    if(max = q.n)
    {
        for(i=min+1;i<=max;i++)
        {
            coefficients[i] = -q.coeff[i];
        }
    } 
    polynomial sum = polynomial_construct(max, coefficients);    
    return sum;
}
polynomial polynomial_mul( polynomial p, polynomial q)
{
    int degree = (p.n)+(q.n);
    int i,j,k;
    double coefficients[(p.n)+(q.n)] ;
    for(i=0;i<=degree;i++)
    {
        coefficients[i] = 0;
    }
    for(j=0;j<=p.n;j++) for(k=0;k<=q.n;k++)
    {
        coefficients[j+k]+= p.coeff[j] * q.coeff[k]; 
    }   
    polynomial product = polynomial_construct(degree, coefficients);
    return product;
}
polynomial polynomial_diff(polynomial p)
{
    int degree = p.n - 1;
    int i;
    double coefficients[p.n];
    for(i=0;i<=p.n-1;i++)
    {
        coefficients[i] = (i+1) * p.coeff[i+1];
    }
    polynomial diff = polynomial_construct(degree, coefficients);
    return diff;   
}
polynomial polynomial_integrate(polynomial p)
{
    int degree = p.n + 1;
    int i;
    double coefficients[p.n+2];
    for(i=0;i<=p.n+1;i++)
    {
        if(i==0) coefficients[0] = 0;   // coefficient of x^0 does not exist after integration
        else
        {
            coefficients[i] = (p.coeff[i-1])/(double)(i);
        }
    }
    polynomial integrated = polynomial_construct(degree, coefficients);
    return integrated;
}
