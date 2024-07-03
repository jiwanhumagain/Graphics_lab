#include <GL/glut.h>

// Scaling parameters
GLfloat scaleX = 1.0f;
GLfloat scaleY = 1.0f;
GLfloat scaleZ = 1.0f;

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
}

void createScalingMatrix(GLfloat scaleX, GLfloat scaleY, GLfloat scaleZ, GLfloat matrix[16]) {
    matrix[0] = scaleX; matrix[4] = 0.0f;   matrix[8] = 0.0f;   matrix[12] = 0.0f;
    matrix[1] = 0.0f;   matrix[5] = scaleY; matrix[9] = 0.0f;   matrix[13] = 0.0f;
    matrix[2] = 0.0f;   matrix[6] = 0.0f;   matrix[10] = scaleZ; matrix[14] = 0.0f;
    matrix[3] = 0.0f;   matrix[7] = 0.0f;   matrix[11] = 0.0f;  matrix[15] = 1.0f;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);

    GLfloat scalingMatrix[16];
    createScalingMatrix(scaleX, scaleY, scaleZ, scalingMatrix);

    // Apply the scaling matrix
    glMultMatrixf(scalingMatrix);

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
        case 'i': scaleX += 0.1f; break;
        case 'k': scaleX -= 0.1f; break;
        case 'j': scaleY += 0.1f; break;
        case 'l': scaleY -= 0.1f; break;
        case 'u': scaleZ += 0.1f; break;
        case 'o': scaleZ -= 0.1f; break;
        case 27: exit(0); break; // ESC key to exit
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("3D Scaling Example");

    initGL();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
