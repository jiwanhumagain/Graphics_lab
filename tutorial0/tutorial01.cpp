#include <GL/freeglut.h>
#include <stdio.h>
#include <cmath>

#define MAX_SEGMENTS 12
float lineEndpointsAwayFromCircle[MAX_SEGMENTS][2];
float lineEndpointsNearToCircle[MAX_SEGMENTS][2];

void draw_circle(const GLfloat center[2], GLfloat radius, GLint segments, const GLfloat fill_color[3])
{
    // Fill the circle
    glColor3fv(fill_color);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(center[0], center[1]);
    for (int i = 0; i <= segments; ++i)
    {
        GLfloat angle = 2 * M_PI * i / segments;
        GLfloat x = center[0] + cos(angle) * radius;
        GLfloat y = center[1] + sin(angle) * radius;
        glVertex2f(x, y);
    }
    glEnd();

    // Outline the circle
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(7);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i <= segments; ++i)
    {
        GLfloat angle = 2 * M_PI * i / segments;
        GLfloat x = center[0] + cos(angle) * radius;
        GLfloat y = center[1] + sin(angle) * radius;
        glVertex2f(x, y);
    }
    glEnd();
}

void drawLinesPerpendicularToCircle(float cx, float cy, float r, int num_segments)
{
    glLineWidth(10.0f); // Set the width of the lines to 10 units

    glBegin(GL_LINES);
    

    float deltaTheta = 2.0f * 3.1415926f / float(num_segments);
    float theta = 0.0f;

    for (int i = 0; i < num_segments; i++)
    {
        float x1 = r * cosf(theta) + cx;
        float y1 = r * sinf(theta) + cy;

        float x2 = (r + 50) * cosf(theta) + cx;
        float y2 = (r + 50) * sinf(theta) + cy;

        //     // Store the endpoints in the array
        lineEndpointsNearToCircle[i][0] = x1;
        lineEndpointsNearToCircle[i][1] = y1;
        lineEndpointsAwayFromCircle[i][0] = x2;
        lineEndpointsAwayFromCircle[i][1] = y2;

        theta += deltaTheta;
    }

    glEnd();
}
void draw_rectangle(const GLfloat center[2], GLfloat width, GLfloat height, const GLfloat color[3])
{
    glColor3fv(color);
    GLfloat half_width = width / 2;
    GLfloat half_height = height / 2;
    glBegin(GL_QUADS);
    glVertex2f(center[0] - half_width, center[1] - half_height);
    glVertex2f(center[0] + half_width, center[1] - half_height);
    glVertex2f(center[0] + half_width, center[1] + half_height);
    glVertex2f(center[0] - half_width, center[1] + half_height);
    glEnd();
}
void draw_u_shape_with_thickness_and_rotation(GLfloat x, GLfloat y, GLfloat width, GLfloat height, GLfloat thickness, GLfloat space, GLfloat angle)
{
    glPushMatrix();
    GLfloat center_x = x + (width + space + thickness) / 2;
    GLfloat center_y = y + height / 2;
    glTranslatef(center_x, center_y, 0);
    glRotatef(angle, 0, 0, 1);
    glTranslatef(-center_x, -center_y, 0);

    // Draw each part of the U shape
    glColor3f(0.0f, 0.0f, 0.0f); // Assuming black color for U shape
    glBegin(GL_QUADS);
    // Left vertical line
    glVertex2f(x, y);
    glVertex2f(x + thickness, y);
    glVertex2f(x + thickness, y + height);
    glVertex2f(x, y + height);

    // Right vertical line
    glVertex2f(x + width + space, y);
    glVertex2f(x + width + space + thickness, y);
    glVertex2f(x + width + space + thickness, y + height);
    glVertex2f(x + width + space, y + height);

    // Bottom horizontal line
    glVertex2f(x, y);
    glVertex2f(x + width + space + thickness, y);
    glVertex2f(x + width + space + thickness, y + thickness);
    glVertex2f(x, y + thickness);
    glEnd();

    glPopMatrix();
}
void draw_triangle(const GLfloat base_center[2], GLfloat base_width, GLfloat height, const GLfloat color[3])
{
    glColor3fv(color);
    GLfloat half_base_width = base_width / 2;

    glBegin(GL_TRIANGLES);
    glVertex2f(base_center[0] - half_base_width, base_center[1]);
    glVertex2f(base_center[0] + half_base_width, base_center[1]);
    glVertex2f(base_center[0], base_center[1] + height);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(7);
    glBegin(GL_LINE_LOOP);
    glVertex2f(base_center[0] - half_base_width, base_center[1]);
    glVertex2f(base_center[0] + half_base_width, base_center[1]);
    glVertex2f(base_center[0], base_center[1] + height);
    glEnd();
}

