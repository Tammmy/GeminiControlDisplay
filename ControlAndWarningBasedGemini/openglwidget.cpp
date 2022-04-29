#include "openglwidget.h"

OpenGLWidget::OpenGLWidget(QWidget* parent)
    :   QOpenGLWidget(parent)
{

}

void OpenGLWidget::initializeGL()
{
    //调用内容初始化函数
    initializeOpenGLFunctions();
    // 创建顶点着色器
    QOpenGLShader* vshader = new QOpenGLShader(QOpenGLShader::Vertex, this);
    const char* vsrc =
                    "void main() {                             \n"
                    "   gl_Position = vec4(0.0, 0.0, 0.0, 1.0);\n"
                    "}                                         \n";
    vshader->compileSourceCode(vsrc);
    // 创建片段着色器
    QOpenGLShader* fshader = new QOpenGLShader(QOpenGLShader::Fragment, this);
    const char* fsrc =
                    "void main() {                              \n"
                    "   gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);\n"
                    "}                                          \n";
    fshader->compileSourceCode(fsrc);
    // 创建着色器程序
    program = new QOpenGLShaderProgram;
    program->addShader(vshader);
    program->addShader(fshader);
    program->link();
    program->bind();
}
void OpenGLWidget::resizeGL(int w, int h)
{
    //当窗口大小改变时，调整界面坐标显示高度和宽度
    glViewport(0, 0, w, h);
}
void OpenGLWidget::paintGL()
{
    //清除之前图形并将背景设置为黑色（设置为黑色纯粹个人爱好！）
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    // 绘制
    glDrawArrays(GL_POINTS, 0, 1);
}
