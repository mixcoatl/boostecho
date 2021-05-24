// \file logger.hpp
//
// \par Copyright
// Copyright (C) 1999-2021 Geoffrey Davis
// All rights reserved.
//
// \author Geoffrey Davis <contact@geoffreydavis.com>

#ifndef _BOOSTECHO_LOGGER_HPP_
#define _BOOSTECHO_LOGGER_HPP_

#include <boostecho/boostecho.hpp>

namespace boostecho {
namespace utility {

//! The logger class. \{
class logger {
public:
    //! The logger severities. \{
    enum severity {
	debug,		//!< Debugging messages.
	information,	//!< Informational messages.
	warning,	//!< Warning messages.
	error		//!< Error messages.
    };
    //! \}

    //! Default constructor.
    //! \param p_severity the severity of the logger
    logger(const severity& p_severity = debug);

    //! Destructor.
    ~logger() noexcept;

    //! Writes to the logger.
    //! \param p_value the value to write to the logger
    //! \return a reference to this logger
    template<class type>
    logger& operator<<(const type& p_value) noexcept {
	if (m_severity >= m_severity_filter)
	    m_buffer << p_value;
	return *this;
    }

    //! Returns the logger severity filter.
    //! \sa #set_severity_filter(const severity&)
    static severity get_severity_filter() noexcept {
	return m_severity_filter;
    }

    //! Sets the logger severity filter.
    //! \param p_severity_filter the new severity filter value
    //! \sa #get_severity_filter() const
    static void set_severity_filter(
	const severity& p_severity_filter) noexcept {
	m_severity_filter = p_severity_filter;
    }

    //! Sets the source location.
    //! \param p_source_filename the source filename
    //! \param p_source_line the source line
    //! \return a reference to this logger
    logger& set_source_location(
	const char *p_source_filename,
	const int p_source_line) {
	m_source_filename = p_source_filename;
	m_source_line = p_source_line;
	return *this;
    }

protected:
    //! The message buffer.
    std::ostringstream m_buffer;

    //! The logger severity.
    severity m_severity;

    //! The logger severity filter.
    //! \sa #get_severity_filter() const
    //! \sa #set_severity_filter(const severity&)
    static severity m_severity_filter;

    //! The source filename.
    const char* m_source_filename;

    //! The source line.
    int m_source_line;
};
//! \}

}; // namespace utility
}; // namespace boostecho

//! Constructs a logger.
//! \param p_logger the severity of the logger
#define LOGGER(p_severity) \
    boostecho::utility::logger(p_severity).set_source_location(__FILE__, __LINE__)

//! Logger shortcuts. \{
#define LOGGER_DEBUG()		LOGGER(boostecho::utility::logger::debug)
#define LOGGER_ERROR()		LOGGER(boostecho::utility::logger::error)
#define LOGGER_INFORMATION()	LOGGER(boostecho::utility::logger::information)
#define LOGGER_WARNING()	LOGGER(boostecho::utility::logger::warning)
//! \}

#endif // _BOOSTECHO_LOGGER_HXX_
