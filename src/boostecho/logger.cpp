// \file log.cpp
//
// \par Copyright
// Copyright (C) 1999-2021 Geoffrey Davis
// All rights reserved.
//
// \author Geoffrey Davis <contact@geoffreydavis.com>

#define _BOOSTECHO_LOGGER_CPP_

#include <boostecho/boostecho.hpp>
#include <boostecho/logger.hpp>

namespace boostecho {
namespace utility {

//! The logger level filter.
logger::severity logger::m_severity_filter = logger::debug;

//! Default constructor.
//! \param p_severity the severity of the logger
logger::logger(const severity& p_severity) :
	m_buffer(),
	m_severity(p_severity),
	m_source_filename(),
	m_source_line() {
    // Nothing.
}

//! Destructor.
logger::~logger() noexcept {
  if (m_severity < m_severity_filter)
    return;

  // Print current time.
  auto now = std::chrono::system_clock::now();
  auto nowc = std::chrono::system_clock::to_time_t(now);
  auto nowtm = std::localtime(&nowc);
  std::cout << std::put_time(nowtm, "%F %T") << " ";

  // Print logger severity.
  switch (m_severity) {
  case logger::debug:		std::cout << "<D> "; break;
  case logger::information:	std::cout << "<I> "; break;
  case logger::warning:		std::cout << "<W> "; break;
  case logger::error:		std::cout << "<E> "; break;
  default:			std::cout << "<~> "; break;
  }

  // Print message.
  if (m_buffer.str().size())
    std::cout << m_buffer.str() << ' ';

  // Print filename and line number.
  if (m_source_filename && *m_source_filename != '\0' && m_source_line)
    std::cout << "{" << m_source_filename << ":" << m_source_line << "}";

  // Flush logger.
  std::cout << std::endl;
}

}; // namespace utility
}; // namespace boostecho
