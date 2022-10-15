#include "log.hpp"


std::string JADE::LOGGER::to_string(std::source_location const source)
{
  return fmt::format("{} : {} : {}", 
    std::filesystem::path(source.file_name()).filename().string(), 
    source.function_name(),
    fmt::styled(source.line(), fmt::fg(fmt::color::aqua)));
}


std::string JADE::LOGGER::to_string(auto tp)
{
  return fmt::format("{:%F %T %Z}", tp);
}


void JADE::LOGGER::print(
  JADE::LOGGER::LOG_LEVEL const level,
  std::string_view const message,
  std::source_location const source)
{
  if (level == JADE::LOGGER::LOG_LEVEL::Info)
  {
    fmt::print(
      "[{}] {} | {} | {}\n",
      fmt::styled(static_cast<char>(level),fmt::fg(fmt::color::blue_violet) | fmt::emphasis::bold),
      JADE::LOGGER::to_string(source),
      JADE::LOGGER::to_string(std::chrono::system_clock::now()),
      fmt::styled(message, fmt::fg(fmt::color::green)));

    return;
  }

  else if (level == JADE::LOGGER::LOG_LEVEL::Warning)
  {
    fmt::print(
      "[{}] {} | {} | {}\n",
      fmt::styled(static_cast<char>(level),fmt::fg(fmt::color::yellow) | fmt::emphasis::bold),
      JADE::LOGGER::to_string(source),
      JADE::LOGGER::to_string(std::chrono::system_clock::now()),
      fmt::styled(message, fmt::fg(fmt::color::green)));

  }

  else if (level == JADE::LOGGER::LOG_LEVEL::Error)
  {
    fmt::print(
      "[{}] {} | {} | {}\n",
      fmt::styled(static_cast<char>(level),fmt::fg(fmt::color::red) | fmt::emphasis::bold),
      JADE::LOGGER::to_string(source),
      JADE::LOGGER::to_string(std::chrono::system_clock::now()),
      fmt::styled(message, fmt::fg(fmt::color::green)));

  }
}
