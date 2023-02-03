#pragma once

template <typename ReturnType, typename ParamsType>
class UseCase {
 public:
  UseCase() { }
  virtual ~UseCase() { }

  virtual ReturnType operator()(const ParamsType& param) { }
};
