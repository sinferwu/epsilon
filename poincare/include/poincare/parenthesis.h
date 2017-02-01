#ifndef POINCARE_PARENTHESIS_H
#define POINCARE_PARENTHESIS_H

#include <poincare/expression.h>

class Parenthesis : public Expression {
  public:
    Parenthesis(Expression * operand, bool cloneOperands = true);
    ~Parenthesis();
    const Expression * operand(int i) const override;
    int numberOfOperands() const override;
    Expression * clone() const override;
    ExpressionLayout * createLayout(DisplayMode displayMode = DisplayMode::Auto) const override;
    float approximate(Context& context, AngleUnit angleUnit = AngleUnit::Radian) const override;
    Expression * evaluate(Context& context, AngleUnit angleUnit = AngleUnit::Radian) const override;
    Type type() const override;
    Expression * cloneWithDifferentOperands(Expression** newOperands,
        int numnerOfOperands, bool cloneOperands = true) const override;
  protected:
    Expression * m_operand;
};

#endif
