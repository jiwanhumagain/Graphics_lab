#include <GL/glut.h>
#include <iostream>
#include <vector>
using namespace std;
// Define the window dimensions
const int WIDTH = 800;
const int HEIGHT = 600;

// Define the maximum frequency value
const int MAX_FREQUENCY = 100;

// Input frequency values (sample data)
std::vector<int> frequencies = {20, 15, 30, 20,20,20};

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WIDTH, 0, HEIGHT);
}

void drawPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void bresenhamLine(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;
    int x = x1;
    int y = y1;
    while (true)
    {
        drawPixel(x, y);

        if (x == x2 && y == y2)
            break;
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y += sy;
        }
    }
}

void drawAxes()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.5, 0.0);

    // Draw x-axis
    for (int i = 0; i < 3; ++i)
        bresenhamLine(0, HEIGHT - 550 - i, WIDTH, HEIGHT - 550 - i);

    // Draw y-axis
    for (int i = 0; i < 3; ++i)
        bresenhamLine(WIDTH - 750 + i, 0, WIDTH - 750 + i, HEIGHT);
}
void drawHistogramBar()
{
    int barWidth = WIDTH / frequencies.size();
    int startX = barWidth / 2;

    for (size_t i = 0; i < frequencies.size(); i++)
    {
        int barHeight = frequencies[i] * HEIGHT / MAX_FREQUENCY;
        if (i != 0)
        {
            int prevbarHeight = (HEIGHT / 2) + (frequencies[i - 1] * HEIGHT / MAX_FREQUENCY);

            // cout<<"PrevHeight "<<prevbarHeight<<" nextHeight"<<barHeight;
            if (prevbarHeight > barHeight)
            {
                bresenhamLine(startX, HEIGHT / 2 + barHeight, startX, prevbarHeight);
                // cout<<"Prev height "<<prevbarHeight;
            }
        }

        int tempYCoordinate = HEIGHT / 2 + barHeight;

        // Draw vertical line starting from the x-axis
        bresenhamLine(startX, HEIGHT - 550, startX, HEIGHT / 2 + barHeight);
        if (i != frequencies.size() - 1)
        {
            bresenhamLine(startX, HEIGHT / 2 + barHeight, startX + barWidth, HEIGHT / 2 + barHeight);
        }

        // cout<<"StartX"<<tempYCoordinate<<" Height"<<HEIGHT/2+barHeight;

        // Move to next bar
        startX += barWidth;
    }
}

void drawHistogram()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0); // Set line color to black

    drawAxes(); // Draw x and y axes
    drawHistogramBar();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Line Histogram Drawing");
    init();
    glutDisplayFunc(drawHistogram);
    glutMainLoop();

    return 0;
}
