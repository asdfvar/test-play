#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <iostream>
#include <chrono>

static float angle = 0.0f;
#define TIME_STEP 10 // milliseconds

static unsigned long time_accumulator = 0;
static unsigned long start = 0;
static unsigned long end = 0;

void display (void)
{
   glClear (GL_COLOR_BUFFER_BIT);

   glPushMatrix ();
   glRotatef (angle, 0.0f, 0.0f, 1.0f);
   glColor3ub (255, 0, 0);
   glBegin (GL_POLYGON);
      glVertex2f (-0.05f, -0.05f);
      glVertex2f (0.05f,  -0.05f);
      glVertex2f (0.0f,    0.05f);
   glEnd ();
   glPopMatrix ();

   glutSwapBuffers ();
}

unsigned long time_count (void)
{
   auto system_time = std::chrono::system_clock::now ().time_since_epoch ();
   return std::chrono::duration_cast<std::chrono::milliseconds> (system_time).count ();
}

void idle (void)
{
   while (time_accumulator >= TIME_STEP)
   {
      angle += 90.0f * static_cast<float> (TIME_STEP) / 1000.0f;
      time_accumulator -= TIME_STEP;
   }
   glutPostRedisplay ();

   end = time_count ();
   while (end == start) end = time_count ();
   time_accumulator += end - start;
   start = end;
}

int main (int argc, char** argv)
{
   const int windowsizex = 600;
   const int windowsizey = 600;

   start = time_count ();
   end = start;

   glutInit (&argc, argv);
   glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE);
   glutInitWindowSize (windowsizex, windowsizey);
   glutInitWindowPosition (50, 50);
   glutCreateWindow ("character example");

   glutDisplayFunc (display);
   glutIdleFunc (idle);

   glutMainLoop ();

   return 0;
}
