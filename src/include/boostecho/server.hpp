// \file server.hpp
//
// \par Copyright
// Copyright (C) 1999-2021 Geoffrey Davis
// All rights reserved.
//
// \author Geoffrey Davis <contact@geoffreydavis.com>

#ifndef _BOOSTECHO_SERVER_HPP_
#define _BOOSTECHO_SERVER_HPP_

#include <boostecho/boostecho.hpp>

// Forward declarations.
namespace boostecho {
namespace core {
class application;
}; // namespace core
}; // namespace boostecho

namespace boostecho {
namespace net {

// Some boost types.
using acceptor_type = boost::asio::ip::tcp::acceptor;
using endpoint_type = boost::asio::ip::tcp::endpoint;
using socket_type = boost::asio::ip::tcp::socket;

// Some boostecho types.
using application_type = boostecho::core::application;

//! The server class. \{
class server {
public:
    //! Constructor.
    //! \param p_application the application state
    server(application_type& p_application);

    //! Destructor.
    virtual ~server() noexcept;

    //! Closes the server.
    void close() noexcept;

    //! Returns the acceptor.
    acceptor_type& get_acceptor() noexcept {
        return m_acceptor;
    }

    //! Returns the application state.
    application_type& get_application() noexcept {
	return m_application;
    }

    //! Starts the acceptor and begins to accept connections.
    //! \param p_port the network port upon which to listen
    //! \param p_address the network address to bind
    void start_acceptor(
	const std::uint16_t p_port,
	const std::string& p_address = std::string());

    //! Starts the acceptor and begins to accept connections.
    //! \param p_endpoint the network endpoint
    void start_acceptor(const endpoint_type& p_endpoint);

protected:
    //! The application state.
    //! \sa #get_application()
    application_type& m_application;

    //! The acceptor.
    //! \sa #get_acceptor()
    acceptor_type m_acceptor;

    //! Sets up the acceptors asynchronous accept call.
    void perform_accept();
};
//! \}

}; // namespace net
}; // namespace boostecho

#endif // _BOOSTECHO_SERVER_HXX_
