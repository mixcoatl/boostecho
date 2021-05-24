// \file client.cpp
//
// \par Copyright
// Copyright (C) 1999-2021 Geoffrey Davis
// All rights reserved.
//
// \author Geoffrey Davis <contact@geoffreydavis.com>

#define _BOOSTECHO_CLIENT_CPP_

#include <boostecho/application.hpp>
#include <boostecho/boostecho.hpp>
#include <boostecho/client.hpp>
#include <boostecho/logger.hpp>

namespace boostecho {
namespace net {

// More boost types.
using error_code_type = boost::system::error_code;

//! Constructor.
//! \param p_application the application state
//! \param p_socket the network socket
client::client(
	application_type& p_application,
	socket_type&& p_socket) :
	m_application(p_application),
	m_socket(std::move(p_socket)) {
    // Setup asynchronous read.
    this->perform_read();
}

//! Destructor.
client::~client() noexcept {
    // Nothing.
}

//! Closes the client.
void client::close() noexcept {
    // Nothing.
}

//! Writes to the client.
//! \param p_message the message to write
void client::send(const std::string& p_message) {
    // Nothing to write.
    if (p_message.length() == 0)
	return;

    // Post message.
    boost::asio::post(m_application.get_io_context(),
	[this, p_message]() {
	    // Are we writing right now?
	    const bool in_progress = !m_output_queue.empty();

	    // Add message to output queue.
	    m_output_queue.push_back(p_message);

	    // Setup asynchronous write.
	    if (!m_application.get_shutdown() && !in_progress)
		this->perform_write();
	});
}

//! Sets up the socket's asynchronous read.
void client::perform_read() {
    boost::asio::async_read_until(
	m_socket, m_input, '\n',
	[this](const error_code_type &error_code, std::size_t bytes_received) {
	    switch (error_code.value()) {
	    case boost::system::errc::success:
		this->perform_read_line();
		this->perform_read();
		break;
	    case boost::asio::error::eof:
		LOGGER_INFORMATION() << "Client " << m_socket.remote_endpoint() << " disconnected.";
		m_socket.close();
		break;
	    default:
		// Write a warning message if we failed.
		LOGGER_WARNING() << "Error reading socket.";
		LOGGER_WARNING() << " >> " << error_code;
		LOGGER_WARNING() << " >> " << error_code.message();
		m_socket.close();
		break;
	    }
	});
}

//! Reads from the client's input buffer.
void client::perform_read_line() {
    // Contains user input.
    std::string line;

    // Use istream to read from buffer.
    std::istream input(&m_input);
    std::getline(input, line);

    // Advance stream buffer.
    m_input.consume(line.length());

    // Remove carriage returns from user input.
    line.erase(std::remove(line.begin(), line.end(), '\r'), line.end() );

    // Write user input to log for now.
    *this << line << "\r\n";
    LOGGER_INFORMATION() << "Client " << m_socket.remote_endpoint() << " - " << line;
}

//! Sets up the socket's asynchronous write.
void client::perform_write() {
    std::string& message = m_output_queue.front();
    boost::asio::async_write(m_socket, boost::asio::buffer(message),
	[this, message](error_code_type error_code, std::size_t /* length */) {
	    if (!error_code) {
		m_output_queue.pop_front();
		if (!m_output_queue.empty())
		    this->perform_write();
	    } else {
		// Write a warning message if we failed.
		LOGGER_WARNING() << "Error writing socket.";
		LOGGER_WARNING() << " >> " << error_code;
		LOGGER_WARNING() << " >> " << error_code.message();
		m_socket.close();
	    }
	});
}

}; // namespace net
}; // namespace boostecho
