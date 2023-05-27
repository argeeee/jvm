#pragma once

template <typename ReturnType, typename ParamsType>
class UseCase {
 public:
  UseCase() { }
  virtual ~UseCase() { }

  virtual ReturnType operator()(const ParamsType& param) {
    // TODO: to fix warning (non-void function does not return a value [-Wreturn-type]) 
  }
};
