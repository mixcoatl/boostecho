// \file server.cpp
//
// \par Copyright
// Copyright (C) 1999-2021 Geoffrey Davis
// All rights reserved.
//
// \author Geoffrey Davis <contact@geoffreydavis.com>

#define _BOOSTECHO_SERVER_CPP_

#include <boostecho/application.hpp>
#include <boostecho/boostecho.hpp>
#include <boostecho/logger.hpp>
#include <boostecho/server.hpp>

namespace boostecho {
namespace net {

// More boost types.
using error_code_type = boost::system::error_code;
using resolver_type = boost::asio::ip::tcp::resolver;
using resolver_iterator_type = boost::asio::ip::tcp::resolver::iterator;
using resolver_query_type = boost::asio::ip::tcp::resolver::query;

//! Constructor.
//! \param p_application the application state
server::server(application_type& p_application) :
	m_application(p_application),
	m_acceptor(p_application.get_io_context()) {
    // Nothing.
}

//! Destructor.
server::~server() noexcept {
    // Nothing.
}

//! Closes the server.
void server::close() noexcept {
    // Close the acceptor.
    error_code_type error_code;
    m_acceptor.close(error_code);

    if (error_code) {
	// Write a warning message if we failed.
	LOGGER_WARNING() << "Error closing acceptor.";
	LOGGER_WARNING() << " >> " << error_code;
	LOGGER_WARNING() << " >> " << error_code.message();
    }
}

//! Starts the acceptor and begins to accept connections.
//! \param p_port the network port upon which to listen
//! \param p_address the network address to bind
void server::start_acceptor(
	const std::uint16_t p_port,
	const std::string& p_address) {
    // Resolve the TCP endpoint.
    // These operations throw if name resolution fails.
    resolver_type resolver(m_application.get_io_context());
    resolver_query_type query(p_address, std::to_string(p_port));
    resolver_iterator_type iter = resolver.resolve(query);

    // Start the acceptor.
    this->start_acceptor(iter->endpoint());
}

//! Starts the acceptor and begins to accept connections.
//! \param p_endpoint the network endpoint
void server::start_acceptor(const endpoint_type& p_endpoint) {
    // Configure the acceptor.
    m_acceptor.open(p_endpoint.protocol());
    m_acceptor.bind(p_endpoint);
    m_acceptor.listen();

    LOGGER_INFORMATION() << "Server listening on " << m_acceptor.local_endpoint() << ".";

    // Begin accepting connections.
    this->perform_accept();
}

//! Sets up the acceptors asynchronous accept call.
void server::perform_accept() {
    m_acceptor.async_accept(
	[this](boost::system::error_code ec, socket_type socket) {
	    LOGGER_INFORMATION() << "Received connection from " << socket.remote_endpoint() << ".";
	    m_application.get_clients().emplace_back(m_application, std::move(socket));
	    perform_accept();
	});
}

}; // namespace net
}; // namespace boostecho
