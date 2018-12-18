#include <stdio.h>
#include <windows.h>

main(){
	float b3 = 246.94;
	float c4 = 261.63;
	float c_4 =277.18;
	float d4 = 293.66;
	float d_4 =311.13;
	float e4 = 329.63;
	float f4 = 349.23;
	float f_4= 369.99;
	float g4 = 392.00;
	float g_4= 415.30;
	float a4 = 440.00;
	float a_4= 466.16;
	float b4 = 493.88;
	
	int one = 152;
	
	while(1){
			Beep(d4 , 1000);
	Beep(e4 , 1000);
	Beep(b3 , 1000);
	Beep(c4 , 1000);
	
	
	Beep(d4 , 250);
	Beep(d4 , 250);
	Beep(d4 , 250);
	Beep(d4 , 250);
	
	Beep(e4 , 250);
	Beep(e4 , 250);
	Beep(e4 , 250);
	Beep(e4 , 250);
	
	Beep(b3 , 250);
	Beep(b3 , 250);
	Beep(b3 , 250);
	Beep(b3 , 250);
	
	Beep(c4 , 250);
	Beep(c4 , 250);
	Beep(c4 , 250);
	Beep(c4 , 250);
	
	Beep(d4 , 250);
	
	}
}
	/*
	
		Beep(f_4 , 4*one);
		Beep(g_4 , 4*one);
		Beep(g_4 , 6*one);
		Beep(f_4 , 2*one);
		
		Beep(g_4 , 4*one);
		Beep(a_4 , 4*one);
		Beep(b4 , 8*one);
		
		Beep(g_4 , 4*one);
		Beep(b4 , 4*one);
		Beep(a_4 , 6*one);
		Beep(g_4 , 2*one);
		
		Beep(f_4 , 4*one);
		Beep(a_4 , 2*one);
		Beep(f_4 , 2*one);
		Beep(g_4 , 8*one);
	
*/

