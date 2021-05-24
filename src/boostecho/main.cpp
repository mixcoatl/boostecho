// \file main.cpp
//
// \par Copyright
// Copyright (C) 1999-2021 Geoffrey Davis
// All rights reserved.
//
// \author Geoffrey Davis <contact@geoffreydavis.com>

#define _BOOSTECHO_MAIN_CPP_

#include <boostecho/application.hpp>
#include <boostecho/boostecho.hpp>
#include <boostecho/logger.hpp>

//! Program entry point.
// \param argc the number of command line arguments
// \param argv an array containing the command line arguments
// \return zero for normal program termination; non-zero otherwise
int main(int argc, const char** argv) {
  // Startup message.
  LOGGER_INFORMATION() << "Starting " << PACKAGE_STRING << '!';

  // Configure application.
  auto application = std::make_shared<boostecho::core::application>();
  application->parse_arguments(argc, argv);

  // Run application.
  application->run();

  return EXIT_SUCCESS;
}
