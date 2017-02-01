#ifndef POINCARE_NTH_ROOT_H
#define POINCARE_NTH_ROOT_H

#include <poincare/function.h>

class NthRoot : public Function {
public:
  NthRoot();
  float approximate(Context & context, AngleUnit angleUnit = AngleUnit::Radian) const override;
  Type type() const override;
  Expression * cloneWithDifferentOperands(Expression ** newOperands,
    int numberOfOperands, bool cloneOperands = true) const override;
  ExpressionLayout * createLayout(DisplayMode displayMode = DisplayMode::Auto) const override;
};

#endif
