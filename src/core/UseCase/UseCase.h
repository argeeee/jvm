#pragma once

template <typename ReturnType, typename ParamsType>
class UseCase {
 public:
  virtual ReturnType operator()(const ParamsType& param) = 0;
};
