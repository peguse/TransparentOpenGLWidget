#include "openglwidget.h"

const char vert_shader [] =
"#version 120\n"
"attribute vec4 position;\n"
"void main()\n"
"{\n"
"gl_Position = position;\n"
"}\n"
;

const char frag_shader [] =
"#version 120\n"
"void main()\n"
"{\n"
"gl_FragColor = vec4(0.0, 0.0, 1.0, 1.0);\n"
"}\n"
;

OpenGLWidget::OpenGLWidget(QWidget *parent)
:   QOpenGLWidget(parent)
{
}

void OpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();

    GLfloat vertices[] = {
        -0.85f, -0.85f,
         0.85f, -0.85f,
         0.0f,  0.85f
    };

    m_buffer = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    m_buffer.setUsagePattern(QOpenGLBuffer::StaticDraw);
    m_buffer.create();
    m_buffer.bind();
    m_buffer.allocate(sizeof(vertices));
    m_buffer.write(0, vertices, sizeof(vertices));

    m_program.addShaderFromSourceCode(QOpenGLShader::Vertex, vert_shader);
    m_program.addShaderFromSourceCode(QOpenGLShader::Fragment, frag_shader);
    m_program.link();
    m_program.bind();

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(0);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void OpenGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glFlush();
}
