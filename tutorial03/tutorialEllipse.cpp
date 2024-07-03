#include <GL/glut.h>
#include <cmath>

// Define the window dimensions
const int WIDTH = 800;
const int HEIGHT = 600;

// Define the center and semi-axes of the ellipse
int centerX = WIDTH / 2;
int centerY = HEIGHT / 2;
int a = 300; // Semi-major axis
int b = 200; // Semi-minor axis

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WIDTH, 0, HEIGHT);
}

void drawPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

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

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0); // Set line color to black
    midpointEllipse(centerX, centerY, a, b);
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Midpoint Ellipse Drawing Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
