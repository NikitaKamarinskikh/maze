#ifndef GLWIDGET_H
#define GLWIDGET_H

#define GL_SILENCE_DEPRECATION
#include <GL/glut.h>

#include <QGLWidget>

#include "../model/maze.h"

// class GLWidget : public QOpenGLWidget
class GLWidget : public QGLWidget {
  Q_OBJECT
 public:
  explicit GLWidget(QWidget* parent = 0);

  void initializeGL();
  void paintGL();
  void resizeGL(int w, int h);

 private:
  const s21::Maze* maze_;

 private:
  void DrawMaze();
  void DrawCell(const s21::MazeCell& cell);
  void DrawTopBorder(const s21::CellCoordinates& coordinates);
  void DrawRightBorder(const s21::CellCoordinates& coordinates);
  void DrawBottomBorder(const s21::CellCoordinates& coordinates);
  void DrawLeftBorder(const s21::CellCoordinates& coordinates);
  void DrawSolvingPath();
  void DrawSolvingPathPoints(const s21::Maze::solving_path_type& solving_path);

 public:
  void SetMaze(const s21::Maze* maze);
};

#endif  // GLWIDGET_H
