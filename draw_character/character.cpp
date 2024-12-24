#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <iostream>

static float pos_x = 0.0f;
static float pos_y = 0.0f;

void display (void)
{
   glClear (GL_COLOR_BUFFER_BIT);

   glColor3ub (255, 0, 0);
   glBegin (GL_POLYGON);
      glVertex2f (pos_x + -0.05f, pos_y + -0.05f);
      glVertex2f (pos_x + 0.05f,  pos_y + -0.05f);
      glVertex2f (pos_x + 0.0f,   pos_y +  0.05f);
   glEnd ();

   glutSwapBuffers ();
}

void keyboardDown (unsigned char key, int x, int y)
{
   switch (key) {
      case 'q':
         exit (1);
         break;

      case 'w':
         pos_y += 0.05f;
         break;

      case 'a':
         pos_x -= 0.05f;
         break;

      case 's':
         pos_y -= 0.05f;
         break;

      case 'd':
         pos_x += 0.05f;
         break;
   }

   glutPostRedisplay ();
}


void idle (void)
{
}

int main (int argc, char** argv)
{

   const int windowsizex = 600;
   const int windowsizey = 600;

   glutInit (&argc, argv);
   glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE);
   glutInitWindowSize (windowsizex, windowsizey);
   glutInitWindowPosition (50, 50);
   glutCreateWindow ("character example");

   glutDisplayFunc (display);
   glutKeyboardFunc (keyboardDown);
   glutIdleFunc (idle);

   glutMainLoop ();

   return 0;
}
