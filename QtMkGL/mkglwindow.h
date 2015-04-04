#ifndef MKGLWINDOW_H
#define MKGLWINDOW_H

#include <QtGui/QWindow>
#include <QtGui/QOpenGLFunctions>

QT_BEGIN_NAMESPACE
class QPainter;
class QOpenGLContext;
class QOpenGLPaintDevice;
QT_END_NAMESPACE

class MkGLWindow : public QWindow, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit MkGLWindow(int sizex, int sizey, QWindow *parent = 0);
    MkGLWindow(QString windowName, int sizex, int sizey, QWindow *parent = 0);
    ~MkGLWindow();

    virtual void render(QPainter *painter);
    virtual void render();
    virtual void initialize();
    void setAnimating(bool animating);

public slots:
    void renderLater();
    void renderNow();

protected:
    bool event(QEvent *event);
    void exposeEvent(QExposeEvent *event);

private:
    bool m_update_pending;
    bool m_animating;
    QOpenGLContext *m_context;
    QOpenGLPaintDevice *m_device;
};

#endif // MKGLWINDOW_H
