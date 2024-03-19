#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int xc = 10, yc =0, r = 100;        //circle Specs, (center x,y and radius)

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

        
        glVertex2i(y+xc, x+yc);
        glVertex2i(y+xc, -x+yc);
        glVertex2i(-y+xc,x+yc);
        glVertex2i(-y+xc,-x+yc);
        
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
}

void display()
{
 glClearColor(1, 1, 1, 1);
 glClear(GL_COLOR_BUFFER_BIT);

 glBegin(GL_POINTS);
 glColor3f(1, 0, 0);

 bresenhamAlgorithm();
 
 glColor3f(0, 0, 1);

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
