#include <GL/freeglut.h>

void renderText(const char* text, int x, int y, void* font) {
  glRasterPos2i(x, y);
  while (*text) {
    glutBitmapCharacter(font, *text);
    ++text;
  }
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0f, 1.0f, 1.0f);
  const char* text = "Hello, OpenGL!";
  renderText(text, 200, 200, GLUT_BITMAP_9_BY_15);
  glutSwapBuffers();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(640, 480);
  glutCreateWindow("OpenGL Text Example");
  glutDisplayFunc(display);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 640.0, 0.0, 480.0, -1.0, 1.0);
  glutMainLoop();
  return 0;
}


// ❯ g++ draw0.cpp -o draw0 -lglut -lGLU -lGL
