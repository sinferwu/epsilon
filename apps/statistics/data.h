#ifndef STATISTICS_DATA_H
#define STATISTICS_DATA_H

#include "../curve_view_window.h"

namespace Statistics {

class Data : public CurveViewWindow {
public:
  Data();
  // Delete the implicit copy constructor: the object is heavy
  Data(const Data&) = delete;

  // Raw numeric data
  int numberOfPairs() const;
  float valueAtIndex(int index);
  int sizeAtIndex(int index);
  void setValueAtIndex(float value, int index);
  void setSizeAtIndex(int size, int index);
  void deletePairAtIndex(int index);
  int totalSize();

  // Histogram bars
  float barWidth();
  void setBarWidth(float barWidth);
  float barStart();
  void setBarStart(float barStart);
  int heightForBarAtValue(float value);
  float selectedBar();
  bool selectNextBarToward(int direction);

  //CurveViewWindow
  float xMin() override;
  // if the range of value is to wide compared to the bar width, value max is capped
  float xMax() override;
  float yMin() override;
  float yMax() override;
  float xGridUnit() override;

  // TODO: decide the max number of elements after optimization
  constexpr static int k_maxNumberOfPairs = 500;
private:
  constexpr static int k_maxNumberOfBarsPerWindow = 300;
  constexpr static float k_marginFactor = 0.2f;
  float sumOfValuesBetween(float x1, float x2);
  float maxValue();
  float minValue();
  bool scrollToSelectedBar();
  void initBarParameters();
  void initWindowParameters();
  // Raw numeric data
  int m_sizes[k_maxNumberOfPairs];
  float m_values[k_maxNumberOfPairs];
  int m_numberOfPairs;
  // Histogram bars
  float m_barWidth;
  float m_selectedBar;
  float m_barStart;
  // Window bounds of the data
  float m_xMin;
  float m_xMax;
  float m_yMax;
  float m_xGridUnit;
};

}

#endif