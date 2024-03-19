#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int counter = 0;
int xs = 0, ys = 0, r = 100;
int xc = 10, yc =0;
float theta = 0;

void firstOctant(int r, int xc, int yc){
    int x, y, e;
    x = (int) (r*sqrt(2)/2);
    y = x;
    e = - r;
    while (y >= 0) {
        glVertex2i(x+xc, y+yc);
        glVertex2i(-x+xc, y+yc);
        glVertex2i(x+xc, -y+yc);
        glVertex2i(-x+xc, -y+yc);
        
        y--;
        e = e + 2 * y + 1;
        if (e >= 0) {
            x++;
            e = e - 2 * x + 2;
        }
    }
}

void secondOctant(int r, int xc, int yc){
    int x, y, e;
    x = 0;
    y = r;
    e = - r;
    while (x <= y) {
        glVertex2i(x+xc, y+yc);
        glVertex2i(-x+xc, y+yc);
        glVertex2i(x+xc, -y+yc);
        glVertex2i(-x+xc, -y+yc);
        
        x++;
        e = e + 2 * x + 1;
        if (e >= 0) {
            y--;
            e = e - 2 * y + 2;
        }
    }
}

void bresenhamAlgorithm(){
    secondOctant(r,xc,yc);
    firstOctant(r,xc,yc);
}

void display()
{
 glClearColor(1, 1, 1, 1);
 glClear(GL_COLOR_BUFFER_BIT);

 glBegin(GL_POINTS);
 glColor3f(1, 0, 0);

 bresenhamAlgorithm();
 
 glColor3f(0, 0, 1);

//     if(counter%2000==0){
//         theta = M_PI/16 + theta;
//         ye = (int) 100*(sin(theta));
//         xe = (int) 100*(cos(theta));
//     }

//  counter++;
 glutPostRedisplay();
 glEnd();
 glFlush();
}

int main(int argc, char** argv)
{
 glutInit(&argc,argv);
 glutInitWindowPosition(150, 150);
 glutInitWindowSize(640, 480);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutCreateWindow("OpenGL application");
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-240, 240, -180, 180);
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}
