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

namespace boostecho {
namespace core {

//! Default constructor.
application::application() :
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
    // Nothing.
}

}; // namespace core
}; // namespace boostecho
