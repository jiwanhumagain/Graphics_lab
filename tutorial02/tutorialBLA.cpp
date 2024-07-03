#include <GL/glut.h>   // Include the GLUT library for OpenGL
#include <iostream>    // Include the iostream library for input/output operations
#include <cmath>       // Include the cmath library for mathematical operations

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Set background color to black
    glMatrixMode(GL_PROJECTION);       // Set the current matrix mode to projection
    glLoadIdentity();                  // Load the identity matrix into the projection matrix
    gluOrtho2D(0, 500, 0, 500);        // Set up a 2D orthographic projection
}

void drawVertex(int x, int y) {
    glBegin(GL_POINTS);    // Begin drawing points
    glVertex2i(x, y);      // Specify a vertex at (x, y)
    glEnd();               // End drawing points
}

void bresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);   // Calculate change in x
    int dy = abs(y2 - y1);   // Calculate change in y
    int sx = (x1 < x2) ? 1 : -1; // Determine the sign of x increment
    int sy = (y1 < y2) ? 1 : -1; // Determine the sign of y increment

    int err = dx - dy;  // Initialize error term
    int x = x1;         // Start x coordinate
    int y = y1;         // Start y coordinate

    while (true) {  // Continue until the line is drawn
        drawVertex(x, y);  // Draw the current pixel

        if (x == x2 && y == y2) // If reached the end point, exit the loop
            break;

        int e2 = 2 * err; // Calculate error term for the next step

        if (e2 > -dy) { // Check if the error term for y should be incremented
            err -= dy;
            x += sx;    // Increment x coordinate
        }
        if (e2 < dx) { // Check if the error term for x should be incremented
            err += dx;
            y += sy;    // Increment y coordinate
        }
    }

    glFlush(); // Flush the OpenGL buffer
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
    glColor3f(1.0, 1.0, 1.0);     // Set line color to white

    // Example line with slope > 1
    bresenham(100, 100, 100, 300);

    // Example line with slope < 1
    bresenham(100, 150, 400, 450);

    // bresenham(100, 100, 400, 450);


    glFlush(); // Flush the OpenGL buffer
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);                        // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Set display mode
    glutInitWindowSize(500, 500);                 // Set window size
    glutCreateWindow("Bresenham's Line Drawing Algorithm"); // Create window with title
    init();                                       // Initialize OpenGL settings
    glutDisplayFunc(display);                     // Register display callback function
    glutMainLoop();                               // Enter the GLUT event processing loop
    return 0;                                     // Return success
}
