#include <iostream>
#include <math.h>

int main(){

  const int SIZE = 50;
  int solutions  = pow(SIZE, 2)*3;

  #define PI 3.141592653589793

  for(long double x = SIZE; x > 0; x--){
    for(long double y = SIZE; y > 0; y--){
        for(long double x1 = x; x1 < SIZE+1; x1++){
          for(long double y1 = y; y1 > -1; y1--){

            long double l1M = atan(y/x);
            long double l2M = atan((y1-y)/(x1-x));

            double resultantL1L2 = (PI - abs(l1M - l2M)) * 180/PI;

            if(resultantL1L2 == 90){
                solutions+=2;
            }
          }
        }
      }
    }

  std::cout << solutions << std::endl;
}
