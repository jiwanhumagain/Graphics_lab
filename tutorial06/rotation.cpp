
//Rotation
#include <GL/glut.h>
#include <cmath>

// Rotation angles
GLfloat angleX = 0.0f;
GLfloat angleY = 0.0f;
GLfloat angleZ = 0.0f;

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

void createRotationMatrixX(GLfloat angle, GLfloat matrix[16]) {
    GLfloat radians = angle * M_PI / 180.0f;
    GLfloat cosA = cosf(radians);
    GLfloat sinA = sinf(radians);
    matrix[0] = 1.0f; matrix[4] = 0.0f; matrix[8] = 0.0f;  matrix[12] = 0.0f;
    matrix[1] = 0.0f; matrix[5] = cosA; matrix[9] = -sinA; matrix[13] = 0.0f;
    matrix[2] = 0.0f; matrix[6] = sinA; matrix[10] = cosA; matrix[14] = 0.0f;
    matrix[3] = 0.0f; matrix[7] = 0.0f; matrix[11] = 0.0f; matrix[15] = 1.0f;
}

void createRotationMatrixY(GLfloat angle, GLfloat matrix[16]) {
    GLfloat radians = angle * M_PI / 180.0f;
    GLfloat cosA = cosf(radians);
    GLfloat sinA = sinf(radians);
    matrix[0] = cosA; matrix[4] = 0.0f; matrix[8] = sinA;  matrix[12] = 0.0f;
    matrix[1] = 0.0f; matrix[5] = 1.0f; matrix[9] = 0.0f;  matrix[13] = 0.0f;
    matrix[2] = -sinA; matrix[6] = 0.0f; matrix[10] = cosA; matrix[14] = 0.0f;
    matrix[3] = 0.0f; matrix[7] = 0.0f; matrix[11] = 0.0f; matrix[15] = 1.0f;
}

void createRotationMatrixZ(GLfloat angle, GLfloat matrix[16]) {
    GLfloat radians = angle * M_PI / 180.0f;
    GLfloat cosA = cosf(radians);
    GLfloat sinA = sinf(radians);
    matrix[0] = cosA; matrix[4] = -sinA; matrix[8] = 0.0f; matrix[12] = 0.0f;
    matrix[1] = sinA; matrix[5] = cosA; matrix[9] = 0.0f;  matrix[13] = 0.0f;
    matrix[2] = 0.0f; matrix[6] = 0.0f; matrix[10] = 1.0f; matrix[14] = 0.0f;
    matrix[3] = 0.0f; matrix[7] = 0.0f; matrix[11] = 0.0f; matrix[15] = 1.0f;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);

    GLfloat rotationMatrixX[16];
    GLfloat rotationMatrixY[16];
    GLfloat rotationMatrixZ[16];
    GLfloat resultMatrix[16];

    // Create individual rotation matrices
    createRotationMatrixX(angleX, rotationMatrixX);
    createRotationMatrixY(angleY, rotationMatrixY);
    createRotationMatrixZ(angleZ, rotationMatrixZ);

    // Combine rotations: RotationZ * RotationY * RotationX
    multiplyMatrices(rotationMatrixZ, rotationMatrixY, resultMatrix);
    multiplyMatrices(resultMatrix, rotationMatrixX, resultMatrix);

    // Apply the final rotation matrix
    glMultMatrixf(resultMatrix);

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
        case 'i': angleX += 5.0f; break;
        case 'k': angleX -= 5.0f; break;
        case 'j': angleY += 5.0f; break;
        case 'l': angleY -= 5.0f; break;
        case 'u': angleZ += 5.0f; break;
        case 'o': angleZ -= 5.0f; break;
        case 27: exit(0); break; // ESC key to exit
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("3D Rotation");

    initGL();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}

