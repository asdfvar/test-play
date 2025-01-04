// See: learnopengl.com/Getting-started/Textures

#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void display (void)
{
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glEnable (GL_TEXTURE_2D);

   int width, height, nrChannels;
   unsigned char* data = stbi_load ("container.jpg", &width, &height, &nrChannels, 0);

   GLuint texture;
   glGenTextures (1, &texture);
   glBindTexture (GL_TEXTURE_2D, texture);
   glTexImage2D (GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

   glTexParameterf (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
   glTexParameterf (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

   glTexParameterf (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameterf (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

   glBindTexture (GL_TEXTURE_2D, texture);

   glVertexAttribPointer (1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));

   glBegin (GL_QUADS);
      glTexCoord2f (0.0f, 1.0f); glVertex2f (0.0f, 0.0f);
      glTexCoord2f (1.0f, 1.0f); glVertex2f (0.5f, 0.0f);
      glTexCoord2f (1.0f, 0.0f); glVertex2f (0.5f, 0.5f);
      glTexCoord2f (0.0f, 0.0f); glVertex2f (0.0f, 0.5f);
   glEnd ();

   stbi_image_free (data);

   glutSwapBuffers ();
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

   glutMainLoop ();

   return 0;
}
