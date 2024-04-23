// This code example is created for educational purpose
// by Thorsten Thormaehlen (contact: www.thormae.de).
// It is distributed without any warranty.

#include <GL/freeglut.h> // we use glut here as window manager
#define _USE_MATH_DEFINES
#include <math.h>

class Renderer1 {

public:
    float t;

public:
    Renderer1() : t(0.0) {}

public:

    void resize1(int w, int h) {
        glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(30.0, (float)w / (float)h, 2.0, 20.0);
    }

    void display1() {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        // camera orbits in the y=10 plane
        // and looks at origin
        double rad = M_PI / 180.0f * t;
        gluLookAt(10.0 * cos(rad), 10.0, 10.0 * sin(rad), // eye
            0.0, 0.0, 0.0, // look at
            0.0, 1.0, 0.0); // up

        //draw cube at origin
        drawCube1();

        glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
        glTranslatef(2.5f, 0.0f, 0.0f);
        glScalef(0.5f, 0.5f, 0.5f);

        drawCube1(); //draw transformed cube
    }

    void init() {
        glEnable(GL_DEPTH_TEST);
    }
private:
    void drawCube1() {
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glEnd();
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex3f(1.0f, 1.0f, -1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        glEnd();
        glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);
        glEnd();
        glColor3f(1.0, 1.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glEnd();
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex3f(1.0f, 1.0f, -1.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glEnd();
        glColor3f(0.0, 1.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex3f(1.0f, -1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);
        glEnd();
    }
};

//this is a static pointer to a Renderer used in the glut callback functions
static Renderer1* renderer1;

//glut static callbacks start
static void glutResize1(int w, int h)
{
    renderer1->resize1(w, h);
}

static void glutDisplay1()
{
    renderer1->display1();
    glutSwapBuffers();
}

static void timer1(int v)
{
    float offset = 1.0f;
    renderer1->t += offset;
    glutDisplay1();
    glutTimerFunc(unsigned(20), timer1, ++v);
}