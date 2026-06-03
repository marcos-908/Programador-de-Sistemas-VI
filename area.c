#include <stdio.h>
 
int main() {
 
    const double PI = 3.14159;
    double R = 0.0;
    double A = 0.0;
    
    scanf("%lf", &R);
    
    A=(R*R)*PI;
    
    printf("A=%.4lf\n", A);
 
    return 0;
}