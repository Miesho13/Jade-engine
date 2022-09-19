/* 
  @author Miesho
  @brief logger class 
*/

#ifndef __JADE_LOGGER_INC__
#define __JADE_LOGGER_INC__ 


#include <iostream>
#include <string>


namespace JADE
{
  class LOGGER
  {

    public:
      static void print()
      {
        std::cout << '\n';
      }
      template<typename T1, typename ... T2>
      static void print(const T1& t1, const T2 ...t2)
      {
        std::cout << t1;
        print(t2...);
      }
  };
}

#endif