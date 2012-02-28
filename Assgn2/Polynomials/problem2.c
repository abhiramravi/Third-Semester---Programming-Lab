/*********************************************
This is the main file for the Second problem
Author : Abhiram : CS10B060
Date : 14.8.11
*********************************************/

#include<stdio.h>
#include<stdlib.h>
#include"polynomial.h"
#include<math.h>

int main(int argc, char* argv[])
{
    if(argc!=4) 
    {
        printf( "Usage: %s <v> <a> <t>", argv[0] );
        exit( EXIT_FAILURE );
    }
    double b = atof(argv[1]);
    double T = atof(argv[2]);
    double f = atof(argv[3]);
    double acctng[3] = {0, b*T, -b};
    double dectng[1] = {-f};
    
    /* Defining the Acceleration polynomials for the car */
    polynomial acc_car = polynomial_construct(2, acctng);
    polynomial dec_car = polynomial_construct(0, dectng);  
    
    /* Velocity and distance polynomials for the accelerating car */
    polynomial velocity_of_acc_car = polynomial_integrate(acc_car);
    polynomial distance_trvd_acc_car = polynomial_integrate(velocity_of_acc_car);
    
    /* Evaluating the distance travelled by the accelerating car in time T */
    double distance_1 = polynomial_evaluate(distance_trvd_acc_car, T);
    polynomial velocity_of_dec_car = polynomial_integrate(dec_car);
    velocity_of_dec_car.coeff[0] = polynomial_evaluate(velocity_of_acc_car, T);
    
    double time_of_stop = -velocity_of_dec_car.coeff[0]/velocity_of_dec_car.coeff[1];
    polynomial distance_trvd_dec_car = polynomial_integrate(velocity_of_dec_car);
    double distance_2 = polynomial_evaluate(distance_trvd_dec_car, time_of_stop);
    /*
    polynomial_print(acc_car);
    polynomial_print(velocity_of_acc_car);
    polynomial_print(distance_trvd_acc_car);
    polynomial_print(dec_car);
    polynomial_print(velocity_of_dec_car);
    polynomial_print(distance_trvd_dec_car);
    printf("The distance_1 travelled by the car is %.4f\n", distance_1 );
    printf("The distance_2 distance travelled by the car is %.4f\n");
    */
    printf("%.4f\n", time_of_stop );
    printf("%f\n", distance_1 + distance_2);
    
}

