﻿#ifndef WINDOW_H
#define WINDOW_H

#include "openglwindow.h"

namespace LEngine {
struct Camera3D;
}

class Window: public OpenGLWindow
{
    Q_OBJECT
public:
    Window(QWindow *parent=nullptr);
    ~Window() override;

    std::string loadFile(const std::string &file);

protected:
    void initialize() override;
    void update() override;
    void frameResize(int w, int h) override;
    void finalize() override;

    void mouseMoveEvent(QMouseEvent *ev) override;
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;
    void wheelEvent(QWheelEvent *ev) override;

private:
    LEngine::Camera3D *mCamera{nullptr};
    QPoint mLatestPoint;
    bool mPressed{false};
};

#endif // WINDOW_H
