#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <wiringPi.h>
#include <softServo.h>
#include <math.h>

#define value 100

int main(void)                        
{                                     
        if (wiringPiSetup() == -1)            
        {                                     
                printf("Setup GPIO error!\n");
                return -1;            
        }  

	softServoSetup(13, 12, 3, 2, -1, -1, -1, -1);
	softServoWrite(13, value);
	softServoWrite(12, value);
	softServoWrite(3, value);
	softServoWrite(2, value);	
	float t=0.;

	while(1){
	        softServoWrite(13, 500+750*sin(2*3.1415926535*t));
        	t+=0.001;
		usleep(1000);
        }
        
	return 0;
}
