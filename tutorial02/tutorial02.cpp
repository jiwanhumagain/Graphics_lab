#include <GL/glut.h> // Include the GLUT library for OpenGL
#include <iostream>  // Include the iostream library for input/output operations
#include <cmath>     // Include the cmath library for mathematical operations

// Function to initialize OpenGL settings
void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Set background color to black
    glMatrixMode(GL_PROJECTION);       // Set the current matrix mode to projection
    glLoadIdentity();                  // Load the identity matrix into the projection matrix
    gluOrtho2D(0, 500, 0, 500);        // Set up a 2D orthographic projection
}

// Function to draw a single vertex at specified coordinates
void drawVertex(int x, int y) {
    glBegin(GL_POINTS);    // Begin drawing points
    glVertex2i(x, y);      // Specify a vertex at (x, y)
    glEnd();               // End drawing points
}

// DDA Line Drawing algorithm implementation
void DDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;                // Calculate change in x
    int dy = y2 - y1;                // Calculate change in y
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); // Determine the number of steps based on the larger change (dx or dy)
    float Xinc = dx / (float)steps; // Calculate the increment in x for each step
    float Yinc = dy / (float)steps; // Calculate the increment in y for each step
    float array_x_coordinates[steps]; // Array to store x coordinates of each step
    float array_y_coordinates[steps]; // Array to store y coordinates of each step
    array_x_coordinates[0] = x1;      // Initialize the first x coordinate
    array_y_coordinates[0] = y1;      // Initialize the first y coordinate

    // Iterate through each step and calculate the coordinates using DDA algorithm
    for (int i = 1; i < steps; i++) { 
        array_x_coordinates[i] = round(array_x_coordinates[i-1] + Xinc); // Calculate next x coordinate
        array_y_coordinates[i] = round(array_y_coordinates[i-1] + Yinc); // Calculate next y coordinate
    } 

    glColor3f(1.0, 1.0, 1.0); // Set line color to white
    // Draw each vertex calculated by the DDA algorithm
    for (int i = 0; i < steps; i++) {
        drawVertex(array_x_coordinates[i], array_y_coordinates[i]); // Draw the vertex
    }
    glFlush(); // Flush the OpenGL buffer
}

// Function to display content on the window
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
    DDA(100, 150, 400, 450);      // Draw a line using DDA algorithm from (100,150) to (400,450)
    glFlush();                    // Flush the OpenGL buffer
}

// Main function
int main(int argc, char **argv) {
    glutInit(&argc, argv);                        // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Set display mode
    glutInitWindowSize(500, 500);                 // Set window size
    glutCreateWindow("DDA Line Drawing Algorithm"); // Create window with title
    init();                                       // Initialize OpenGL settings
    glutDisplayFunc(display);                     // Register display callback function
    glutMainLoop();                               // Enter the GLUT event processing loop
    return 0;                                     // Return success
}
