#include "log.hpp"


std::string JADE::LOGGER::to_string(std::source_location const source)
{
  return fmt::format("{} : {} : {}", 
    std::filesystem::path(source.file_name()).filename().string(), 
    source.function_name(),
    source.line());
}


std::string JADE::LOGGER::to_string(auto tp)
{
  std::time_t now = std::chrono::system_clock::to_time_t(tp);
  return fmt::format("{}", std::ctime(&now));
}


void JADE::LOGGER::print(
  JADE::LOGGER::LOG_LEVEL const level,
  std::string_view const message,
  std::source_location const source)
{
  fmt::print(
    "[{}] {} | {} | {}",
    static_cast<char>(level),
    JADE::LOGGER::to_string(source),
    message,
    JADE::LOGGER::to_string(std::chrono::system_clock::now()));
}
