#ifndef __JADE_UNIT_TEST__
#define __JADE_UNIT_TEST__

#include "log.hpp"
#include <typeinfo>

namespace JADE
{
  class UnitTestBase
  {
    public:
      UnitTestBase();
      ~UnitTestBase();

      template<typename T1, typename T2>
      static bool compare_type(const T1 &t1, const T2 &t2)
      {
        if (typeid(T1) != typeid(T2))
        {
          return false;
        }

        return true;
      }

      template<typename T>
      static bool compare_value(const T t1, const T t2)
      {
        if (t1 == t2)
        {
          return true;
        }
        return false;
      }
      
    public:
      virtual  void run();
  };
}

#endif