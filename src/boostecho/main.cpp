// \file main.cpp
//
// \par Copyright
// Copyright (C) 1999-2021 Geoffrey Davis
// All rights reserved.
//
// \author Geoffrey Davis <contact@geoffreydavis.com>

#define _BOOSTECHO_MAIN_CPP_

#include <boostecho/boostecho.hpp>
#include <boostecho/logger.hpp>

//! Program entry point.
// \param argc the number of command line arguments
// \param argv an array containing the command line arguments
// \return zero for normal program termination; non-zero otherwise
int main(int argc, const char** argv) {
  LOGGER_INFORMATION() << "Starting " << PACKAGE_STRING << '!';
  return EXIT_SUCCESS;
}
