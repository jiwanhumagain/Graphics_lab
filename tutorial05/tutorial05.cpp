// #include <GL/glut.h>
// #include <iostream>
// #include <cmath>

// // Window dimensions
// const int WIDTH = 1200;
// const int HEIGHT = 1000;

// // Define the clipping region (rectangle)
// const int X_MIN = 100;
// const int X_MAX = 500;
// const int Y_MIN = 100;
// const int Y_MAX = 400;

// // Define region codes for the clipping region edges
// const int INSIDE = 0; // 0000
// const int LEFT = 1;   // 0001
// const int RIGHT = 2;  // 0010
// const int BOTTOM = 4; // 0100
// const int TOP = 8;    // 1000

// // Function to compute region code for a point (x, y) relative to the clipping window
// int computeRegionCode(int x, int y) {
//     int code = INSIDE; // Initialize as inside

//     if (x < X_MIN)
//         code |= LEFT;
//     else if (x > X_MAX)
//         code |= RIGHT;

//     if (y < Y_MIN)
//         code |= BOTTOM;
//     else if (y > Y_MAX)
//         code |= TOP;

//     return code;
// }

// // Function to clip a line segment using Cohen-Sutherland algorithm
// void cohenSutherlandLineClip(int x1, int y1, int x2, int y2) {
//     int code1 = computeRegionCode(x1, y1);
//     int code2 = computeRegionCode(x2, y2);
//     bool accept = false;

//     while (true) {
//         if (!(code1 | code2)) { // Both endpoints are inside
//             accept = true;
//             break;
//         } else if (code1 & code2) { // Both endpoints are outside and on the same side
//             break;
//         } else {
//             int codeOut = code1 ? code1 : code2; // Get the code of the endpoint outside the window

//             // Calculate intersection point
//             int x, y;
//             if (codeOut & TOP) {
//                 x = x1 + (x2 - x1) * (Y_MAX - y1) / (y2 - y1);
//                 y = Y_MAX;
//             } else if (codeOut & BOTTOM) {
//                 x = x1 + (x2 - x1) * (Y_MIN - y1) / (y2 - y1);
//                 y = Y_MIN;
//             } else if (codeOut & RIGHT) {
//                 y = y1 + (y2 - y1) * (X_MAX - x1) / (x2 - x1);
//                 x = X_MAX;
//             } else if (codeOut & LEFT) {
//                 y = y1 + (y2 - y1) * (X_MIN - x1) / (x2 - x1);
//                 x = X_MIN;
//             }

//             if (codeOut == code1) {
//                 x1 = x;
//                 y1 = y;
//                 code1 = computeRegionCode(x1, y1);
//             } else {
//                 x2 = x;
//                 y2 = y;
//                 code2 = computeRegionCode(x2, y2);
//             }
//         }
//     }

//     if (accept) {
//         glColor3f(0.0, 0.0, 0.0); // Set line color to black
//         glBegin(GL_LINES);
//         glVertex2i(x1, y1);
//         glVertex2i(x2, y2);
//         glEnd();
//     }
// }

// void display() {
//     glClear(GL_COLOR_BUFFER_BIT);
//     glColor3f(1.0, 0.0, 0.0); // Set rectangle color to red
//     glBegin(GL_LINE_LOOP);
//     glVertex2i(X_MIN, Y_MIN);
//     glVertex2i(X_MAX, Y_MIN);
//     glVertex2i(X_MAX, Y_MAX);
//     glVertex2i(X_MIN, Y_MAX);
//     glEnd();

//      glColor3f(0.0, 0.0, 1.0); // Set line color to blue
//     cohenSutherlandLineClip(50, 200, 600, 200); // Line segment completely inside
//     cohenSutherlandLineClip(250, 50, 250, 500); // Line segment intersecting top edge
//     cohenSutherlandLineClip(350, 450, 600, 50); // Line segment intersecting top-right corner
//     cohenSutherlandLineClip(550, 300, 200, 100); // Line segment completely outside


//     // glClear(GL_COLOR_BUFFER_BIT);
//     glColor3f(1.0, 0.0, 0.0); // Set rectangle color to red
//     glBegin(GL_LINE_LOOP);
//     glVertex2i(X_MIN+500, Y_MIN+400);
//     glVertex2i(X_MAX+500, Y_MIN+400);
//     glVertex2i(X_MAX+500, Y_MAX+400);
//     glVertex2i(X_MIN+500, Y_MAX+400);
//     glEnd();

//     // Define initial line segments
//     int initialLines[][4] = {
//         {50+500, 200+400, 600+500, 200+400}, // Line segment completely inside
//         {250+500, 50+400, 250+500, 500+400}, // Line segment intersecting top edge
//         {350+500, 450+400, 600+500, 50+400}, // Line segment intersecting top-right corner
//         {550+500, 300+400, 200+500, 100+400} // Line segment completely outside
//     };

//     // Draw initial line segments (before clipping)
//     glColor3f(0.0, 0.0, 1.0); // Set line color to blue
//     for (const auto& line : initialLines) {
//         glBegin(GL_LINES);
//         glVertex2i(line[0], line[1]);
//         glVertex2i(line[2], line[3]);
//         glEnd();
//     }

//     glFlush();
// }

// void init() {
//     glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     gluOrtho2D(0, WIDTH, 0, HEIGHT);
// }

