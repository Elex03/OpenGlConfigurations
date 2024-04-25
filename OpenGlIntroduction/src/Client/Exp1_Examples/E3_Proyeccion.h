// This code example is created for educational purpose
// by Thorsten Thormaehlen (contact: www.thormae.de).
// It is distributed without any warranty.

#include <GL/freeglut.h> // we use glut here as window manager

#include <math.h>

class Renderer2 {

public:
  float t;

public:
  Renderer2() : t(0.0), width(0), height(0) {}

public:
  void display2() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // top right viewport (look from front)
    glViewport(width/2, height/2, width/2, height/2);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    drawFrame2();
    // set camera (look from positive x-direction)
    gluLookAt(10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
    // draw scene
    drawSceneGrid2();
    drawRotatingPyramid2();

    // bottom left viewport (look from left)
    glViewport(0, 0, width/2, height/2);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    drawFrame2();
     // set camera (look from negative y-direction)
    gluLookAt(0.0, -10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
    // draw scene
    drawSceneGrid2();
    drawRotatingPyramid2();

    // top left viewport (look from top)
    glViewport(0, height/2, width/2, height/2);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    drawFrame2();
    // set camera (look from positive z-direction)
     gluLookAt(0.0, 0.0, 10.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0);
    // draw scene
    drawSceneGrid2();
    drawRotatingPyramid2();

    // bottom right viewport (perspective)
    glViewport(width/2, 0, width/2, height/2);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    drawFrame2();
    // set camera
    gluLookAt(8.0, -2.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
    // draw scene
    drawSceneGrid2();
    drawRotatingPyramid2();
  }

  void init2() {
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_CULL_FACE);
  }

  void resize2(int w, int h) {
    width = w;
    height = h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective (30.0, (float)width/(float)height, 2.0, 20.0);

  }

private:
  int width;
  int height;

private:
  void drawFrame2() {
      glLineWidth(2.0f);
      glMatrixMode(GL_PROJECTION);
      glPushMatrix();
      glLoadIdentity();
      glColor3f(1.0f, 1.0f, 1.0f);
      glBegin(GL_LINE_LOOP);
      glVertex3f(-1.0f, 1.0f, 0.0f);
      glVertex3f( 1.0f, 1.0f, 0.0f);
      glVertex3f( 1.0f,-1.0f, 0.0f);
      glVertex3f(-1.0f,-1.0f, 0.0f);
      glEnd();
      glPopMatrix();
      glMatrixMode(GL_MODELVIEW);
      glLineWidth(1.0f);
  }

  void drawSceneGrid2() {
      glColor3f(0.3f, 0.3f, 0.3f);
      glBegin(GL_LINES);
      for(unsigned i=0; i<=10; i++) {
        glVertex3f(-5.0f+i, -5.0f,   0.0f);
        glVertex3f(-5.0f+i,  5.0f,   0.0f);
        glVertex3f(-5.0f,   -5.0f+i, 0.0f);
        glVertex3f( 5.0f,   -5.0f+i, 0.0f);
      }
      glEnd();

    glColor3f(0.0f, 0.0f, 1.0f);
    drawCoordinateAxisZ2();
    glColor3f(0.0f, 1.0f, 0.0f);
    drawCoordinateAxisY2();
    glColor3f(1.0f, 0.0f, 0.0f);
    drawCoordinateAxisX2();
  }

  void drawCoordinateAxisZ2() {
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f); // z-axis
    glVertex3f(0.0f, 0.0f, 2.0f);
    glEnd();
    glLineWidth(1.0f);

    // z-axis tip
    glBegin(GL_TRIANGLES);
    glVertex3f( 0.0f, 0.0f, 2.0f);
    glVertex3f(-0.05f, 0.05f, 1.9f);
    glVertex3f( 0.05f, 0.05f, 1.9f);
    glVertex3f( 0.0f,  0.0f, 2.0f);
    glVertex3f( 0.05f, -0.05f, 1.9f);
    glVertex3f(-0.05f, -0.05f, 1.9f);
    glVertex3f( 0.0f,  0.0f, 2.0f);
    glVertex3f( 0.05f,  0.05f, 1.9f);
    glVertex3f( 0.05f, -0.05f, 1.9f);
    glVertex3f( 0.0f,  0.0f, 2.0f);
    glVertex3f(-0.05f, -0.05f, 1.9f);
    glVertex3f(-0.05f,  0.05f, 1.9f);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f( 0.05f, -0.05f, 1.9f);
    glVertex3f( 0.05f,  0.05f, 1.9f);
    glVertex3f(-0.05f,  0.05f, 1.9f);
    glVertex3f(-0.05f, -0.05f, 1.9f);
    glEnd();
  }

  void drawCoordinateAxisX2() {
      glPushMatrix();
      glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
      drawCoordinateAxisZ2();
      glPopMatrix();
  }

  void drawCoordinateAxisY2() {
      glPushMatrix();
      glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
      drawCoordinateAxisZ2();
      glPopMatrix();
  }

  void drawRotatingPyramid2() {
    glRotatef(t, 0.0f, 0.0f, 1.0f);
    drawPyramid2();
  }

  void drawPyramid2() {
    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_TRIANGLES);
    glVertex3f( 0.0f, 0.0f, 1.5f);
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glVertex3f( 1.0f, 1.0f, 0.0f);
    glEnd();
    glColor3f(0.0f,1.0f,0.0f);
    glBegin(GL_TRIANGLES);
    glVertex3f( 0.0f,  0.0f, 1.5f);
    glVertex3f( 1.0f, -1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glEnd();
    glColor3f(0.0f,0.0f,1.0f);
    glBegin(GL_TRIANGLES);
    glVertex3f( 0.0f,  0.0f, 1.5f);
    glVertex3f( 1.0f,  1.0f, 0.0f);
    glVertex3f( 1.0f, -1.0f, 0.0f);
    glEnd();
    glColor3f(1.0f,1.0f,0.0f);
    glBegin(GL_TRIANGLES);
    glVertex3f( 0.0f,  0.0f, 1.5f);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glVertex3f(-1.0f,  1.0f, 0.0f);
    glEnd();
    glColor3f(0.0f,1.0f,1.0f);
    glBegin(GL_POLYGON);
    glVertex3f( 1.0f, -1.0f, 0.0f);
    glVertex3f( 1.0f,  1.0f, 0.0f);
    glVertex3f(-1.0f,  1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glEnd();
  }
};

//this is a static pointer to a Renderer used in the glut callback functions
static Renderer2 *renderer2;

//glut static callbacks start
static void glutResize2(int w, int h)
{
  renderer2->resize2(w,h);
}

static void glutDisplay2()
{
  renderer2->display2();
  glutSwapBuffers();
}

static void timer(int v)
{
  float offset = 1.0f;
  renderer2->t += offset;
  glutDisplay2();
  glutTimerFunc(unsigned(20), timer, ++v);
}

