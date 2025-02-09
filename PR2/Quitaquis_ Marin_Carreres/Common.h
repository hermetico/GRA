//////////////////////////////////////////////////////////////////////////////
//
//  --- Angel.h ---
//
//   The main header file for all examples from Angel 6th Edition
//   Renamed to Common.h
//
//////////////////////////////////////////////////////////////////////////////

#ifndef __ANGEL_H__
#define __ANGEL_H__

//----------------------------------------------------------------------------
// 
// --- Include system headers ---
//

#include <cmath>
#include <iostream>
#include <stdlib.h>

//  Define M_PI in the case it's not defined in the math header file
#ifndef M_PI
#  define M_PI  3.14159265358979323846
#endif

//----------------------------------------------------------------------------
//
// --- Include OpenGL header files and helpers ---
//
//   The location of these files vary by operating system.  We've included
//     copies of open-soruce project headers in the "GL" directory local
//     this this "include" directory.
//

#define GL_GLEXT_PROTOTYPES 1
# include  <GL/gl.h>
# include  <GL/glext.h>

// Define a helpful macro for handling offsets into buffer objects
#define BUFFER_OFFSET( offset )   ((GLvoid*) (offset))

//----------------------------------------------------------------------------
//
//  --- Include our class libraries and constants ---
//



namespace Common {

//  Defined constant for when numbers are too small to be used in the
//    denominator of a division operation.  This is only used if the
//    DEBUG macro is defined.
const GLfloat  DivideByZeroTolerance = GLfloat(1.0e-07);

//  Degrees-to-radians constant 
const GLfloat  DegreesToRadians = M_PI / 180.0;

char*
readShaderSource(const char* shaderFile);

}  // namespace Common

#include "vec.h"
#include "mat.h"




#define Print(x)  do { std::cerr << #x " = " << (x) << std::endl; } while(0)


//  Globally use our namespace in our example programs.
using namespace Common;

typedef struct {
      vec3 pmin;
      // a = anchura, h altura, p profunditat
      GLfloat a, h, p;
} Capsa3D;

typedef struct {
      vec2 pmin;
      float a, h;
} Capsa2D;




#endif // __ANGEL_H__
