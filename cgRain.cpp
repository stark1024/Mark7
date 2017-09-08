#include<iostream>
#include<graphics.h>
using namespace std;

void cloud(){
	int i;
	for(i=0; i<getmaxx(); i+=100){
		if(i%3 == 0)
			sector(i, 0, 0, 180, 75, 75);
		if(i%3 == 1)
			sector(i, 0, 0, 180, 50, 50);
		if(i%3 == 2)
			sector(i, 0, 0, 180, 25, 25);
	}
}

void car(int x){
	line(0, 450, getmaxx(), 450);
	line(x, 400, x+100, 400);
	line(x, 430, x+100, 430);
	line(x, 400, x, 430);
	line(x+100, 400, x+100, 430);
	circle(x+30, 435, 15);
	circle(x+70, 435, 15);
	floodfill(x+30, 430, WHITE);
	floodfill(x+70, 430, WHITE);
	floodfill(x+30, 440, WHITE);
	floodfill(x+70, 440, WHITE);
}

void rain(int x){
	int i, j, k;
	for(i=-getmaxx(), j=50; i<600, j<450; i+=20, j+=40){
		if(j%100 == 0){
			cleardevice();
		}
		cloud();
		car(x);
		if(x%2 == 0){
			for(k=0; k<=1200; k+=140){
				if((i+k+6)<(x+10) || (i+k+6)>(x+110) || j<380)
					line(i+k, j, i+k+6, j+12);
				if((i+k+76)<(x+10) || (i+k+76)>(x+110) || (j+20)<380)
					line(i+k+70, j+20, i+k+76, j+32);
			}	
		}else{
			for(k=0; k<=1200; k+=140){
				if((i+k+106)<(x+10) || (i+k+106)>(x+110) || (j+20)<380)
					line(i+k+100, j+20, i+k+106, j+32);
				if((i+k+36)<(x+10) || (i+k+36)>(x+110) || j<380)
					line(i+k+30, j, i+k+36, j+12);
			}
		}
		delay(5);
	}
}

int main(){
	int gd=DETECT, gm;
	initgraph(&gd, &gm, NULL);
	
	int i=0;
	while(i!=(getmaxx()-100)){
		cleardevice();
		rain(i);
		i++;
	}
	
	getch();
	closegraph();
	
return 0;
}

