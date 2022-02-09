#include "myglwidget.h"
#include <GL/glu.h>
#include <QApplication>

MyGLWidget::MyGLWidget(QWidget * parent) : QOpenGLWidget(parent)
{
    // Setting window size, default background color and primitive shape, color and rotation.
    setFixedSize(800, 600);
    mcolor_primitive[0] = 0;
    mcolor_primitive[1] = 0;
    mcolor_primitive[2] = 255;
    mcolor_fond[0] = 1.7f;
    mcolor_fond[1] = 0.7f;
    mcolor_fond[2] = 0.7f;
    mcolor_fond[3] = 0.0f;
    rotated = false;
    form = 0;
}


// Gray background as default
void MyGLWidget::initializeGL()
{
    glClearColor(mcolor_fond[0], mcolor_fond[1], mcolor_fond[2], mcolor_fond[3]);
}


// Setting up a perspective projection matrix to handle viewer's angle of view
void MyGLWidget::resizeGL(int width, int height)
{
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)width/height, 0.01, 100.0);
}


// Painting function
void MyGLWidget::paintGL()
{
    glClearColor(mcolor_fond[0], mcolor_fond[1], mcolor_fond[2], mcolor_fond[3]); // In case background color was changed
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (rotated) // 180 Rotation before and after the painting.
    {
        glRotated(180., 0., 0., 1.);
    }

    if (form == 0) // Painting a triangle
    {
        glBegin(GL_TRIANGLES);
            glColor3ub(mcolor_primitive[0], mcolor_primitive[1], mcolor_primitive[2]);
            glVertex3f(-0.2, -0.2, -4.0);
            glVertex3f( 0.2, -0.2, -4.0);
            glVertex3f( 0.0,  0.2, -4.0);
        glEnd();
    }

    if (form == 1)
    {
        glBegin(GL_QUADS); // Painting a square
            glColor3ub(mcolor_primitive[0], mcolor_primitive[1], mcolor_primitive[2]);
            glVertex3f (-0.2f, 0.2f, -4.0f);
            glVertex3f (0.2f, 0.2f, -4.0f);
            glVertex3f (0.2f, -0.2f, -4.0f);
            glVertex3f (-0.2f, -0.2f, -4.0f);
        glEnd();
    }

    if (form == 2)
    {
        glBegin ( GL_POLYGON ); // Painting a polygon
            glColor3ub(mcolor_primitive[0], mcolor_primitive[1], mcolor_primitive[2]);
            glVertex3f(0.0, 0.0, -4.0);
            glVertex3f(0.2, 0.0, -4.0);
            glVertex3f(0.3, 0.3, -4.0);
            glVertex3f(0.2, 0.5, -4.0);
            glVertex3f(0.0, 0.5, -4.0);
            glVertex3f(-0.2, 0.3, -4.0);
        glEnd();
    }


    if (rotated)
    {
        glRotated(180., 0., 0., 1.);
    }

}

void MyGLWidget::keyPressEvent(QKeyEvent* event)
{
    switch (event->key()) // Handling key presses
    {
    case Qt::Key_C : // If C key is pressed, randomly change the primitive shape's color.
        mcolor_primitive[0] = rand()%255;
        mcolor_primitive[1] = rand()%255;
        mcolor_primitive[2] = rand()%255;
        update();
        break;

    case Qt::Key_O : // If O key is pressed, randomly change the background's color.
        mcolor_fond[0] = (float)(rand()%255)/255.0;
        mcolor_fond[1] = (float)(rand()%255)/255.0;
        mcolor_fond[2] = (float)(rand()%255)/255.0;
        update();
        break;

    case Qt::Key_R : // If R key is pressed, rotate the primitive shape.
        rotated = !rotated;
        update();
        break;

    case Qt::Key_Space : // If space key is pressed, change the primitive shapes.
        form++;
        if (form > 2)
            form = 0;
        update();
        break;

    default:
        break;
    }
}


// Fonction de gestion des événements















