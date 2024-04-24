#include<iostream>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
int xc=300,yc=300;
void displayPoint(int x,int y)
{
glColor3f(0,1,0);
glPointSize(2);
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
}
void SimpleLine(float x1,float y1,float x2,float y2)
{
float step;
float dx = x2-x1;
float dy = y2-y1;
if(abs(dx)>= abs(dy))
{
step=abs(dx);
}
else
step =abs(dy);
float Xinc =dx/(float) step;
float Yinc =dy/(float) step;
float x=x1;
float y=y1;
for(int i=0;i<=step;i++)
{
displayPoint(x,y);
x=x+Xinc;
y=y+Yinc;
}
glFlush();
}
void plotPoint(int xc,int yc,int x,int y)
{
glColor3f(0,1,1);
glPointSize(2);
glBegin(GL_POINTS);
glVertex2i(xc+x,yc+y);
glVertex2i(xc+y,yc+x);
glVertex2i(xc-x,yc+y);
glVertex2i(xc-y,yc+x);
glVertex2i(xc-x,yc-y);
glVertex2i(xc-y,yc-x);
glVertex2i(xc+x,yc-y);
glVertex2i(xc+y,yc-x);
glEnd();
}
void bresenhams(int xc,int yc,int radius)
{
int x=0;
int y=radius;
plotPoint(xc,yc,x,y);
int p=3-2*radius;
do{
if(p<0)
{
x++;
p=p+4*x+6;
}
if(p>=0)
{
x++;
y--;
p=p+4*(x-y)+10;
}
plotPoint(xc,yc,x,y);
}while(x<=y);
glFlush();
}
void keyboard(unsigned char key,int x,int y)
{
int r=70;
switch(key)
{
case 's':
glClearColor(1.0,1.0,1.0,1.0);
glClear(GL_COLOR_BUFFER_BIT);
bresenhams(xc,yc,100);
break;
case 'c':
glClearColor(1.0,1.0,1.0,1.0);
glClear(GL_COLOR_BUFFER_BIT);
bresenhams(xc,yc,50);
bresenhams(xc,yc,200);
break;
case 'f':
glClearColor(1.0,1.0,1.0,1.0);
glClear(GL_COLOR_BUFFER_BIT);
bresenhams(xc,yc,r);
bresenhams(xc+r,yc,r);
bresenhams(xc-r,yc,r);
bresenhams(xc,yc-r,r);
bresenhams(xc,yc+r,r);
break;
case 'p':
glClearColor(1.0,1.0,1.0,1.0);
glClear(GL_COLOR_BUFFER_BIT);
bresenhams(xc,yc,r);
bresenhams(xc+2*r,yc,r);
bresenhams(xc-2*r,yc,r);
bresenhams(xc,yc-2*r,r);
bresenhams(xc,yc+2*r,r);
break;
case 'q':
glClearColor(1.0,1.0,1.0,1.0);
glClear(GL_COLOR_BUFFER_BIT);
bresenhams(xc,yc,r);
bresenhams(xc+r+(r/1.5),yc,(r/1.5));
bresenhams(xc,yc+r+(r/1.5),(r/1.5));
bresenhams(xc-r-(r/1.5),yc,(r/1.5));
bresenhams(xc,yc-r-(r/1.5),(r/1.5));
bresenhams(xc+r+(r/5.2),yc+r+(r/5.2),(r/1.5));
bresenhams(xc-r-(r/5.2),yc-r-(r/5.2),(r/1.5));
bresenhams(xc+r+(r/5.2),yc-r-(r/5.2),(r/1.5));
bresenhams(xc-r-(r/5.2),yc+r+(r/5.2),(r/1.5));
break;
}
glutPostRedisplay();
}
void initialize()
{
glClearColor(1.0,1.0,1.0,1.0);
glClear(GL_COLOR_BUFFER_BIT);
gluOrtho2D(0,600,600,0);
}
void primitives(void)
{
glColor3f(1,0,0);
SimpleLine(0,300,600,300);
SimpleLine(300,0,300,600);
glutKeyboardFunc(keyboard);
}
int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE);
glutInitWindowPosition(0,0);
glutInitWindowSize(600,600);
glutCreateWindow("Circle");
initialize();
cout<<"s:Simple Circle";
cout<<"\n c: Concentric Circle";
cout<<"\n f: Intersecting Circle";
cout<<"\n p: four circles around center Circle";
cout<<"\n q: eight circles around center Circle";
glutDisplayFunc(primitives);
glutMainLoop();
return 0;
}
