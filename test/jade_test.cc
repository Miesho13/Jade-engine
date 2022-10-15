/*
 * @author Miesho
 * @date 22.09.2020
 * @brief ...
 */

#include "log.hpp"

int main()
{
  JADE::LOGGER::print(JADE::LOGGER::LOG_LEVEL::Info, "Logg message");
  JADE::LOGGER::print(JADE::LOGGER::LOG_LEVEL::Warning, "Logg message");
  JADE::LOGGER::print(JADE::LOGGER::LOG_LEVEL::Error, "Logg message");

}