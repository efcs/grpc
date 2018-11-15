#include <cxxabi.h>
#include <iostream>

struct Foo {
  virtual void foo() = delete;
  virtual void bar() = 0;
  virtual ~Foo() {}
};


struct Bar : Foo {
  virtual void foo() = delete;
  virtual void bar() {}
};

volatile Foo *sink;

using FnT = void(*)();
volatile FnT fn_sink;

bool my_test(Foo *f) {
  std::cout << "here\n";
  sink = f;
  fn_sink = &__cxxabiv1::__cxa_rethrow;
  return fn_sink != nullptr;
}
