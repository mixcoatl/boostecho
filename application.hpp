// \file application.hpp
//
// \par Copyright
// Copyright (C) 1999-2021 Geoffrey Davis
// All rights reserved.
//
// \author Geoffrey Davis <contact@geoffreydavis.com>

#ifndef _BOOSTECHO_APPLICATION_HPP_
#define _BOOSTECHO_APPLICATION_HPP_

#include <boostecho/boostecho.hpp>

namespace boostecho {
namespace core {

//! The application class. \{
class application {
public:
    //! Default constructor.
    application();

    //! Destructor.
    virtual ~application() noexcept;

    //! Runs the application.
    virtual void run();

    //! Returns the shutdown flag.
    //! \sa #set_shutdown(const bool)
    bool get_shutdown() const noexcept {
	return m_shutdown;
    }

    //! Parses command line arguments.
    //! \param argv an array containing the command line arguments
    //! \param argc the number of command line arguments
    void parse_arguments(
	const int argc,
	const char **argv);

    //! Sets the shutdown flag.
    //! \param p_shutdown the new shutdown flag value
    //! \sa #get_shutdown() const
    void set_shutdown(const bool p_shutdown) noexcept {
	m_shutdown = p_shutdown;
    }

protected:
    //! The shutdown flag.
    //! \sa #get_shutdown() const
    //! \sa #set_shutdown(const bool)
    bool m_shutdown;
};
//! \}

}; // namespace core
}; // namespace boostecho

#endif // _BOOSTECHO_APPLICATION_HXX_