void draw_triangle_line(const GLfloat base_center[2], GLfloat base_width, GLfloat height, const GLfloat color[3])
{
    glColor3fv(color);
    GLfloat half_base_width = base_width / 2;
    glLineWidth(10);
    glBegin(GL_LINE_LOOP);

    glVertex2f(base_center[0] - half_base_width, base_center[1]); // Left Base Vertex
    glVertex2f(base_center[0] + half_base_width, base_center[1]); // Right Base Vertex
    glVertex2f(base_center[0], base_center[1] + height);          // Top Vertex
    glEnd();
}

void draw_triangle_line_small(const GLfloat base_center[2], GLfloat base_width, GLfloat height, const GLfloat color[3])
{
    glColor3fv(color);
    GLfloat half_base_width = base_width / 2;
    glLineWidth(5); // Smaller line width
    glBegin(GL_LINE_LOOP);

    glVertex2f(base_center[0] - half_base_width, base_center[1]); // Left Base Vertex
    glVertex2f(base_center[0] + half_base_width, base_center[1]); // Right Base Vertex
    glVertex2f(base_center[0], base_center[1] + height);          // Top Vertex
    glEnd();
}


// Function to handle rendering

static void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Set background color to white
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // White color

    // Set circle parameters
    float centerX = 0.0f;
    float centerY = 0.0f;
    float radius = 0.5f;
    int numSegments = 50; // Number of line segments to approximate a circle
    GLfloat center_circle_main[2] = {0.0f, 0.0f};
    GLfloat color_circle_main[3] = {0.66f, 0.66f, 0.9f}; // Mauve for fill
                                                         // Draw outer circle with specified colors

    
    draw_circle(center_circle_main, 0.8f, 100, color_circle_main);
    // Drawing the smaller circle inside the main circle
    GLfloat color_circle_inner[3] = {1.0f, 1.0f, 0.0f}; // Yellow for inner circle
    draw_circle(center_circle_main, 0.65f, 100, color_circle_inner);

    drawLinesPerpendicularToCircle(0.0f, 0.0f, 300, MAX_SEGMENTS);

     // Drawing a triangle
        GLfloat base_center_triangle[2] = {0.0f, 0.3f};
        GLfloat color_triangle[3] = {1.0f, 0.7f, 0.8f}; // Pinkish color
        draw_triangle(base_center_triangle, 1.1f, -0.92f, color_triangle);
        GLfloat color_triangle_line[3] = {1.0f, 1.0f, 1.0f};
        // Draw triangle lines
        GLfloat base_center_line1[2] = {0.0f, -0.28f};
        draw_triangle_line(base_center_line1, 1.2f, 0.92f, color_triangle_line);
        // Draw triangle lines
        GLfloat base_center_line2[2] = {0, -0.245};
        draw_triangle_line(base_center_line2, 1.1f, 0.84f, color_triangle_line);
        GLfloat color_triangle_small[3] = {0.0f, 0.0f, 0.0f};
        GLfloat base_center_line_small1[2] = {0.0f, -0.29f};
        draw_triangle_line_small(base_center_line_small1, 1.2f, 0.96f, color_triangle_small);
        GLfloat base_center_line_small2[2] = {0.0f, -0.245f};
        draw_triangle_line_small(base_center_line_small2, 1.05f, 0.84f, color_triangle_small);
    GLfloat center_rectangle[2] = {-0.07f, 0.0f};
    GLfloat color_rectangle[3] = {0.0f, 0.0f, 0.0f}; // Black for the rectangle
    draw_rectangle(center_rectangle, 0.05f, 0.3f, color_rectangle);
    draw_u_shape_with_thickness_and_rotation(-0.01f, -0.1f, 0.02f, 0.175f, 0.05f, 0.1f, -30);


    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

    int width = 800;
    int height = 600;
    glutInitWindowSize(width, height);

    int x = 200;
    int y = 100;
    glutInitWindowPosition(x, y);
    int win = glutCreateWindow("Triangles Inside Circle");
    printf("Window ID: %d\n", win);

    GLclampf Red = 1.0f, Green = 1.0f, Blue = 1.0f, Alpha = 1.0f;
    glClearColor(Red, Green, Blue, Alpha);

    glutDisplayFunc(RenderSceneCB);

    glutMainLoop();

    return 0;
}
