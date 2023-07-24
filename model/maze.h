#ifndef MAZE_H_
#define MAZE_H_

#include <fstream>
#include <stack>

#include "exceptions.h"
#include "field.h"
#include "matrix.h"
#include "maze_cell.h"
#include "parser.h"

namespace s21 {

constexpr unsigned kDefaultRow = 0;
constexpr int kDefaultSetNumber = 1;

class Maze : public s21::Field<s21::Matrix<s21::MazeCell>> {
 public:
  using size_type = Matrix<s21::MazeCell>::size_type;
  using cells_type = Matrix<s21::MazeCell>;
  using solving_path_type = std::vector<s21::Coordinates2D>;
  using solving_stack_type = std::stack<s21::MazeCell>;

 private:
  size_type current_row_{kDefaultRow};
  int set_number_{kDefaultSetNumber};
  solving_path_type solving_path_;
  solving_stack_type solving_stack_;
  Parser parser_;

 public:
  // Functions
  void Generate(size_type rows, size_type columns);
  void Reset();
  void SaveToFile(const std::string file_path);
  void Solve(const CellMatrixCoordinates& start_cell,
             const CellMatrixCoordinates& end_cell);
  bool IsInithialized() const;
  bool HasSolvingPath() const;
  void LoadFromFile(const std::string file_path);

  // Getters
  const solving_path_type& GetSolvingPath() const;

 private:
  // Generation functions
  void GenerateFirstRow();
  void GenerateMiddleRows();
  void GenerateLastRow();
  void NumerateRow();
  void CreateRightBorders();
  void MergeCells(const size_type start_cell_index);
  void CreateBottomBorders();
  void ValidateBottomBorders();
  void PrepareNewRow();
  void CopyPrewiousRowWithoutTopBordes();
  void RemoveAllRightBorders();
  void DenumerateCellsWithBottomBorder();
  void RemoveAllBottomBorders();

  // Solving functions
  void CreateSolvingPath();
  bool IsCorrectCellMatrixCoordinates(const CellMatrixCoordinates& start_cell,
                                      const CellMatrixCoordinates& end_cell);
  void PrepareMazeForSolving();

  // Other functions
  bool RandomChoice();
};

}  // namespace s21

#endif  // MAZE_H_
