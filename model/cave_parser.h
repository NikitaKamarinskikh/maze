#ifndef CAVE_PARSER_H_
#define CAVE_PARSER_H_

#include <fstream>
#include <sstream>

#include "cave_cell.h"
#include "exceptions.h"
#include "matrix.h"

namespace s21 {

class CaveParser {
 public:
  s21::Matrix<s21::CaveCell> ExtractCaveFromFile(const std::string file_path);

 private:
  std::pair<int, int> ParseCaveSizes(std::string str);
  bool IsDigit(const std::string str) const;
};

}  //  namespace s21

#endif  // CAVE_PARSER_H_
