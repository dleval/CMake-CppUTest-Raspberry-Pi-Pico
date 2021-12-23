#include "CppUTest/TestHarness.h"

extern "C"
{
  #include "module.h"
}

TEST_GROUP(module)
{
  void setup()
  {
    
  }

  void teardown() 
  {
    
  }
};

TEST(module, LedsAreOffAfterCreate)
{
  bool val = toggleGPIO();
  CHECK(val);
  val = toggleGPIO();
  CHECK(!val);
  val = toggleGPIO();
  CHECK(val);
}
