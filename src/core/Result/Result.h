#pragma once

// TODO: to change
template<typename T>
class Result {
 public:
  Result(const T& value) : value_(value), has_value_(true) {}
  Result(const char* error) : error_(error), has_value_(false) {}

  bool HasValue() const { return has_value_; }
  const T& Value() const { return value_; }
  const char* Error() const { return error_; }

 private:
  union
  {
    T value_;
    const char* error_;
  };
  bool has_value_;
};
