// \file application.cpp
//
// \par Copyright
// Copyright (C) 1999-2021 Geoffrey Davis
// All rights reserved.
//
// \author Geoffrey Davis <contact@geoffreydavis.com>

#define _BOOSTECHO_APPLICATION_CPP_

#include <boostecho/application.hpp>
#include <boostecho/boostecho.hpp>
#include <boostecho/logger.hpp>
#include <boostecho/server.hpp>

namespace boostecho {
namespace core {

//! Default constructor.
application::application() :
	m_io_context(),
	m_server(*this),
	m_clients(),
	m_shutdown(false) {
    // Nothing.
}

//! Destructor.
application::~application() noexcept {
    // Nothing.
}

//! Parses command line arguments.
//! \param argv an array containing the command line arguments
//! \param argc the number of command line arguments
void application::parse_arguments(
	const int argc,
	const char **argv) {
    // Nothing.
}

//! Runs the application.
void application::run() {
    // Configure server.
    m_server.start_acceptor(6767);

    // Now run event loop.
    LOGGER_INFORMATION() << "Starting event loop.";
    while (!m_shutdown) {
	// The IO context stops when it runs out of
	// work or when it services one its handlers.
	// Restart the context just in case.
	m_io_context.restart();

	// Run the IO context.
	if (!m_shutdown)
	    m_io_context.run();
    }

    // We seem to be done for now.
    LOGGER_INFORMATION() << "Application completed normally.";
}

}; // namespace core
}; // namespace boostecho
