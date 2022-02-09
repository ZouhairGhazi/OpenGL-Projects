#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QColor>
#include <QVector2D>
#include <QtOpenGLWidgets/QtOpenGLWidgets>


// Class to display an OpenGL scene
class MyGLWidget : public QOpenGLWidget
{
    Q_OBJECT

public:

    // Constructor
    MyGLWidget(QWidget * parent = nullptr);
    virtual void keyPressEvent(QKeyEvent*);

private:
    GLfloat mcolor_fond[4]; // GLfloat array to manipulate background color
    GLubyte mcolor_primitive[3]; // GLubyte array to manipulate primitive shape color
    bool rotated; // Boolean variable to track rotation
    int form; // Integer to track forms (Triangle, rectangle, polygon)

protected:

    // Initialization function
    void initializeGL();

    // Resizing function
    void resizeGL(int width, int height);

    // Display/Paint function
    void paintGL();
};

#endif // MYGLWIDGET_H
