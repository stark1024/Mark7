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
    line(50, 25, 600, 25);
    line(600, 25, 600, 475);
}

int main(){
	int gd=DETECT, gm;
	initgraph(&gd, &gm, NULL);
	
	int i, j, si=1, xbar=300, sbar=1;
	for(i=300; ; ){
		for(j=449; j>=50; j--){
			cleardevice();
			box();
			if(i+25==600){
			    si=-1;
			}else if(i-25==50){
                si=1;			    
			}
			if(j%10==0){
				i+=si;
			}
			if(sbar>0){
			    if(xbar-i <= 400){
			        xbar+=sbar;
			    }else
			        sbar=-1;
			}else{
			    if(i-xbar <= 400){
			        xbar+=sbar;
			    }else
			        sbar=1;
			}
			ball(i, j);
			bar(xbar-25, 475, xbar+25, 485);
			delay(5);
		}
		for(j=50; j<=449; j++){
			cleardevice();
			box();
			if(i+25==600){
			    si=-1;
			}else if(i-25==50){
                si=1;			    
			}
			if(j%10==0){
				i+=si;
			}
			if(sbar>0){
			    if(xbar-i <= 400){
			        xbar+=sbar;
			    }else
			        sbar=-1;
			}else{
			    if(i-xbar <= 400){
			        xbar+=sbar;
			    }else
			        sbar=1;
			}
			ball(i, j);
			bar(xbar-25, 475, xbar+25, 485);
			delay(5);
		}
	}
	
	getch();
	closegraph();
	
return 0;
}
