#include <iostream>
#include <math.h> //for atan, abs and pow function

int main(){

  const int SIZE = 50; //defines the x and y dimesions of the grid
  int solutions  = pow(SIZE, 2)*3; // this takes account into the triangles that come in triples

  #define PI 3.141592653589793 //defining a sufficiently accurate pi value

  for(long double x = SIZE; x > 0; x--){
    for(long double y = SIZE; y > 0; y--){
        for(long double x1 = x; x1 < SIZE+1; x1++){
          for(long double y1 = y; y1 > -1; y1--){

            long double l1M = atan(y/x); //finds the inverse of tan for the gradient of line1
            long double l2M = atan((y1-y)/(x1-x)); //finds the inverse of tan for the gradient of line2

            double resultantL1L2 = (PI - abs(l1M - l2M)) * 180/PI; // finds the resultant angle and converts it into degrees,
                                                                   // **REMOVE PI AND CALCULATE AS RADIANS TO INCREASE EFFICIENCY**
            // if the resultant angle == 90 degrees the angle must be right angled, therefore add to because these triangles appear in pairs.
            if(resultantL1L2 == 90){
                //can be optimized that after a solution is found, just following the gradient down and adding +2 every 'm' removing the need
                //for processor heavy calculation
                solutions+=2;
            }
          }
        }
      }
    }

  std::cout << solutions << std::endl; // print number of solutions found
}
