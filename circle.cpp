// Author : velan
// Date : Jan-2-26 at 11:35pm
// Description : Making Circle through OpenGl
// Launguage : c++ with clangd comipler

// Algorithm
/*
 * 1.Initiate a Window
 * 2.Draw a Circle
 * 3.Close the Window
 */

#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <cmath>

void drawCircle(float cx, float cy, float r, int num_segments) {
  glBegin(GL_LINE_LOOP); // Use GL_LINE_LOOP for an empty outline
  for (int i = 0; i < num_segments; i++) {
    // Calculate angle in radians
    float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);

    // Calculate x and y based on polar coordinates
    float x = r * cosf(theta);
    float y = r * sinf(theta);

    // Output the vertex
    glVertex2f(x + cx, y + cy);
  }
  glEnd();
}

void Display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0f, 0.0f, 1.0f);
  drawCircle(0.0f, 0.0f, 0.5f, 100);
  glFlush();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(600, 600);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("OpenGl - Circle");

  // Background color : Transparent
  glClearColor(0, 0, 0, 0);

  glutDisplayFunc(Display);
  glutMainLoop();

  return 0;
}
