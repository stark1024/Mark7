#include<iostream>
#include<graphics.h>
using namespace std;

void ball(int x, int y){
	setcolor(YELLOW);
	circle(x, y, 25);
	floodfill(x, y, YELLOW);
}

int main(){
	int gd=DETECT, gm;
	initgraph(&gd, &gm, NULL);
	
	int i, j, k=100, d, x=getmaxx(), y=getmaxy();
	for(i=100; i<x-100;){
		d=(x-i)/y;
		if(d<=1)
			d=1;
		for(j=y-85; j>50; j--, k+=(2*d)){
			cleardevice();
			if(j%10==0)
				i++;
			ball(i, j);
			bar(k-40, y-60, k+40, y-50);
			delay(1);
		}
		d=(x-i)/y;
		if(d<=1)
			d=1;
		for(j=50; j<y-85; j++, k-=(2*d)){
			cleardevice();
			if(j%10==0)
				i++;
			ball(i, j);
			bar(k-40, y-60, k+40, y-50);
			delay(1);
		}
		cout<<y<<endl;
	}
	getch();
	closegraph();
	
return 0;
}
