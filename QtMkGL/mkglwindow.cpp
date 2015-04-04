#include "mkglwindow.h"

#include <QtCore/QCoreApplication>

#include <QtGui/QOpenGLContext>
#include <QtGui/QOpenGLPaintDevice>
#include <QtGui/QPainter>

/*MkGL Widow Contructors*/
MkGLWindow::MkGLWindow(int sizex, int sizey, QWindow *parent)
    : QWindow(parent)
    , m_update_pending(false)
    , m_animating(false)
    , m_context(0)
    , m_device(0)
{
    setSurfaceType(QWindow::OpenGLSurface);
    setTitle("MkGL Window");
    setWidth(sizex);
    setHeight(sizey);
}

MkGLWindow::MkGLWindow(QString windowName, int sizex, int sizey, QWindow *parent)
    : QWindow(parent)
    , m_update_pending(false)
    , m_animating(false)
    , m_context(0)
    , m_device(0)
{
    setSurfaceType(QWindow::OpenGLSurface);
    setTitle(windowName);
    setWidth(sizex);
    setHeight(sizey);
}

/*MkGL Widow Destructor*/
MkGLWindow::~MkGLWindow()
{
    delete m_device;
}

/*MkGL Implementations*/
void MkGLWindow::render(QPainter *painter)
{
    Q_UNUSED(painter);
}

void MkGLWindow::initialize()
{
}

void MkGLWindow::render()
{
    if (!m_device)
        m_device = new QOpenGLPaintDevice;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    m_device->setSize(size());

    QPainter painter(m_device);
    render(&painter);
}

void MkGLWindow::renderLater()
{
    if (!m_update_pending) {
        m_update_pending = true;
        QCoreApplication::postEvent(this, new QEvent(QEvent::UpdateRequest));
    }
}

bool MkGLWindow::event(QEvent *event)
{
    switch (event->type()) {
    case QEvent::UpdateRequest:
        m_update_pending = false;
        renderNow();
        return true;
    default:
        return QWindow::event(event);
    }
}

void MkGLWindow::exposeEvent(QExposeEvent *event)
{
    Q_UNUSED(event);

    if (isExposed())
        renderNow();
}

void MkGLWindow::renderNow()
{
    if (!isExposed())
        return;

    bool needsInitialize = false;

    if (!m_context) {
        m_context = new QOpenGLContext(this);
        m_context->setFormat(requestedFormat());
        m_context->create();

        needsInitialize = true;
    }

    m_context->makeCurrent(this);

    if (needsInitialize) {
        initializeOpenGLFunctions();
        initialize();
    }

    render();

    m_context->swapBuffers(this);

    if (m_animating)
        renderLater();
}

void MkGLWindow::setAnimating(bool animating)
{
    m_animating = animating;

    if (animating)
        renderLater();
}
