// #include <GL/glut.h>

// // Window dimensions
// const int WIDTH = 800;
// const int HEIGHT = 600;

// // Translation factors
// float tx = 300.0f; // Translation along the x-axis
// float ty = 200.0f;  // Translation along the y-axis

// void init() {
//     glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     gluOrtho2D(0, WIDTH, 0, HEIGHT);
// }

// void drawPixel(int x, int y) {
//     glBegin(GL_POINTS);
//     glVertex2i(x, y);
//     glEnd();
// }

// void drawAxes() {
//     glColor3f(0.0, 0.0, 0.0); // Set line color to black

//     // Draw x-axis
//     glBegin(GL_LINES);
//     glVertex2i(0, HEIGHT / 2);
//     glVertex2i(WIDTH, HEIGHT / 2);
//     glEnd();

//     // Draw y-axis
//     glBegin(GL_LINES);
//     glVertex2i(WIDTH / 2, 0);
//     glVertex2i(WIDTH / 2, HEIGHT);
//     glEnd();
// }

// void display() {
//     glClear(GL_COLOR_BUFFER_BIT);

//     // Draw axes
//     drawAxes();

//     // Draw original square (before translation)
//     glColor3f(1.0, 0.0, 0.0); // Red color
//     glBegin(GL_QUADS);
//     glVertex2f(200.0f, 200.0f);
//     glVertex2f(300.0f, 200.0f);
//     glVertex2f(300.0f, 300.0f);
//     glVertex2f(200.0f, 300.0f);
//     glEnd();

//     // Apply translation using homogeneous coordinates
//     glPushMatrix();
//     glTranslatef(tx, ty, 0.0f);

//     // Draw translated square
//     glColor3f(0.0, 0.0, 1.0); // Blue color
//     glBegin(GL_QUADS);
//     glVertex2f(200.0f, 200.0f);
//     glVertex2f(300.0f, 200.0f);
//     glVertex2f(300.0f, 300.0f);
//     glVertex2f(200.0f, 300.0f);
//     glEnd();

//     glPopMatrix();

//     glFlush();
// }

// int main(int argc, char **argv) {
//     glutInit(&argc, argv);
//     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//     glutInitWindowSize(WIDTH, HEIGHT);
//     glutCreateWindow("2D Translation Using Homogeneous Coordinates with Axes");
//     init();
//     glutDisplayFunc(display);
//     glutMainLoop();

//     return 0;
// }


// //2D-Rotation

// #include <GL/glut.h>
// #include <cmath>

// // Window dimensions
// const int WIDTH = 800;
// const int HEIGHT = 600;

// // Rotation angle in degrees
// float angle = -60.0f; // Change this value to rotate by a different angle

// // Pivot point for rotation
// float pivotX = WIDTH / 2;
// float pivotY = HEIGHT / 2;

// void init() {
//     glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     gluOrtho2D(0, WIDTH, 0, HEIGHT);
// }

// void drawPixel(int x, int y) {
//     glBegin(GL_POINTS);
//     glVertex2i(x, y);
//     glEnd();
// }

// void drawAxes() {
//     glColor3f(0.0, 0.0, 0.0); // Set line color to black

//     // Draw x-axis
//     glBegin(GL_LINES);
//     glVertex2i(0, HEIGHT / 2);
//     glVertex2i(WIDTH, HEIGHT / 2);
//     glEnd();

//     // Draw y-axis
//     glBegin(GL_LINES);
//     glVertex2i(WIDTH / 2, 0);
//     glVertex2i(WIDTH / 2, HEIGHT);
//     glEnd();
// }

// void display() {
//     glClear(GL_COLOR_BUFFER_BIT);

//     // Draw axes
//     drawAxes();

