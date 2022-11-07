#include <windows.h>
#include <GL/glut.h>

int k = 0;
char title[] = "3D Shapes with animation";
GLfloat anglePyramid = 0.0f; // Rotational angle for pyramid
GLfloat angleCube = 0.0f; // Rotational angle for cube
int refreshMills = 15; // refresh interval in milliseconds

void initGL() {
 glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
 glClearDepth(1.0f); // Set background depth to farthest
 glEnable(GL_DEPTH_TEST); // Enable depth testing for z-culling
 glDepthFunc(GL_LEQUAL); // Set the type of depth-test
 glShadeModel(GL_SMOOTH); // Enable smooth shading
 glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Nice perspective corrections
}

void display() {
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
 glMatrixMode(GL_MODELVIEW); // To operate on model-view matrix

 glLoadIdentity(); // Reset the model-view matrix
 glTranslatef(1.5f, 0.0f, -20.0f); // Move right and into the screen
 glRotatef(angleCube, 10.0f, 0.0f, 0.0f); // Rotate about (1,1,1)-axis [NEW]
 glBegin(GL_QUADS); // Begin drawing the color cube with 6 quads

 // 2
 glColor3f(0.0f, 1.0f, 0.0f); // Green
 {
 glVertex3f( 1.0f, 0.0f, 5.0f);
 glVertex3f( 0.0f, 0.0f, 4.0f);
 glVertex3f( 1.0f, 0.0f, 4.0f);
 glVertex3f( 2.0f, 0.0f, 4.5f);

 glVertex3f( 2.0f, 0.0f, 5.5f);
 glVertex3f( 1.0f, 0.0f, 5.0f);
 glVertex3f( 2.0f, 0.0f, 4.5f);
 glVertex3f( 3.0f, 0.0f, 4.5f);

 glVertex3f( 3.0f, 0.0f, 5.5f);
 glVertex3f( 2.0f, 0.0f, 5.5f);
 glVertex3f( 3.0f, 0.0f, 4.5f);
 glVertex3f( 4.0f, 0.0f, 4.0f);

 glVertex3f( 4.0f, 0.0f, 5.0f);
 glVertex3f( 3.0f, 0.0f, 5.5f);
 glVertex3f( 4.0f, 0.0f, 4.0f);
 glVertex3f( 5.0f, 0.0f, 4.0f);

 glVertex3f( 5.0f, 0.0f, 4.0f);
 glVertex3f( 4.0f, 0.0f, 4.5f);
 glVertex3f( 4.0f, 0.0f, 3.0f);
 glVertex3f( 5.0f, 0.0f, 2.5f);

 glVertex3f( 5.0f, 0.0f, 2.5f);
 glVertex3f( 4.0f, 0.0f, 3.0f);
 glVertex3f( 0.0f, 0.0f, 1.0f);
 glVertex3f( 2.0f, 0.0f, 1.0f);

 glVertex3f( 5.0f, 0.0f, 1.0f);
 glVertex3f( 0.0f, 0.0f, 1.0f);
 glVertex3f( 0.0f, 0.0f, 0.0f);
 glVertex3f( 5.0f, 0.0f, 0.0f);
}


 glColor3f(0.0f, 0.0f, 1.0f); // blue
 {
 glVertex3f( 1.0f, -1.0f, 5.0f);
 glVertex3f( 0.0f, -1.0f, 4.0f);
 glVertex3f( 1.0f, -1.0f, 4.0f);
 glVertex3f( 2.0f, -1.0f, 4.5f);

 glVertex3f( 2.0f, -1.0f, 5.5f);
 glVertex3f( 1.0f, -1.0f, 5.0f);
 glVertex3f( 2.0f, -1.0f, 4.5f);
 glVertex3f( 3.0f, -1.0f, 4.5f);

 glVertex3f( 3.0f, -1.0f, 5.5f);
 glVertex3f( 2.0f, -1.0f, 5.5f);
 glVertex3f( 3.0f, -1.0f, 4.5f);
 glVertex3f( 4.0f, -1.0f, 4.0f);

 glVertex3f( 4.0f, -1.0f, 5.0f);
 glVertex3f( 3.0f, -1.0f, 5.5f);
 glVertex3f( 4.0f, -1.0f, 4.0f);
 glVertex3f( 5.0f, -1.0f, 4.0f);

 glVertex3f( 5.0f, -1.0f, 4.0f);
 glVertex3f( 4.0f, -1.0f, 4.5f);
 glVertex3f( 4.0f, -1.0f, 3.0f);
 glVertex3f( 5.0f, -1.0f, 2.5f);

 glVertex3f( 5.0f, -1.0f, 2.5f);
 glVertex3f( 4.0f, -1.0f, 3.0f);
 glVertex3f( 0.0f, -1.0f, 1.0f);
 glVertex3f( 2.0f, -1.0f, 1.0f);

 glVertex3f( 5.0f, -1.0f, 1.0f);
 glVertex3f( 0.0f, -1.0f, 1.0f);
 glVertex3f( 0.0f, -1.0f, 0.0f);
 glVertex3f( 5.0f, -1.0f, 0.0f);

}


 glColor3f(1.0f, 1.0f, 1.0f); // White
 {
 glVertex3f( 0.0f, 0.0f, 0.0f);
 glVertex3f( 0.0f, -1.0f, 0.0f);
 glVertex3f( 5.0f, -1.0f, 0.0f);
 glVertex3f( 5.0f, 0.0f, 0.0f);

 glVertex3f( 5.0f, 0.0f, 0.0f);
 glVertex3f( 5.0f, -1.0f, 0.0f);
 glVertex3f( 5.0f, -1.0f, 1.0f);
 glVertex3f( 5.0f, 0.0f, 1.0f);

 glVertex3f( 5.0f, 0.0f, 1.0f);
 glVertex3f( 5.0f, -1.0f, 1.0f);
 glVertex3f( 2.0f, -1.0f, 1.0f);
 glVertex3f( 2.0f, 0.0f, 1.0f);

 glVertex3f( 2.0f, 0.0f, 1.0f);
 glVertex3f( 2.0f, -1.0f, 1.0f);
 glVertex3f( 5.0f, -1.0f, 2.5f);
 glVertex3f( 5.0f, 0.0f, 2.5f);

 glVertex3f( 5.0f, 0.0f, 2.5f);
 glVertex3f( 5.0f, -1.0f, 2.5f);
 glVertex3f( 5.0f, -1.0f, 4.0f);
 glVertex3f( 5.0f, 0.0f, 4.0f);

 glVertex3f( 5.0f, 0.0f, 4.0f);
 glVertex3f( 5.0f, -1.0f, 4.0f);
 glVertex3f( 4.0f, -1.0f, 5.0f);
 glVertex3f( 4.0f, 0.0f, 5.0f);

 glVertex3f( 4.0f, 0.0f, 5.0f);
 glVertex3f( 4.0f, -1.0f, 5.0f);
 glVertex3f( 3.0f, -1.0f, 5.5f);
 glVertex3f( 3.0f, 0.0f, 5.5f);

 glVertex3f( 3.0f, 0.0f, 5.5f);
 glVertex3f( 3.0f, -1.0f, 5.5f);
 glVertex3f( 2.0f, -1.0f, 5.5f);
 glVertex3f( 2.0f, 0.0f, 5.5f);

 glVertex3f( 2.0f, 0.0f, 5.5f);
 glVertex3f( 2.0f, -1.0f, 5.5f);
 glVertex3f( 1.0f, -1.0f, 5.0f);
 glVertex3f( 1.0f, 0.0f, 5.0f);

 glVertex3f( 1.0f, 0.0f, 5.0f);
 glVertex3f( 1.0f, -1.0f, 5.0f);
 glVertex3f( 0.0f, -1.0f, 4.0f);
 glVertex3f( 0.0f, 0.0f, 4.0f);

 glVertex3f( 0.0f, 0.0f, 4.0f);
 glVertex3f( 0.0f, -1.0f, 4.0f);
 glVertex3f( 1.0f, -1.0f, 4.0f);
 glVertex3f( 1.0f, 0.0f, 4.0f);

 glVertex3f( 1.0f, 0.0f, 4.0f);
 glVertex3f( 1.0f, -1.0f, 4.0f);
 glVertex3f( 2.0f, -1.0f, 4.5f);
 glVertex3f( 2.0f, 0.0f, 4.5f);

 glVertex3f( 2.0f, 0.0f, 4.5f);
 glVertex3f( 2.0f, -1.0f, 4.5f);
 glVertex3f( 3.0f, -1.0f, 4.5f);
 glVertex3f( 3.0f, 0.0f, 4.5f);

 glVertex3f( 3.0f, 0.0f, 4.5f);
 glVertex3f( 3.0f, -1.0f, 4.5f);
 glVertex3f( 4.0f, -1.0f, 4.0f);
 glVertex3f( 4.0f, 0.0f, 4.0f);

 glVertex3f( 4.0f, 0.0f, 4.0f);
 glVertex3f( 4.0f, -1.0f, 4.0f);
 glVertex3f( 4.0f, -1.0f, 3.0f);
 glVertex3f( 4.0f, 0.0f, 3.0f);

 glVertex3f( 4.0f, 0.0f, 3.0f);
 glVertex3f( 4.0f, -1.0f, 3.0f);
 glVertex3f( 0.0f, -1.0f, 1.0f);
 glVertex3f( 0.0f, 0.0f, 1.0f);

 glVertex3f( 0.0f, 0.0f, 1.0f);
 glVertex3f( 0.0f, -1.0f, 1.0f);
 glVertex3f( 0.0f, -1.0f, 0.0f);
 glVertex3f( 0.0f, 0.0f, 0.0f);

 {// K
 glVertex3f( 1.0f, 1.0f, 0.0f);
 glVertex3f( 2.0f, 1.0f, 0.0f);
 glVertex3f( 2.0f, -5.0f, 0.0f);
 glVertex3f( 1.0f, -5.0f, 0.0f);

 glVertex3f( 1.0f, 1.0f, 1.0f);
 glVertex3f( 2.0f, 1.0f, 1.0f);
 glVertex3f( 2.0f, -5.0f, 1.0f);
 glVertex3f( 1.0f, -5.0f, 1.0f);

 glVertex3f( 1.0f, 1.0f, 0.0f);
 glVertex3f( 1.0f, 1.0f, 1.0f);
 glVertex3f( 1.0f, -5.0f, 1.0f);
 glVertex3f( 1.0f, -5.0f, 0.0f);

 glVertex3f( 2.0f, 1.0f, 0.0f);
 glVertex3f( 2.0f, 1.0f, 1.0f);
 glVertex3f( 2.0f, -5.0f, 1.0f);
 glVertex3f( 2.0f, -5.0f, 0.0f);

 glColor3f(0.0f, 0.0f, 1.0f);
 glVertex3f( 1.0f, -5.0f, 0.0f);
 glVertex3f( 1.0f, -5.0f, 1.0f);
 glVertex3f( 2.0f, -5.0f, 1.0f);
 glVertex3f( 2.0f, -5.0f, 0.0f);

 glColor3f(1.0f, 1.0f, 1.0f);
 glVertex3f( 2.0f, -3.0f, 0.0f);
 glVertex3f( 3.0f, -2.0f, 0.0f);
 glVertex3f( 4.0f, -2.0f, 0.0f);
 glVertex3f( 2.0f, -4.0f, 0.0f);

 glVertex3f( 2.0f, -3.0f, 0.0f);
 glVertex3f( 4.0f, -5.0f, 0.0f);
 glVertex3f( 3.0f, -5.0f, 0.0f);
 glVertex3f( 2.0f, -4.0f, 0.0f);

 glVertex3f( 2.0f, -3.0f, 1.0f);
 glVertex3f( 3.0f, -2.0f, 1.0f);
 glVertex3f( 4.0f, -2.0f, 1.0f);
 glVertex3f( 2.0f, -4.0f, 1.0f);

 glVertex3f( 2.0f, -3.0f, 1.0f);
 glVertex3f( 4.0f, -5.0f, 1.0f);
 glVertex3f( 3.0f, -5.0f, 1.0f);
 glVertex3f( 2.0f, -4.0f, 1.0f);

 glVertex3f( 2.0f, -3.0f, 0.0f);
 glVertex3f( 2.0f, -3.0f, 1.0f);
 glVertex3f( 3.0f, -2.0f, 1.0f);
 glVertex3f( 3.0f, -2.0f, 0.0f);

 glVertex3f( 3.0f, -2.0f, 0.0f);
 glVertex3f( 3.0f, -2.0f, 1.0f);
 glVertex3f( 4.0f, -2.0f, 1.0f);
 glVertex3f( 4.0f, -2.0f, 0.0f);

 glVertex3f( 4.0f, -2.0f, 0.0f);
 glVertex3f( 4.0f, -2.0f, 1.0f);
 glVertex3f( 2.0f, -4.0f, 1.0f);
 glVertex3f( 2.0f, -4.0f, 0.0f);

 glVertex3f( 2.0f, -3.0f, 0.0f);
 glVertex3f( 2.0f, -3.0f, 1.0f );
 glVertex3f( 4.0f, -5.0f, 1.0f);
 glVertex3f( 4.0f, -5.0f, 0.0f);

 glColor3f(0.0f, 0.0f, 1.0f);
 glVertex3f( 4.0f, -5.0f, 0.0f);
 glVertex3f( 4.0f, -5.0f, 1.0f);
 glVertex3f( 3.0f, -5.0f, 1.0f);
 glVertex3f( 3.0f, -5.0f, 0.0f);

 glColor3f(1.0f, 1.0f, 1.0f);
 glVertex3f( 3.0f, -5.0f, 0.0f);
 glVertex3f( 3.0f, -5.0f, 1.0f);
 glVertex3f( 2.0f, -4.0f, 1.0f);
 glVertex3f( 2.0f, -4.0f, 0.0f);

 }




 {// i

 glVertex3f( 4.5f, -2.0f, 0.0f);
 glVertex3f( 4.5f, -5.0f, 0.0f);
 glVertex3f( 5.0f, -5.0f, 0.0f);
 glVertex3f( 5.0f, -2.0f, 0.0f);

 glVertex3f( 4.5f, -2.0f, 1.0f);
 glVertex3f( 4.5f, -5.0f, 1.0f);
 glVertex3f( 5.0f, -5.0f, 1.0f);
 glVertex3f( 5.0f, -2.0f, 1.0f);

 glVertex3f( 4.5f, -2.0f, 0.0f);
 glVertex3f( 4.5f, -2.0f, 1.0f);
 glVertex3f( 4.5f, -5.0f, 1.0f);
 glVertex3f( 4.5f, -5.0f, 0.0f);

 glColor3f(0.0f, 0.0f, 1.0f);
 glVertex3f( 4.5f, -5.0f, 0.0f);
 glVertex3f( 4.5f, -5.0f, 1.0f);
 glVertex3f( 5.0f, -5.0f, 1.0f);
 glVertex3f( 5.0f, -5.0f, 0.0f);

 glColor3f(1.0f, 1.0f, 1.0f);
 glVertex3f( 5.0f, -5.0f, 0.0f);
 glVertex3f( 5.0f, -5.0f, 1.0f);
 glVertex3f( 5.0f, -2.0f, 1.0f);
 glVertex3f( 5.0f, -2.0f, 0.0f);

 glVertex3f( 5.0f, -2.0f, 0.0f);
 glVertex3f( 5.0f, -2.0f, 1.0f);
 glVertex3f( 4.5f, -2.0f, 1.0f);
 glVertex3f( 4.5f, -2.0f, 0.0f);
 }

 }


//2
glColor3f(0.0f, 1.0f, 0.0f); // Green
 {
 glVertex3f( -9.0f, 0.0f, 5.0f);
 glVertex3f( -10.0f, 0.0f, 4.0f);
 glVertex3f( -9.0f, 0.0f, 4.0f);
 glVertex3f( -8.0f, 0.0f, 4.5f);

 glVertex3f( -8.0f, 0.0f, 5.5f);
 glVertex3f( -9.0f, 0.0f, 5.0f);
 glVertex3f( -8.0f, 0.0f, 4.5f);
 glVertex3f( -7.0f, 0.0f, 4.5f);

 glVertex3f( -7.0f, 0.0f, 5.5f);
 glVertex3f( -8.0f, 0.0f, 5.5f);
 glVertex3f( -7.0f, 0.0f, 4.5f);
 glVertex3f( -6.0f, 0.0f, 4.0f);

 glVertex3f( -6.0f, 0.0f, 5.0f);
 glVertex3f( -7.0f, 0.0f, 5.5f);
 glVertex3f( -6.0f, 0.0f, 4.0f);
 glVertex3f( -5.0f, 0.0f, 4.0f);

 glVertex3f( -5.0f, 0.0f, 4.0f);
 glVertex3f( -6.0f, 0.0f, 4.5f);
 glVertex3f( -6.0f, 0.0f, 3.0f);
 glVertex3f( -5.0f, 0.0f, 2.5f);

 glVertex3f( -5.0f, 0.0f, 2.5f);
 glVertex3f( -6.0f, 0.0f, 3.0f);
 glVertex3f( -10.0f, 0.0f, 1.0f);
 glVertex3f( -8.0f, 0.0f, 1.0f);

 glVertex3f( -5.0f, 0.0f, 1.0f);
 glVertex3f( -10.0f, 0.0f, 1.0f);
 glVertex3f( -10.0f, 0.0f, 0.0f);
 glVertex3f( -5.0f, 0.0f, 0.0f);
}


// Bottom face (y = -1.0f)
 glColor3f(0.0f, 0.0f, 1.0f); // Blue
 {
 glVertex3f( -9.0f, -1.0f, 5.0f);
 glVertex3f( -10.0f, -1.0f, 4.0f);
 glVertex3f( -9.0f, -1.0f, 4.0f);
 glVertex3f( -8.0f, -1.0f, 4.5f);

 glVertex3f( -8.0f, -1.0f, 5.5f);
 glVertex3f( -9.0f, -1.0f, 5.0f);
 glVertex3f( -8.0f, -1.0f, 4.5f);
 glVertex3f( -7.0f, -1.0f, 4.5f);

 glVertex3f( -7.0f, -1.0f, 5.5f);
 glVertex3f( -8.0f, -1.0f, 5.5f);
 glVertex3f( -7.0f, -1.0f, 4.5f);
 glVertex3f( -6.0f, -1.0f, 4.0f);

 glVertex3f( -6.0f, -1.0f, 5.0f);
 glVertex3f( -7.0f, -1.0f, 5.5f);
 glVertex3f( -6.0f, -1.0f, 4.0f);
 glVertex3f( -5.0f, -1.0f, 4.0f);

 glVertex3f( -5.0f, -1.0f, 4.0f);
 glVertex3f( -6.0f, -1.0f, 4.5f);
 glVertex3f( -6.0f, -1.0f, 3.0f);
 glVertex3f( -5.0f, -1.0f, 2.5f);

 glVertex3f( -5.0f, -1.0f, 2.5f);
 glVertex3f( -6.0f, -1.0f, 3.0f);
 glVertex3f( -10.0f, -1.0f, 1.0f);
 glVertex3f( -8.0f, -1.0f, 1.0f);

 glVertex3f( -5.0f, -1.0f, 1.0f);
 glVertex3f( -10.0f, -1.0f, 1.0f);
 glVertex3f( -10.0f, -1.0f, 0.0f);
 glVertex3f( -5.0f, -1.0f, 0.0f);
}


glColor3f(1.0f, 1.0f, 1.0f); // White
 {
 glVertex3f( -10.0f, 0.0f, 0.0f);
 glVertex3f( -10.0f, -1.0f, 0.0f);
 glVertex3f( -5.0f, -1.0f, 0.0f);
 glVertex3f( -5.0f, 0.0f, 0.0f);

 glVertex3f( -5.0f, 0.0f, 0.0f);
 glVertex3f( -5.0f, -1.0f, 0.0f);
 glVertex3f( -5.0f, -1.0f, 1.0f);
 glVertex3f( -5.0f, 0.0f, 1.0f);

 glVertex3f( -5.0f, 0.0f, 1.0f);
 glVertex3f( -5.0f, -1.0f, 1.0f);
 glVertex3f( -8.0f, -1.0f, 1.0f);
 glVertex3f( -8.0f, 0.0f, 1.0f);

 glVertex3f( -8.0f, 0.0f, 1.0f);
 glVertex3f( -8.0f, -1.0f, 1.0f);
 glVertex3f( -5.0f, -1.0f, 2.5f);
 glVertex3f( -5.0f, 0.0f, 2.5f);

 glVertex3f( -5.0f, 0.0f, 2.5f);
 glVertex3f( -5.0f, -1.0f, 2.5f);
 glVertex3f( -5.0f, -1.0f, 4.0f);
 glVertex3f( -5.0f, 0.0f, 4.0f);

 glVertex3f( -5.0f, 0.0f, 4.0f);
 glVertex3f( -5.0f, -1.0f, 4.0f);
 glVertex3f( -6.0f, -1.0f, 5.0f);
 glVertex3f( -6.0f, 0.0f, 5.0f);

 glVertex3f( -6.0f, 0.0f, 5.0f);
 glVertex3f( -6.0f, -1.0f, 5.0f);
 glVertex3f( -7.0f, -1.0f, 5.5f);
 glVertex3f( -7.0f, 0.0f, 5.5f);

 glVertex3f( -7.0f, 0.0f, 5.5f);
 glVertex3f( -7.0f, -1.0f, 5.5f);
 glVertex3f( -8.0f, -1.0f, 5.5f);
 glVertex3f( -8.0f, 0.0f, 5.5f);

 glVertex3f( -8.0f, 0.0f, 5.5f);
 glVertex3f( -8.0f, -1.0f, 5.5f);
 glVertex3f( -9.0f, -1.0f, 5.0f);
 glVertex3f( -9.0f, 0.0f, 5.0f);

 glVertex3f( -9.0f, 0.0f, 5.0f);
 glVertex3f( -9.0f, -1.0f, 5.0f);
 glVertex3f( -10.0f, -1.0f, 4.0f);
 glVertex3f( -10.0f, 0.0f, 4.0f);

 glVertex3f( -10.0f, 0.0f, 4.0f);
 glVertex3f( -10.0f, -1.0f, 4.0f);
 glVertex3f( -9.0f, -1.0f, 4.0f);
 glVertex3f( -9.0f, 0.0f, 4.0f);

 glVertex3f( -9.0f, 0.0f, 4.0f);
 glVertex3f( -9.0f, -1.0f, 4.0f);
 glVertex3f( -8.0f, -1.0f, 4.5f);
 glVertex3f( -8.0f, 0.0f, 4.5f);

 glVertex3f( -8.0f, 0.0f, 4.5f);
 glVertex3f( -8.0f, -1.0f, 4.5f);
 glVertex3f( -7.0f, -1.0f, 4.5f);
 glVertex3f( -7.0f, 0.0f, 4.5f);

 glVertex3f( -7.0f, 0.0f, 4.5f);
 glVertex3f( -7.0f, -1.0f, 4.5f);
 glVertex3f( -6.0f, -1.0f, 4.0f);
 glVertex3f( -6.0f, 0.0f, 4.0f);

 glVertex3f( -6.0f, 0.0f, 4.0f);
 glVertex3f( -6.0f, -1.0f, 4.0f);
 glVertex3f( -6.0f, -1.0f, 3.0f);
 glVertex3f( -6.0f, 0.0f, 3.0f);

 glVertex3f( -6.0f, 0.0f, 3.0f);
 glVertex3f( -6.0f, -1.0f, 3.0f);
 glVertex3f( -10.0f, -1.0f, 1.0f);
 glVertex3f( -10.0f, 0.0f, 1.0f);

 glVertex3f( -10.0f, 0.0f, 1.0f);
 glVertex3f( -10.0f, -1.0f, 1.0f);
 glVertex3f( -10.0f, -1.0f, 0.0f);
 glVertex3f( -10.0f, 0.0f, 0.0f);



 {// T

 glVertex3f( -9.0f, 0.0f, 0.0f);
 glVertex3f( -8.0f, 0.0f, 0.0f);
 glVertex3f( -8.0f, -5.0f, 0.0f);
 glVertex3f( -9.0f, -5.0f, 0.0f);

 glVertex3f( -9.0f, 0.0f, 1.0f);
 glVertex3f( -8.0f, 0.0f, 1.0f);
 glVertex3f( -8.0f, -5.0f, 1.0f);
 glVertex3f( -9.0f, -5.0f, 1.0f);

 glVertex3f( -9.0f, 0.0f, 0.0f);
 glVertex3f( -9.0f, 0.0f, 1.0f);
 glVertex3f( -9.0f, -5.0f, 1.0f);
 glVertex3f( -9.0f, -5.0f, 0.0f);

 glVertex3f( -8.0f, 0.0f, 0.0f);
 glVertex3f( -8.0f, 0.0f, 1.0f);
 glVertex3f( -8.0f, -5.0f, 1.0f);
 glVertex3f( -8.0f, -5.0f, 0.0f);

 glColor3f(0.0f, 0.0f, 1.0f);
 glVertex3f( -9.0f, -5.0f, 0.0f);
 glVertex3f( -9.0f, -5.0f, 1.0f);
 glVertex3f( -8.0f, -5.0f, 1.0f);
 glVertex3f( -8.0f, -5.0f, 0.0f);
 }

 }


//0
 glColor3f(0.0f, 1.0f, 0.0f); // Green
 {
 glVertex3f( 6.0f, 0.0f, 1.0f);
 glVertex3f( 6.0f, 0.0f, 0.0f);
 glVertex3f( 9.0f, 0.0f, 0.0f);
 glVertex3f( 9.0f, 0.0f, 1.0f);

 glVertex3f( 8.0f, 0.0f, 1.0f);
 glVertex3f( 9.0f, 0.0f, 1.0f);
 glVertex3f( 9.0f, 0.0f, 3.0f);
 glVertex3f( 8.0f, 0.0f, 3.0f);

 glVertex3f( 9.0f, 0.0f, 3.0f);
 glVertex3f( 9.0f, 0.0f, 4.0f);
 glVertex3f( 6.0f, 0.0f, 4.0f);
 glVertex3f( 6.0f, 0.0f, 3.0f);

 glVertex3f( 6.0f, 0.0f, 3.0f);
 glVertex3f( 7.0f, 0.0f, 3.0f);
 glVertex3f( 7.0f, 0.0f, 1.0f);
 glVertex3f( 6.0f, 0.0f, 1.0f);

}


glColor3f(0.0f, 0.0f, 1.0f); // White
 {
 glVertex3f( 6.0f, -1.0f, 1.0f);
 glVertex3f( 6.0f, -1.0f, 0.0f);
 glVertex3f( 9.0f, -1.0f, 0.0f);
 glVertex3f( 9.0f, -1.0f, 1.0f);

 glVertex3f( 8.0f, -1.0f, 1.0f);
 glVertex3f( 9.0f, -1.0f, 1.0f);
 glVertex3f( 9.0f, -1.0f, 3.0f);
 glVertex3f( 8.0f, -1.0f, 3.0f);

 glVertex3f( 9.0f, -1.0f, 3.0f);
 glVertex3f( 9.0f, -1.0f, 4.0f);
 glVertex3f( 6.0f, -1.0f, 4.0f);
 glVertex3f( 6.0f, -1.0f, 3.0f);

 glVertex3f( 6.0f, -1.0f, 3.0f);
 glVertex3f( 7.0f, -1.0f, 3.0f);
 glVertex3f( 7.0f, -1.0f, 1.0f);
 glVertex3f( 6.0f, -1.0f, 1.0f);

}

glColor3f(1.0f, 1.0f, 1.0f); // White
{
 glVertex3f( 6.0f, 0.0f, 0.0f);
 glVertex3f( 6.0f, -1.0f, 0.0f);
 glVertex3f( 9.0f, -1.0f, 0.0f);
 glVertex3f( 9.0f, 0.0f, 0.0f);

 glVertex3f( 9.0f, 0.0f, 0.0f);
 glVertex3f( 9.0f, -1.0f, 0.0f);
 glVertex3f( 9.0f, -1.0f, 4.0f);
 glVertex3f( 9.0f, 0.0f, 4.0f);

 glVertex3f( 9.0f, 0.0f, 4.0f);
 glVertex3f( 9.0f, -1.0f, 4.0f);
 glVertex3f( 6.0f, -1.0f, 4.0f);
 glVertex3f( 6.0f, 0.0f, 4.0f);

 glVertex3f( 6.0f, 0.0f, 4.0f);
 glVertex3f( 6.0f, -1.0f, 4.0f);
 glVertex3f( 6.0f, -1.0f, 0.0f);
 glVertex3f( 6.0f, 0.0f, 0.0f);

 glVertex3f( 7.0f, 0.0f, 1.0f);
 glVertex3f( 7.0f, -1.0f, 1.0f);
 glVertex3f( 7.0f, -1.0f, 3.0f);
 glVertex3f( 7.0f, 0.0f, 3.0f);

 glVertex3f( 7.0f, 0.0f, 3.0f);
 glVertex3f(  7.0f, -1.0f, 3.0f);
 glVertex3f( 8.0f, -1.0f, 3.0f);
 glVertex3f( 8.0f, 0.0f, 3.0f);

 glVertex3f( 8.0f, 0.0f, 3.0f);
 glVertex3f( 8.0f, -1.0f, 3.0f);
 glVertex3f( 8.0f, -1.0f, 1.0f);
 glVertex3f( 8.0f, 0.0f, 1.0f);

 glVertex3f( 8.0f, 0.0f, 1.0f);
 glVertex3f( 8.0f, -1.0f, 1.0f);
 glVertex3f( 7.0f, -1.0f, 1.0f);
 glVertex3f( 7.0f, 0.0f, 1.0f);
{// o

 glVertex3f( 6.0f, 0.0f, 0.0f);
 glVertex3f( 6.0f, -5.0f, 0.0f);
 glVertex3f( 7.0f, -5.0f, 0.0f);
 glVertex3f( 7.0f, 0.0f, 0.0f);

 glVertex3f( 6.0f, -4.0f, 0.0f);
 glVertex3f( 6.0f, -5.0f, 0.0f);
 glVertex3f( 9.0f, -5.0f, 0.0f);
 glVertex3f( 9.0f, -4.0f, 0.0f);

 glVertex3f( 9.0f, -5.0f, 0.0f);
 glVertex3f( 8.0f, -5.0f, 0.0f);
 glVertex3f( 8.0f, 0.0f, 0.0f);
 glVertex3f( 9.0f, 0.0f, 0.0f);

 glVertex3f( 6.0f, 0.0f, 1.0f);
 glVertex3f( 6.0f, -5.0f, 1.0f);
 glVertex3f( 7.0f, -5.0f, 1.0f);
 glVertex3f( 7.0f, 0.0f, 1.0f);

 glVertex3f( 6.0f, -4.0f, 1.0f);
 glVertex3f( 6.0f, -5.0f, 1.0f);
 glVertex3f( 9.0f, -5.0f, 1.0f);
 glVertex3f( 9.0f, -4.0f, 1.0f);

 glVertex3f( 9.0f, -5.0f, 1.0f);
 glVertex3f( 8.0f, -5.0f, 1.0f);
 glVertex3f( 8.0f, 0.0f, 1.0f);
 glVertex3f( 9.0f, 0.0f, 1.0f);

 glVertex3f( 6.0f, 0.0f, 0.0f);
 glVertex3f( 6.0f, 0.0f, 1.0f);
 glVertex3f( 6.0f, -5.0f, 1.0f);
 glVertex3f( 6.0f, -5.0f, 0.0f);

 glColor3f(0.0f, 0.0f, 1.0f);
 glVertex3f( 6.0f, -5.0f, 0.0f);
 glVertex3f( 6.0f, -5.0f, 1.0f);
 glVertex3f( 9.0f, -5.0f, 1.0f);
 glVertex3f( 9.0f, -5.0f, 0.0f);

 glColor3f(1.0f, 1.0f, 1.0f);
 glVertex3f( 9.0f, -5.0f, 0.0f);
 glVertex3f( 9.0f, -5.0f, 1.0f);
 glVertex3f( 9.0f, 0.0f, 1.0f);
 glVertex3f( 9.0f, 0.0f, 0.0f);

 glVertex3f( 7.0f, -1.0f, 0.0f);
 glVertex3f( 7.0f, -1.0f, 1.0f);
 glVertex3f( 7.0f, -4.0f, 1.0f);
 glVertex3f( 7.0f, -4.0f, 0.0f);

 glVertex3f( 7.0f, -4.0f, 0.0f);
 glVertex3f( 7.0f, -4.0f, 1.0f);
 glVertex3f( 8.0f, -4.0f, 1.0f);
 glVertex3f( 8.0f, -4.0f, 0.0f);

 glVertex3f( 8.0f, -4.0f, 0.0f);
 glVertex3f( 8.0f, -4.0f, 1.0f);
 glVertex3f( 8.0f, -1.0f, 1.0f);
 glVertex3f( 8.0f, -1.0f, 0.0f);
}

}

//0

glColor3f(0.0f, 1.0f, 0.0f); // Green
 {
 glVertex3f( -4.0f, 0.0f, 1.0f);
 glVertex3f( -4.0f, 0.0f, 0.0f);
 glVertex3f( -1.0f, 0.0f, 0.0f);
 glVertex3f( -1.0f, 0.0f, 1.0f);

 glVertex3f( -2.0f, 0.0f, 1.0f);
 glVertex3f( -1.0f, 0.0f, 1.0f);
 glVertex3f( -1.0f, 0.0f, 3.0f);
 glVertex3f( -2.0f, 0.0f, 3.0f);

 glVertex3f( -1.0f, 0.0f, 3.0f);
 glVertex3f( -1.0f, 0.0f, 4.0f);
 glVertex3f( -4.0f, 0.0f, 4.0f);
 glVertex3f( -4.0f, 0.0f, 3.0f);

 glVertex3f( -4.0f, 0.0f, 3.0f);
 glVertex3f( -3.0f, 0.0f, 3.0f);
 glVertex3f( -3.0f, 0.0f, 1.0f);
 glVertex3f( -4.0f, 0.0f, 1.0f);

}


glColor3f(0.0f, 0.0f, 1.0f); // White
 {
 glVertex3f( -4.0f, -1.0f, 1.0f);
 glVertex3f( -4.0f, -1.0f, 0.0f);
 glVertex3f( -1.0f, -1.0f, 0.0f);
 glVertex3f( -1.0f, -1.0f, 1.0f);

 glVertex3f( -2.0f, -1.0f, 1.0f);
 glVertex3f( -1.0f, -1.0f, 1.0f);
 glVertex3f( -1.0f, -1.0f, 3.0f);
 glVertex3f( -2.0f, -1.0f, 3.0f);

 glVertex3f( -1.0f, -1.0f, 3.0f);
 glVertex3f( -1.0f, -1.0f, 4.0f);
 glVertex3f( -4.0f, -1.0f, 4.0f);
 glVertex3f( -4.0f, -1.0f, 3.0f);

 glVertex3f( -4.0f, -1.0f, 3.0f);
 glVertex3f( -3.0f, -1.0f, 3.0f);
 glVertex3f( -3.0f, -1.0f, 1.0f);
 glVertex3f( -4.0f, -1.0f, 1.0f);

}

glColor3f(1.0f, 1.0f, 1.0f); // White
{
 glVertex3f( -4.0f, 0.0f, 0.0f);
 glVertex3f( -4.0f, -1.0f, 0.0f);
 glVertex3f( -1.0f, -1.0f, 0.0f);
 glVertex3f( -1.0f, 0.0f, 0.0f);

 glVertex3f( -1.0f, 0.0f, 0.0f);
 glVertex3f( -1.0f, -1.0f, 0.0f);
 glVertex3f( -1.0f, -1.0f, 4.0f);
 glVertex3f( -1.0f, 0.0f, 4.0f);

 glVertex3f( -1.0f, 0.0f, 4.0f);
 glVertex3f( -1.0f, -1.0f, 4.0f);
 glVertex3f( -4.0f, -1.0f, 4.0f);
 glVertex3f( -4.0f, 0.0f, 4.0f);

 glVertex3f( -4.0f, 0.0f, 4.0f);
 glVertex3f( -4.0f, -1.0f, 4.0f);
 glVertex3f( -4.0f, -1.0f, 0.0f);
 glVertex3f( -4.0f, 0.0f, 0.0f);

 glVertex3f( -4.0f, 0.0f, 0.0f);
 glVertex3f( -4.0f, -3.0f, 0.0f);
 glVertex3f( -3.0f, -3.0f, 0.0f);
 glVertex3f( -3.0f, 0.0f, 0.0f);

 glVertex3f( -3.0f, 0.0f, 1.0f);
 glVertex3f( -3.0f, -1.0f, 1.0f);
 glVertex3f( -3.0f, -1.0f, 3.0f);
 glVertex3f( -3.0f, 0.0f, 3.0f);

 glVertex3f( -3.0f, 0.0f, 3.0f);
 glVertex3f( -3.0f, -1.0f, 3.0f);
 glVertex3f( -2.0f, -1.0f, 3.0f);
 glVertex3f( -2.0f, 0.0f, 3.0f);

 glVertex3f( -2.0f, 0.0f, 3.0f);
 glVertex3f( -2.0f, -1.0f, 3.0f);
 glVertex3f( -2.0f, -1.0f, 1.0f);
 glVertex3f( -2.0f, 0.0f, 1.0f);

 glVertex3f( -2.0f, 0.0f, 1.0f);
 glVertex3f( -2.0f, -1.0f, 1.0f);
 glVertex3f( -3.0f, -1.0f, 1.0f);
 glVertex3f( -3.0f, 0.0f, 1.0f);

{// o
 glVertex3f( -4.0f, 0.0f, 0.0f);
 glVertex3f( -4.0f, -5.0f, 0.0f);
 glVertex3f( -3.0f, -5.0f, 0.0f);
 glVertex3f( -3.0f, 0.0f, 0.0f);

 glVertex3f( -4.0f, -4.0f, 0.0f);
 glVertex3f( -4.0f, -5.0f, 0.0f);
 glVertex3f( -1.0f, -5.0f, 0.0f);
 glVertex3f( -1.0f, -4.0f, 0.0f);

 glVertex3f( -1.0f, -5.0f, 0.0f);
 glVertex3f( -2.0f, -5.0f, 0.0f);
 glVertex3f( -2.0f, 0.0f, 0.0f);
 glVertex3f( -1.0f, 0.0f, 0.0f);

 glVertex3f( -4.0f, 0.0f, 1.0f);
 glVertex3f( -4.0f, -5.0f, 1.0f);
 glVertex3f( -3.0f, -5.0f, 1.0f);
 glVertex3f( -3.0f, 0.0f, 1.0f);

 glVertex3f( -4.0f, -4.0f, 1.0f);
 glVertex3f( -4.0f, -5.0f, 1.0f);
 glVertex3f( -1.0f, -5.0f, 1.0f);
 glVertex3f( -1.0f, -4.0f, 1.0f);

 glVertex3f( -1.0f, -5.0f, 1.0f);
 glVertex3f( -2.0f, -5.0f, 1.0f);
 glVertex3f( -2.0f, 0.0f, 1.0f);
 glVertex3f( -1.0f, 0.0f, 1.0f);

 glVertex3f( -4.0f, 0.0f, 0.0f);
 glVertex3f( -4.0f, 0.0f, 1.0f);
 glVertex3f( -4.0f, -5.0f, 1.0f);
 glVertex3f( -4.0f, -5.0f, 0.0f);

 glColor3f(0.0f, 0.0f, 1.0f);
 glVertex3f( -4.0f, -5.0f, 0.0f);
 glVertex3f( -4.0f, -5.0f, 1.0f);
 glVertex3f( -1.0f, -5.0f, 1.0f);
 glVertex3f( -1.0f, -5.0f, 0.0f);

 glColor3f(1.0f, 1.0f, 1.0f);
 glVertex3f( -1.0f, -5.0f, 0.0f);
 glVertex3f( -1.0f, -5.0f, 1.0f);
 glVertex3f( -1.0f, 0.0f, 1.0f);
 glVertex3f( -1.0f, 0.0f, 0.0f);

 glVertex3f( -3.0f, -1.0f, 0.0f);
 glVertex3f( -3.0f, -1.0f, 1.0f);
 glVertex3f( -3.0f, -4.0f, 1.0f);
 glVertex3f( -3.0f, -4.0f, 0.0f);

 glVertex3f( -3.0f, -4.0f, 0.0f);
 glVertex3f( -3.0f, -4.0f, 1.0f);
 glVertex3f( -2.0f, -4.0f, 1.0f);
 glVertex3f( -2.0f, -4.0f, 0.0f);

 glVertex3f( -2.0f, -4.0f, 0.0f);
 glVertex3f( -2.0f, -4.0f, 1.0f);
 glVertex3f( -2.0f, -1.0f, 1.0f);
 glVertex3f( -2.0f, -1.0f, 0.0f);
}

}

 glEnd(); // End of drawing color-cube
 glutSwapBuffers(); // Swap the front and back frame buffers (double buffering)
 // Update the rotational angle after each refresh [NEW]



 if(k==0)
    if (angleCube > -1.0f) angleCube -= 0.01f;
        else if (angleCube > -90.0f)
            angleCube -= 0.15f;
                else {k=1;}
else
    if (angleCube < -89.0f) angleCube += 0.01f;
        else if (angleCube < 0.0f)
                angleCube += 0.15f;
                else {k=0; }
}
/* Called back when timer expired [NEW] */
void timer(int value) {
 glutPostRedisplay(); // Post re-paint request to activate display()
 glutTimerFunc(refreshMills, timer, 0); // next timer call milliseconds later
}
/* Handler for window re-size event. Called back when the window first appears
and
 whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) { // GLsizei for non-negative integer
 // Compute aspect ratio of the new window
 if (height == 0) height = 1; // To prevent divide by 0
 GLfloat aspect = (GLfloat)width / (GLfloat)height;
 // Set the viewport to cover the new window
 glViewport(0, 0, width, height);
 // Set the aspect ratio of the clipping volume to match the viewport
 glMatrixMode(GL_PROJECTION); // To operate on the Projection matrix
 glLoadIdentity(); // Reset
 // Enable perspective projection with fovy, aspect, zNear and zFar
 gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

int main(int argc, char** argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DOUBLE);
 glutInitWindowSize(1280, 480); // Set the window's initial width & height
 glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
 glutCreateWindow(title);
 glutDisplayFunc(display); // Register callback handler for window repaint event
 glutReshapeFunc(reshape); // Register callback handler for window resize event
 initGL(); // Our own OpenGL initialization
 glutTimerFunc(0, timer, 0); // First timer call immediately
 glutMainLoop();
 return 0;
}
