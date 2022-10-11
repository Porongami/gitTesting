#include <cstdio>   

float Q_rsqrt(float number){
    long i;                                     //32 bit number
    float x2, y;                                //32 bit decimal number
    const float threehalfs = 1.5F;              // 1.5 (also 32 bit)

    x2 = number * 0.5F;
    y  = number;
    i  = * ( long * ) &y;                       // evil floating point bit level hacking
    i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
    y  = * ( float * ) &i;
    y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
    // y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed
    return y;
}

int main(){
    float number = 0.0;
    printf("Enter a number: ");
    scanf("%f", &number);
    printf("The square root of %f is %f", number, Q_rsqrt(number));
    return 0;
}