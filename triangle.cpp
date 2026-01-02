// Author : velan
// Date : Jan-1-26
// Description : Making a graphical program though OPenGl

#define GL_SILENCE_DEPRECATION // Hide Apple's "OpenGL is depressed" warning
#include <GLUT/glut.h>         //Native Mac window management
#include <OpenGL/gl.h>         //Basic OPenGl functions

void Display();

// Start of Program
int main(int argc, char **argv) {
  glutInit(&argc, argv);                 // Initalize GLUT
  glutCreateWindow("Native Mac OpenGL"); // Create the window
  glutInitWindowSize(1080, 1920);        // Set window size
  glutDisplayFunc(Display);              // Tell GLUT how to draw
  glutMainLoop();                        // Keep the window open

  // End of Program
  return 0;
}

void Display() {
  // 1.clear the Screen to black
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  // 2.Draw a simple colored trinagle
  glBegin(GL_TRIANGLES);
  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex2d(-0.5f, -0.5f);

  glColor3f(0.0f, 1.0f, 0.0f);
  glVertex2d(0.5f, -0.5f);

  glColor3f(0.0f, 0.0f, 1.0f);
  glVertex2d(0.0f, 0.5f);
  glEnd();

  // 3. Push the command to gpu
  glFlush();
}
