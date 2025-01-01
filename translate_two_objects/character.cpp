#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <iostream>

static float a_pos_x = 0.0f;
static float a_pos_y = 0.0f;

static float b_pos_x = 0.0f;
static float b_pos_y = 0.0f;

void display (void)
{
   glClear (GL_COLOR_BUFFER_BIT);

   glPushMatrix ();
   glTranslatef (a_pos_x, a_pos_y, 0.0f);
   glColor3ub (255, 0, 0);
   glBegin (GL_POLYGON);
      glVertex2f (-0.05f, -0.05f);
      glVertex2f ( 0.05f, -0.05f);
      glVertex2f (  0.0f,  0.05f);
   glEnd ();
   glPopMatrix ();

   glPushMatrix ();
   glTranslatef (b_pos_x, b_pos_y, 0.0f);
   glColor3ub (0, 255, 0);
   glBegin (GL_POLYGON);
      glVertex2f (-0.05f, -0.05f);
      glVertex2f ( 0.05f, -0.05f);
      glVertex2f (  0.0f,  0.05f);
   glEnd ();
   glPopMatrix ();

   glutSwapBuffers ();
}

void keyboardDown (unsigned char key, int x, int y)
{
   switch (key) {
      case 'q':
         exit (1);
         break;

      case 'w':
         a_pos_y += 0.05f;
         break;

      case 'a':
         a_pos_x -= 0.05f;
         break;

      case 's':
         a_pos_y -= 0.05f;
         break;

      case 'd':
         a_pos_x += 0.05f;
         break;

      case 'i':
         b_pos_y += 0.05f;
         break;

      case 'j':
         b_pos_x -= 0.05f;
         break;

      case 'k':
         b_pos_y -= 0.05f;
         break;

      case 'l':
         b_pos_x += 0.05f;
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