//     // Draw original square (before rotation)
//     glColor3f(1.0, 0.0, 0.0); // Red color
//     glBegin(GL_QUADS);
//     glVertex2f(300.0f, 300.0f);
//     glVertex2f(400.0f, 300.0f);
//     glVertex2f(400.0f, 400.0f);
//     glVertex2f(300.0f, 400.0f);
//     glEnd();

//     // Apply rotation using homogeneous coordinates
//     glPushMatrix();

//     // Translate to pivot point, rotate, then translate back
//     glTranslatef(pivotX, pivotY, 0.0f);
//     glRotatef(angle, 0.0f, 0.0f, 1.0f);
//     glTranslatef(-pivotX, -pivotY, 0.0f);

//     // Draw rotated square
//     glColor3f(0.0, 0.0, 1.0); // Blue color
//     glBegin(GL_QUADS);
//     glVertex2f(300.0f, 300.0f);
//     glVertex2f(400.0f, 300.0f);
//     glVertex2f(400.0f, 400.0f);
//     glVertex2f(300.0f, 400.0f);
//     glEnd();

//     glPopMatrix();

//     glFlush();
// }

// int main(int argc, char **argv) {
//     glutInit(&argc, argv);
//     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//     glutInitWindowSize(WIDTH, HEIGHT);
//     glutCreateWindow("2D Rotation Using Homogeneous Coordinates with Axes");
//     init();
//     glutDisplayFunc(display);
//     glutMainLoop();

//     return 0;
// }



// //2D Scaling


// #include <GL/glut.h>

// // Window dimensions
// const int WIDTH = 800;
// const int HEIGHT = 600;

// // Scaling factors
// float sx = 1.5f; // Scale factor along the x-axis
// float sy = 1.5f; // Scale factor along the y-axis

// void init() {
//     glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     gluOrtho2D(0, WIDTH, 0, HEIGHT);
// }

// void drawAxes() {
//     glColor3f(0.0, 0.0, 0.0); // Set line color to black

//     // Draw x-axis
//     glBegin(GL_LINES);
//     glVertex2i(0, HEIGHT / 2);
//     glVertex2i(WIDTH, HEIGHT / 2);
//     glEnd();

//     // Draw y-axis
//     glBegin(GL_LINES);
//     glVertex2i(WIDTH / 2, 0);
//     glVertex2i(WIDTH / 2, HEIGHT);
//     glEnd();
// }

// void display() {
//     glClear(GL_COLOR_BUFFER_BIT);

//     // Draw axes
//     drawAxes();

//     // Draw original square (before scaling)
//     glColor3f(1.0, 0.0, 0.0); // Red color
//     glBegin(GL_LINE_LOOP);
//     glVertex2f(300.0f, 300.0f);
//     glVertex2f(400.0f, 300.0f);
//     glVertex2f(400.0f, 400.0f);
//     glVertex2f(300.0f, 400.0f);
//     glEnd();

//     // Apply scaling using homogeneous coordinates
//     glPushMatrix();

//     // Translate to the center of the square, scale, then translate back
//     float centerX = 350.0f; // Center x of the square
//     float centerY = 350.0f; // Center y of the square

//     glTranslatef(centerX, centerY, 0.0f);
//     glScalef(sx, sy, 1.0f);
//     glTranslatef(-centerX, -centerY, 0.0f);

//     // Draw scaled square
//     glColor3f(0.0, 0.0, 1.0); // Blue color
//     glBegin(GL_LINE_LOOP);
//     glVertex2f(300.0f, 300.0f);
//     glVertex2f(400.0f, 300.0f);
//     glVertex2f(400.0f, 400.0f);
//     glVertex2f(300.0f, 400.0f);
//     glEnd();

//     glPopMatrix();

//     glFlush();
// }

// int main(int argc, char **argv) {
//     glutInit(&argc, argv);
//     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//     glutInitWindowSize(WIDTH, HEIGHT);
//     glutCreateWindow("2D Scaling Using Homogeneous Coordinates");
//     init();
//     glutDisplayFunc(display);
//     glutMainLoop();

