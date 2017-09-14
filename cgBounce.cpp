#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

void ball(int x, int y){
	setcolor(YELLOW);
	circle(x, y, 25);
	floodfill(x, y, YELLOW);
}

void box(){
    line(50, 25, 50, 475);
    line(50, 25, 550, 25);
    line(550, 25, 550, 475);
}

int main(){
	int gd=DETECT, gm;
	initgraph(&gd, &gm, NULL);
	
	int i, j, si=1, xbar=100, sbar=1;
	for(i=300; ; ){
		for(j=50; j<=450; j++){
			cleardevice();
			box();
			if(i+25==550){
			    si=-1;
			}else if(i-25==50){
                si=1;			    
			}
			if(j%10==0){
				i+=si;
			}
			if(sbar>0){
			    if(xbar-i <= j){
			        xbar+=sbar;
			    }else
			        sbar=-1;
			}else{
			    if(i-xbar <= j){
			        xbar+=sbar;
			    }else
			        sbar=1;
			}
			ball(i, j);
			bar(xbar-50, 475, xbar, 485);
			delay(1);
		}
		for(j=450; j>=50; j--){
			cleardevice();
			box();
			if(i+25==550){
			    si=-1;
			}else if(i-25==50){
                si=1;			    
			}
			if(j%10==0){
				i+=si;
			}
			if(sbar>0){
			    if(xbar-i <= j){
			        xbar+=sbar;
			    }else
			        sbar=-1;
			}else{
			    if(i-xbar <= j){
			        xbar+=sbar;
			    }else
			        sbar=1;
			}
			ball(i, j);
			bar(xbar-50, 475, xbar, 485);
			delay(1);
		}
	}
	
	getch();
	closegraph();
	
return 0;
}
