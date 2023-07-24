#ifndef CAVEWIDGET_H
#define CAVEWIDGET_H

#define GL_SILENCE_DEPRECATION

#include <GL/glut.h>
#include <QGLWidget>

#include "../model/cave.h"
#include "../model/exceptions.h"

class CaveWidget : public QGLWidget {
  Q_OBJECT

 public:
  explicit CaveWidget(QWidget* parent = 0);

  void initializeGL();
  void paintGL();
  void resizeGL(int w, int h);

 private:
  const s21::Cave* cave_;

 public:
  void SetCave(const s21::Cave* cave);

 private:
  void DrawCave();
  void DrawCell(const s21::CaveCell& cell);
};

#endif  // CAVEWIDGET_H