// int main(int argc, char **argv) {
//     glutInit(&argc, argv);
//     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//     glutInitWindowSize(WIDTH, HEIGHT);
//     glutCreateWindow("Cohen-Sutherland Line Clipping Algorithm");
//     init();
//     glutDisplayFunc(display);
//     glutMainLoop();

//     return 0;
// }


//polygon clipping

#include <GL/glut.h>
#include <iostream>
#include <vector>

// Window dimensions
const int WIDTH = 800;
const int HEIGHT = 600;

// Define the clipping region (rectangle)
const int X_MIN = 100;
const int X_MAX = 500;
const int Y_MIN = 100;
const int Y_MAX = 400;

// Define region codes for the clipping region edges
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

// Function to compute region code for a point (x, y) relative to the clipping window
int computeRegionCode(int x, int y) {
    int code = INSIDE; // Initialize as inside

    if (x < X_MIN)
        code |= LEFT;
    else if (x > X_MAX)
        code |= RIGHT;

    if (y < Y_MIN)
        code |= BOTTOM;
    else if (y > Y_MAX)
        code |= TOP;

    return code;
}

// Function to clip a polygon using Sutherland-Hodgman algorithm
std::vector<std::pair<int, int>> sutherlandHodgmanPolygonClip(const std::vector<std::pair<int, int>>& polygon) {
    std::vector<std::pair<int, int>> clippedPolygon = polygon;

    for (int edge = LEFT; edge <= TOP; edge <<= 1) { // Iterate over each clipping edge
        std::vector<std::pair<int, int>> inputList = clippedPolygon;
        clippedPolygon.clear();

        for (size_t i = 0; i < inputList.size(); ++i) {
            std::pair<int, int> current = inputList[i];
            std::pair<int, int> previous = (i == 0) ? inputList.back() : inputList[i - 1];

            int currentCode = computeRegionCode(current.first, current.second);
            int previousCode = computeRegionCode(previous.first, previous.second);

            if (!(currentCode & edge)) { // Current point inside
                if (previousCode & edge) { // Previous point outside
                    // Compute intersection point
                    int x, y;
                    switch (edge) {
                        case LEFT:
                            x = X_MIN;
                            y = previous.second + (current.second - previous.second) * (X_MIN - previous.first) / (current.first - previous.first);
                            break;
                        case RIGHT:
                            x = X_MAX;
                            y = previous.second + (current.second - previous.second) * (X_MAX - previous.first) / (current.first - previous.first);
                            break;
                        case BOTTOM:
                            y = Y_MIN;
                            x = previous.first + (current.first - previous.first) * (Y_MIN - previous.second) / (current.second - previous.second);
                            break;
                        case TOP:
                            y = Y_MAX;
                            x = previous.first + (current.first - previous.first) * (Y_MAX - previous.second) / (current.second - previous.second);
                            break;
                    }
                    clippedPolygon.push_back(std::make_pair(x, y));
                }
                clippedPolygon.push_back(current);
            } else if (!(previousCode & edge)) { // Current point outside, previous point inside
                // Compute intersection point
                int x, y;
                switch (edge) {
                    case LEFT:
                        x = X_MIN;
                        y = previous.second + (current.second - previous.second) * (X_MIN - previous.first) / (current.first - previous.first);
                        break;
                    case RIGHT:
                        x = X_MAX;
                        y = previous.second + (current.second - previous.second) * (X_MAX - previous.first) / (current.first - previous.first);
                        break;
                    case BOTTOM:
                        y = Y_MIN;
                        x = previous.first + (current.first - previous.first) * (Y_MIN - previous.second) / (current.second - previous.second);
                        break;
                    case TOP:
                        y = Y_MAX;
                        x = previous.first + (current.first - previous.first) * (Y_MAX - previous.second) / (current.second - previous.second);
                        break;
                }
                clippedPolygon.push_back(std::make_pair(x, y));
            }
        }
    }

    return clippedPolygon;
}

void drawPolygon(const std::vector<std::pair<int, int>>& polygon) {
    glBegin(GL_LINE_LOOP);
    for (const auto& point : polygon) {
        glVertex2i(point.first, point.second);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the clipping window (rectangle)
    glColor3f(1.0, 0.0, 0.0); // Set rectangle color to red
    glBegin(GL_LINE_LOOP);
    glVertex2i(X_MIN, Y_MIN);
    glVertex2i(X_MAX, Y_MIN);
    glVertex2i(X_MAX, Y_MAX);
    glVertex2i(X_MIN, Y_MAX);
    glEnd();

    // Define the polygon vertices
    std::vector<std::pair<int, int>> polygon = {
        {50, 200},
        {250, 50},
        {450, 250},
        {350, 450},
        {200, 350}
    };

    // Draw the original polygon
    glColor3f(0.0, 0.0, 0.0); // Set polygon color to blue
    drawPolygon(polygon);

    // Clip the polygon against the clipping window
    std::vector<std::pair<int, int>> clippedPolygon = sutherlandHodgmanPolygonClip(polygon);

    // Draw the clipped polygon
    glColor3f(0.0, 0.0, 1.0); // Set polygon color to green
    drawPolygon(clippedPolygon);

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WIDTH, 0, HEIGHT);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Sutherland-Hodgman Polygon Clipping Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
