#include <GL/glut.h>

// Shearing parameters
GLfloat shearXY = 0.0f;
GLfloat shearXZ = 0.0f;
GLfloat shearYX = 0.0f;
GLfloat shearYZ = 0.0f;
GLfloat shearZX = 0.0f;
GLfloat shearZY = 0.0f;

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
}

void multiplyMatrices(const GLfloat a[16], const GLfloat b[16], GLfloat result[16]) {
    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            result[row * 4 + col] =
                a[row * 4 + 0] * b[0 * 4 + col] +
                a[row * 4 + 1] * b[1 * 4 + col] +
                a[row * 4 + 2] * b[2 * 4 + col] +
                a[row * 4 + 3] * b[3 * 4 + col];
        }
    }
}

void createShearMatrix(GLfloat shearXY, GLfloat shearXZ, GLfloat shearYX, GLfloat shearYZ, GLfloat shearZX, GLfloat shearZY, GLfloat matrix[16]) {
    matrix[0] = 1.0f; matrix[4] = shearXY; matrix[8] = shearXZ; matrix[12] = 0.0f;
    matrix[1] = shearYX; matrix[5] = 1.0f; matrix[9] = shearYZ; matrix[13] = 0.0f;
    matrix[2] = shearZX; matrix[6] = shearZY; matrix[10] = 1.0f; matrix[14] = 0.0f;
    matrix[3] = 0.0f; matrix[7] = 0.0f; matrix[11] = 0.0f; matrix[15] = 1.0f;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);

    GLfloat shearMatrix[16];
    createShearMatrix(shearXY, shearXZ, shearYX, shearYZ, shearZX, shearZY, shearMatrix);

    // Apply the shear matrix
    glMultMatrixf(shearMatrix);

    // Draw a cube
    glBegin(GL_QUADS);

    // Front face
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);

    // Back face
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);

    // Top face
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);

    // Bottom face
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);

    // Right face
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);

    // Left face
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);

    glEnd();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'q': shearXY += 0.1f; break;
        case 'a': shearXY -= 0.1f; break;
        case 'w': shearXZ += 0.1f; break;
        case 's': shearXZ -= 0.1f; break;
        case 'e': shearYX += 0.1f; break;
        case 'd': shearYX -= 0.1f; break;
        case 'r': shearYZ += 0.1f; break;
        case 'f': shearYZ -= 0.1f; break;
        case 't': shearZX += 0.1f; break;
        case 'g': shearZX -= 0.1f; break;
        case 'y': shearZY += 0.1f; break;
        case 'h': shearZY -= 0.1f; break;
        case 27: exit(0); break; // ESC key to exit
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("3D Shearing Example");

    initGL();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
