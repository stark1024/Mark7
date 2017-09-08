#include <iostream>
#include <math.h>
#include <graphics.h>
using namespace std;

int main(){
	int gd=DETECT, gm;
	initgraph(&gd, &gm, NULL);
	int a = getmaxx()/2;
	int b = getmaxy()/2;
	int x, y1, y, r=200;
	while(1){
	for(x=a-r; x<a+r; x++){
		cleardevice();
		setcolor(YELLOW);
		circle(a, b, 50);
		floodfill(a, b, YELLOW);
		circle(a, b, r);
		y1 = (r*r) - ((x-a)*(x-a));
		y = sqrt(y1) + b;
		setcolor(BLUE);
		circle(x, y, 50);
		floodfill(x, y, BLUE);
		delay(10);
	}
	delay(10);
	for(x=a+r; x>a-r; x--){
		cleardevice();
		setcolor(YELLOW);
		circle(a, b, 50);
		floodfill(a, b, YELLOW);
		circle(a, b, r);
		y1 = (r*r) - ((x-a)*(x-a));
		y = b - sqrt(y1);
		setcolor(BLUE);
		circle(x, y, 50);
		floodfill(x, y, BLUE);
		delay(10);
	}
	delay(10);
	}
	getch();
	closegraph();
	
return 0;
}
