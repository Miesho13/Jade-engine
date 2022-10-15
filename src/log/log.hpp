/* 
  @author Miesho
  @brief logger class 
*/

#ifndef __JADE_LOGGER_INC__
#define __JADE_LOGGER_INC__ 


#include <iostream>
#include <string>
#include <chrono>
#include <source_location>
#include <filesystem>

#include "fmt/core.h"
#include "fmt/chrono.h"
#include "fmt/color.h"

namespace JADE
{


  class LOGGER
  {
    public:
      enum class LOG_LEVEL : char
      {
        Info = 'I',
        Warning = 'W',
        Error = 'E'
      };

    public:

      static void print(
        LOG_LEVEL const level,
        std::string_view const message,
        std::source_location const source = std::source_location::current());

    private:
      static auto as_local(std::chrono::system_clock::time_point const tp);
      static std::string to_string(std::source_location const source);
      static std::string to_string(auto tp);
      
  };
}

#endif