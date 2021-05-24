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
#include <boostecho/client.hpp>
#include <boostecho/server.hpp>

namespace boostecho {
namespace core {

// BoostEcho types.
using client_type = boostecho::net::client;
using server_type = boostecho::net::server;

//! The application class. \{
class application {
public:
    //! The type of an IO context.
    typedef boost::asio::io_context io_context_type;

    //! Default constructor.
    application();

    //! Destructor.
    virtual ~application() noexcept;

    //! Returns the client list.
    std::list<client_type>& get_clients() noexcept {
        return m_clients;
    }

    //! Returns the IO context.
    io_context_type& get_io_context() noexcept {
        return m_io_context;
    }

    //! Returns the server component.
    server_type& get_server() noexcept {
	return m_server;
    }

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

    //! Runs the application.
    virtual void run();

    //! Sets the shutdown flag.
    //! \param p_shutdown the new shutdown flag value
    //! \sa #get_shutdown() const
    void set_shutdown(const bool p_shutdown) noexcept {
	m_shutdown = p_shutdown;
    }

protected:
    //! The IO context.
    //! \sa #get_io_context()
    io_context_type m_io_context;

    //! The server component.
    //! \sa #get_server()
    server_type m_server;

    //! The client list.
    //! \sa #get_clients()
    std::list<client_type> m_clients;

    //! The shutdown flag.
    //! \sa #get_shutdown() const
    //! \sa #set_shutdown(const bool)
    bool m_shutdown;
};
//! \}

}; // namespace core
}; // namespace boostecho

#endif // _BOOSTECHO_APPLICATION_HXX_
