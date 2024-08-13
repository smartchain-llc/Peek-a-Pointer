#include <gtest/gtest.h>
#include <sstream>
#include <string_view>
#include <iostream>

struct Inspector{
  template<typename T>
  std::string inspect(const T& t){
    std::stringstream ss;
    ss << "T:\n\tSize: " << sizeof(t) << "\n";   
    return ss.str();
  }

};

struct TestUDT {
  uint64_t i { 0 };
};

TEST(InspectorTest, AcceptsAnyPrimitives){
  Inspector ins;
  TestUDT udt;
  std::cout << ins.inspect(udt);
  ASSERT_TRUE(true);
}