//     return 0;
// }


//2D Reflection

#include <GL/glut.h>

// Window dimensions
const int WIDTH = 800;
const int HEIGHT = 600;

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WIDTH, 0, HEIGHT);
}

void drawAxes() {
    glColor3f(0.0, 0.0, 0.0); // Set line color to black

    // Draw x-axis
    glBegin(GL_LINES);
    glVertex2i(0, HEIGHT / 2);
    glVertex2i(WIDTH, HEIGHT / 2);
    glEnd();

    // Draw y-axis
    glBegin(GL_LINES);
    glVertex2i(WIDTH / 2, 0);
    glVertex2i(WIDTH / 2, HEIGHT);
    glEnd();
}

void drawPolygon() {
    glBegin(GL_LINE_LOOP);
    glVertex2f(300.0f, 300.0f);
    glVertex2f(400.0f, 300.0f);
    glVertex2f(400.0f, 400.0f);
    glVertex2f(300.0f, 400.0f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw axes
    drawAxes();

    // Draw original polygon (before reflection)
    glColor3f(1.0, 0.0, 0.0); // Red color
    drawPolygon();

    // Apply reflection across the x-axis
    // glPushMatrix();
    // glTranslatef(0, HEIGHT / 2, 0.0f);
    // glScalef(1.0f, -1.0f, 1.0f);
    // glTranslatef(0, -HEIGHT / 2, 0.0f);
    // glColor3f(0.0, 0.0, 1.0); // Blue color
    // drawPolygon();
    // glPopMatrix();

    // Apply reflection across the y-axis
    glPushMatrix();
    glTranslatef(WIDTH / 2, 0, 0.0f);
    glScalef(-1.0f, 1.0f, 1.0f);
    glTranslatef(-WIDTH / 2, 0, 0.0f);
    glColor3f(0.0, 1.0, 0.0); // Green color
    drawPolygon();
    glPopMatrix();


    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("2D Reflection Using Homogeneous Coordinates with Axes");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}


// //2D Shearing


// #include <GL/glut.h>

// // Window dimensions
// const int WIDTH = 800;
// const int HEIGHT = 600;

// // Shearing factors
// float shx = 0.5f; // Horizontal shearing factor
// float shy = 0.5f; // Vertical shearing factor

// void init() {
//     glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     gluOrtho2D(0, WIDTH, 0, HEIGHT);
// }

// void drawAxes() {
//     glColor3f(0.0, 0.0, 0.0); // Set line color to black

//     // Draw x-axis
//     glBegin(GL_LINES);
//     glVertex2i(0, HEIGHT / 2);
//     glVertex2i(WIDTH, HEIGHT / 2);
//     glEnd();

//     // Draw y-axis
//     glBegin(GL_LINES);
//     glVertex2i(WIDTH / 2, 0);
//     glVertex2i(WIDTH / 2, HEIGHT);
//     glEnd();
// }

// void drawPolygon() {
//     glBegin(GL_LINE_LOOP);
//     glVertex2f(300.0f, 300.0f);
//     glVertex2f(400.0f, 300.0f);
//     glVertex2f(400.0f, 400.0f);
//     glVertex2f(300.0f, 400.0f);
//     glEnd();
// }

// void display() {
//     glClear(GL_COLOR_BUFFER_BIT);

//     // Draw axes
//     drawAxes();

//     // Draw original polygon (before shearing)
//     glColor3f(1.0, 0.0, 0.0); // Red color
//     drawPolygon();

//     // Apply horizontal shearing
//     glPushMatrix();
//     glTranslatef(0, HEIGHT / 2, 0.0f);
//     glMultMatrixf(new float[16]{1.0f, shx, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f});
//     glTranslatef(0, -HEIGHT / 2, 0.0f);
//     glColor3f(0.0, 0.0, 1.0); // Blue color
//     drawPolygon();
//     glPopMatrix();

//     // Apply vertical shearing
//     glPushMatrix();
//     glTranslatef(WIDTH / 2, 0, 0.0f);
//     glMultMatrixf(new float[16]{1.0f, 0.0f, 0.0f, 0.0f, shy, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f});
//     glTranslatef(-WIDTH / 2, 0, 0.0f);
//     glColor3f(0.0, 1.0, 0.0); // Green color
//     drawPolygon();
//     glPopMatrix();

//     glFlush();
// }

// int main(int argc, char **argv) {
//     glutInit(&argc, argv);
//     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//     glutInitWindowSize(WIDTH, HEIGHT);
//     glutCreateWindow("2D Shearing Using Homogeneous Coordinates with Axes");
//     init();
//     glutDisplayFunc(display);
//     glutMainLoop();

//     return 0;
// }


//Composite Transformation (Should be able to perform atleast 3 transformations)


// #include <GL/glut.h>
// #include <cmath>

// // Window dimensions
// const int WIDTH = 800;
// const int HEIGHT = 600;

// // Rectangle parameters
// const float rectWidth = 100.0f;
// const float rectHeight = 50.0f;

// // Transformation parameters
// float tx = 200.0f; // Translation along x-axis
// float ty = 200.0f; // Translation along y-axis
// float theta = 45.0f; // Rotation angle in degrees
// float sx = 1.5f; // Scaling factor along x-axis
// float sy = 0.8f; // Scaling factor along y-axis

// void init() {
//     glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     gluOrtho2D(0, WIDTH, 0, HEIGHT);
// }

// void drawAxes() {
//     glColor3f(0.0, 0.0, 0.0); // Set line color to black

//     // Draw x-axis
//     glBegin(GL_LINES);
//     glVertex2i(0, HEIGHT / 2);
//     glVertex2i(WIDTH, HEIGHT / 2);
//     glEnd();

//     // Draw y-axis
//     glBegin(GL_LINES);
//     glVertex2i(WIDTH / 2, 0);
//     glVertex2i(WIDTH / 2, HEIGHT);
//     glEnd();
// }

// void drawRectangle() {
//     glBegin(GL_LINE_LOOP);
//     glVertex2f(-rectWidth / 2, -rectHeight / 2);
//     glVertex2f(rectWidth / 2, -rectHeight / 2);
//     glVertex2f(rectWidth / 2, rectHeight / 2);
//     glVertex2f(-rectWidth / 2, rectHeight / 2);
//     glEnd();
// }

// void display() {
//     glClear(GL_COLOR_BUFFER_BIT);

//     // Draw axes
//     drawAxes();

//     // Draw initial rectangle (before transformations)
//     glColor3f(0.5, 0.5, 0.5); // Gray color
//     glPushMatrix();
//     glTranslatef(WIDTH / 4, HEIGHT / 2, 0.0);
//     drawRectangle();
//     glPopMatrix();

//     // Apply composite transformation to draw transformed rectangle
//     glPushMatrix();

//     // Translation
//     glTranslatef(tx + WIDTH / 4, ty + HEIGHT / 2, 0.0);

//     // Rotation
//     glTranslatef(rectWidth / 2, rectHeight / 2, 0.0);
//     glRotatef(theta, 0.0, 0.0, 1.0);
//     glTranslatef(-rectWidth / 2, -rectHeight / 2, 0.0);

//     // Scaling
//     glScalef(sx, sy, 1.0);

//     // Draw transformed rectangle
//     glColor3f(0.0, 0.0, 0.0); // Black color
//     drawRectangle();

//     glPopMatrix();

//     glFlush();
// }

// int main(int argc, char **argv) {
//     glutInit(&argc, argv);
//     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//     glutInitWindowSize(WIDTH, HEIGHT);
//     glutCreateWindow("Composite Transformation on Rectangle");
//     init();
//     glutDisplayFunc(display);
//     glutMainLoop();

//     return 0;
// }

