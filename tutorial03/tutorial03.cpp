// //Circle using midpoint
// #include <GL/glut.h>    // Include the GLUT library for OpenGL
// #include <cmath>        // Include the cmath library for mathematical operations

// const int WIDTH = 800;  // Define the window width
// const int HEIGHT = 600; // Define the window height

// int centerX = WIDTH / 2;    // Calculate the x-coordinate of the center of the circle
// int centerY = HEIGHT / 2;   // Calculate the y-coordinate of the center of the circle
// int radius = 200;           // Define the radius of the circle

// // Function to initialize OpenGL settings
// void init() {
//     glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
//     glMatrixMode(GL_PROJECTION);       // Set the current matrix mode to projection
//     glLoadIdentity();                  // Load the identity matrix into the projection matrix
//     gluOrtho2D(0, WIDTH, 0, HEIGHT);   // Set up a 2D orthographic projection
// }

// // Function to draw a single pixel
// void drawPixel(int x, int y) {
//     glBegin(GL_POINTS);    // Begin drawing points
//     glVertex2i(x, y);      // Specify a vertex at (x, y)
//     glEnd();               // End drawing points
// }

// // Function to draw a circle using the midpoint algorithm
// void midpointCircle(int centerX, int centerY, int radius) {
//     int x = 0;              // Initialize x-coordinate of the point
//     int y = radius;         // Initialize y-coordinate of the point
//     int p = 1 - radius;     // Initialize decision parameter

//     // Iterate until x is less than or equal to y
//     while (x <= y) {
//         // Plot the eight symmetric points
//         drawPixel(centerX + x, centerY + y);
//         drawPixel(centerX - x, centerY + y);
//         drawPixel(centerX + x, centerY - y);
//         drawPixel(centerX - x, centerY - y);
//         drawPixel(centerX + y, centerY + x);
//         drawPixel(centerX - y, centerY + x);
//         drawPixel(centerX + y, centerY - x);
//         drawPixel(centerX - y, centerY - x);

//         // Update decision parameter and coordinates based on the midpoint algorithm
//         if (p < 0) {
//             p += 2 * x + 3;
//         } else {
//             p += 2 * (x - y) + 5;
//             y--;
//         }
//         x++;
//     }
// }

// // Function to display content on the window
// void display() {
//     glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
//     glColor3f(0.0, 0.0, 0.0);       // Set line color to black
//     midpointCircle(centerX, centerY, radius); // Draw the circle using midpoint algorithm
//     glFlush();                      // Flush the OpenGL buffer
// }

// // Main function
// int main(int argc, char **argv) {
//     glutInit(&argc, argv);                          // Initialize GLUT
//     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    // Set display mode
//     glutInitWindowSize(WIDTH, HEIGHT);              // Set window size
//     glutCreateWindow("Midpoint Circle Drawing Algorithm"); // Create window with title
//     init();                                         // Initialize OpenGL settings
//     glutDisplayFunc(display);                       // Register display callback function
//     glutMainLoop();                                 // Enter the GLUT event processing loop
//     return 0;                                       // Return success
// }

//Ellipse using midpoint
#include <GL/glut.h>    // Include the GLUT library for OpenGL
#include <cmath>        // Include the cmath library for mathematical operations

// Define the window dimensions
const int WIDTH = 800;
const int HEIGHT = 600;

// Define the center and semi-axes of the ellipse
int centerX = WIDTH / 2;
int centerY = HEIGHT / 2;
int a = 300; // Semi-major axis
int b = 150; // Semi-minor axis

// Function to initialize OpenGL settings
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
    glMatrixMode(GL_PROJECTION);       // Set the current matrix mode to projection
    glLoadIdentity();                  // Load the identity matrix into the projection matrix
    gluOrtho2D(0, WIDTH, 0, HEIGHT);   // Set up a 2D orthographic projection
}

// Function to draw a single pixel
void drawPixel(int x, int y) {
    glBegin(GL_POINTS);    // Begin drawing points
    glVertex2i(x, y);      // Specify a vertex at (x, y)
    glEnd();               // End drawing points
}

