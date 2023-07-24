#ifndef CAVE_CELL_H_
#define CAVE_CELL_H_

#include "cell.h"

namespace s21 {

enum class CaveCellStates : int8_t { kDead = 0, kAlive };

class CaveCell : public Cell {
 public:
  using reference = CaveCell&;
  using const_rederence = const CaveCell&;
  using size_type = unsigned int;

 private:
  CaveCellStates state_;

 public:
  // Functions
  bool IsAlive() const;
  bool IsDead() const;

  void Die();
  void Reborn();

  void Reset();
};

}  // namespace s21

#endif  // CAVE_CELL_H_
