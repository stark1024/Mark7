#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

void dda(int xi, int yi, int xf, int yf){
        int dx=xf-xi, dy=yf-yi, steps, k;
        float inx, iny, x=xi, y=yi;
        if(abs(dx)>abs(dy)){
            steps=abs(dx);
        }else{
            steps=abs(dy);
        }
        inx=dx/(float)steps;
        iny=dy/(float)steps;
        x=x+0.5, y=y+0.5;
        putpixel(x, y, WHITE);
        for(k=0; k<steps; k++){
            x+=inx;
            y+=iny;
            putpixel(x, y, WHITE);
            delay(100);
        }
}

int main(){
    int gd=DETECT, gm;
    int xi, yi, xf, yf;
    cout<<"Enter initial points (x,y)\n";
    cin>>xi>>yi;
    cout<<"Enter final points (x,y)\n";
    cin>>xf>>yf;
    initgraph(&gd, &gm, NULL);
    dda(xi, yi, xf, yf);
    getch();
    closegraph();
    
return 0;
}
