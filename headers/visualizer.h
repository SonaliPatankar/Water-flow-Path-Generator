#pragma once

#include <QtWidgets/QMainWindow>
#include "Visualizer.h"

class OpenGLWindow;

class Visualizer : public QMainWindow
{
    Q_OBJECT

public:
    Visualizer(QWindow* parent = nullptr);
    ~Visualizer();

private slots:  
    void onLoadReadFileButtonClicked();

private:
    void setupUi();

private:
    QPushButton* mReadFileButton;
    QWidget* mWidget;
    OpenGLWindow* mRenderer;
    QGridLayout* mCentralGrid;
};