// Function to draw an ellipse using the midpoint algorithm
void midpointEllipse(int centerX, int centerY, int a, int b) {
    int x = 0;
    int y = b;
    double d1 = b * b - a * a * b + 0.25 * a * a;
    double dx = 2 * b * b * x;
    double dy = 2 * a * a * y;

    while (dx < dy) {
        drawPixel(centerX + x, centerY + y);
        drawPixel(centerX - x, centerY + y);
        drawPixel(centerX + x, centerY - y);
        drawPixel(centerX - x, centerY - y);

        if (d1 < 0) {
            x++;
            dx = dx + 2 * b * b;
            d1 = d1 + dx + b * b;
        } else {
            x++;
            y--;
            dx = dx + 2 * b * b;
            dy = dy - 2 * a * a;
            d1 = d1 + dx - dy + b * b;
        }
    }

    double d2 = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b;

    while (y >= 0) {
        drawPixel(centerX + x, centerY + y);
        drawPixel(centerX - x, centerY + y);
        drawPixel(centerX + x, centerY - y);
        drawPixel(centerX - x, centerY - y);

        if (d2 > 0) {
            y--;
            dy = dy - 2 * a * a;
            d2 = d2 + a * a - dy;
        } else {
            y--;
            x++;
            dx = dx + 2 * b * b;
            dy = dy - 2 * a * a;
            d2 = d2 + dx - dy + a * a;
        }
    }
}

// Function to display content on the window
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
    glColor3f(0.0, 0.0, 0.0);     // Set line color to black
    midpointEllipse(centerX, centerY, a, b); // Draw the ellipse using midpoint algorithm
    glFlush(); // Flush the OpenGL buffer
}

// Main function
int main(int argc, char **argv) {
    glutInit(&argc, argv);                          // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    // Set display mode
    glutInitWindowSize(WIDTH, HEIGHT);              // Set window size
    glutCreateWindow("Midpoint Ellipse Drawing Algorithm"); // Create window with title
    init();                                         // Initialize OpenGL settings
    glutDisplayFunc(display);                       // Register display callback function
    glutMainLoop();                                 // Enter the GLUT event processing loop
    return 0;                                       // Return success
}

// //Circle using Polar Coordinates
// #include <GL/glut.h>    // Include the GLUT library for OpenGL
// #include <cmath>        // Include the cmath library for mathematical operations

// // Define the window dimensions
// const int WIDTH = 800;
// const int HEIGHT = 600;

// // Define the center and radius of the circle
// int centerX = WIDTH / 2;
// int centerY = HEIGHT / 2;
// int radius = 200;

// // Function to initialize OpenGL settings
// void init() {
//     glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
//     glMatrixMode(GL_PROJECTION);       // Set the current matrix mode to projection
//     glLoadIdentity();                  // Load the identity matrix into the projection matrix
//     gluOrtho2D(0, WIDTH, 0, HEIGHT);   // Set up a 2D orthographic projection
// }

// // Function to draw a single pixel
// void drawPixel(int x, int y) {
//     glBegin(GL_POINTS);    // Begin drawing points
//     for (int i = x - 1; i <= x + 1; ++i) { // Loop for nearby pixels in x direction
//         for (int j = y - 1; j <= y + 1; ++j) { // Loop for nearby pixels in y direction
//             glVertex2i(i, j); // Specify a vertex at (i, j)
//         }
//     }
//     glEnd();    // End drawing points
// }

// // Function to draw a circle using polar coordinates
// void polarCircle(int centerX, int centerY, int radius) {
//     glColor3f(0.0, 0.0, 0.0); // Set line color to black

//     // Iterate through angles from 0 to 360 degrees
//     for (int theta = 0; theta <= 360; ++theta) {
//         double thetaRadians = theta * (M_PI / 180.0); // Convert angle to radians
//         int x = centerX + round(radius * cos(thetaRadians)); // Calculate x-coordinate using polar equation
//         int y = centerY + round(radius * sin(thetaRadians)); // Calculate y-coordinate using polar equation
//         drawPixel(x, y); // Draw the pixel at (x, y)
//     }
// }

// // Function to display content on the window
// void display() {
//     glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
//     polarCircle(centerX, centerY, radius); // Draw the circle using polar coordinates
//     glFlush(); // Flush the OpenGL buffer
// }

// // Main function
// int main(int argc, char **argv) {
//     glutInit(&argc, argv);                          // Initialize GLUT
//     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    // Set display mode
//     glutInitWindowSize(WIDTH, HEIGHT);              // Set window size
//     glutCreateWindow("Circle Drawing Algorithm (Polar Coordinate System)"); // Create window with title
//     init();                                         // Initialize OpenGL settings
//     glutDisplayFunc(display);                       // Register display callback function
//     glutMainLoop();                                 // Enter the GLUT event processing loop
//     return 0;                                       // Return success
// }
