// \file client.hpp
//
// \par Copyright
// Copyright (C) 1999-2021 Geoffrey Davis
// All rights reserved.
//
// \author Geoffrey Davis <contact@geoffreydavis.com>

#ifndef _BOOSTECHO_CLIENT_HPP_
#define _BOOSTECHO_CLIENT_HPP_

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
using endpoint_type = boost::asio::ip::tcp::endpoint;
using socket_type = boost::asio::ip::tcp::socket;
using streambuf_type = boost::asio::streambuf;

// Some boostecho types.
using application_type = boostecho::core::application;

//! The client class. \{
class client {
public:
    //! Constructor.
    //! \param p_application the application state
    //! \param p_socket the network socket
    client(
	application_type& p_application,
	socket_type&& p_socket);

    //! Destructor.
    virtual ~client() noexcept;

    //! Closes the client.
    void close() noexcept;

    //! Returns the socket.
    socket_type& get_socket() noexcept {
	return m_socket;
    }

    //! Returns the application state.
    application_type& get_application() noexcept {
	return m_application;
    }

    //! Writes to the client.
    //! \param p_value the value to write
    //! \sa #send(const std::string&)
    template<class type>
    client& operator<<(const type& p_value) {
	this->send(boost::lexical_cast<std::string>(p_value));
	return *this;
    }

    //! Writes to the client.
    //! \param p_message the message to write
    void send(const std::string& p_message);

protected:
    //! The application state.
    //! \sa #get_application()
    application_type& m_application;

    //! The socket.
    //! \sa #get_socket()
    socket_type m_socket;

    //! The input buffer.
    streambuf_type m_input;

    //! The output queue.
    std::deque<std::string> m_output_queue;

    //! Sets up the socket's asynchronous read.
    void perform_read();

    //! Reads from the client's input buffer.
    void perform_read_line();

    //! Sets up the socket's asynchronous write.
    void perform_write();
};
//! \}

}; // namespace net
}; // namespace boostecho

#endif // _BOOSTECHO_CLIENT_HXX_
