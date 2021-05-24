// \file boostecho.hpp
//
// \par Copyright
// Copyright (C) 1999-2021 Geoffrey Davis
// All rights reserved.
//
// \author Geoffrey Davis <contact@geoffreydavis.com>

#ifndef _BOOSTECHO_BOOSTECHO_HPP_
#define _BOOSTECHO_BOOSTECHO_HPP_

#include "../config.hpp"

#ifdef HAVE_ALGORITHM
#include <algorithm>
#endif // HAVE_ALGORITHM

#ifdef HAVE_ANY
#include <any>
#endif // HAVE_ANY

#ifdef HAVE_ARPA_INET_H
#include <arpa/inet.h>
#endif // HAVE_ARPA_INET_H

#ifdef HAVE_ARPA_TELNET_H
#include <arpa/telnet.h>
#endif // HAVE_ARPA_TELNET_H

#ifdef HAVE_ATOMIC
#include <atomic>
#endif // HAVE_ATOMIC

#ifdef HAVE_BITSET
#include <bitset>
#endif // HAVE_BITSET

#ifdef HAVE_BOOST_ALGORITH_STRING_HPP
#include <boost/algorithm/string.hpp>
#endif // HAVE_BOOST_ALGORITH_STRING_HPP

#ifdef HAVE_BOOST_ASIO_HPP
#include <boost/asio.hpp>
#endif // HAVE_BOOST_ASIO_HPP

#ifdef HAVE_BOOST_CHRONO_HPP
#include <boost/chrono.hpp>
#endif // HAVE_BOOST_CHRONO_HPP

#ifdef HAVE_BOOST_LEXICAL_CAST_HPP
#include <boost/lexical_cast.hpp>
#endif // HAVE_BOOST_LEXICAL_CAST_HPP

#ifdef HAVE_BOOST_NONCOPYABLE_HPP
#include <boost/noncopyable.hpp>
#endif // HAVE_BOOST_NONCOPYABLE_HPP

#ifdef HAVE_BOOST_RANDOM_HPP
#include <boost/random.hpp>
#endif // HAVE_BOOST_RANDOM_HPP

#ifdef HAVE_BOOST_SYSTEM_ERROR_CODE_HPP
#include <boost/system/error_code.hpp>
#endif // HAVE_BOOST_SYSTEM_ERROR_CODE_HPP

#ifdef HAVE_CHRONO
#include <chrono>
#endif // HAVE_CHRONO

#ifdef HAVE_CRYPT_H
#include <crypt.h>
#endif // HAVE_CRYPT_H

#ifdef HAVE_CCTYPE
#include <cctype>
#endif // HAVE_CCTYPE

#ifdef HAVE_CERRNO
#include <cerrno>
#endif // HAVE_CERRNO

#ifdef HAVE_CMATH
#include <cmath>
#endif // HAVE_CMATH

#ifdef HAVE_CSIGNAL
#include <csignal>
#endif // HAVE_CSIGNAL

#ifdef HAVE_CSTDARG
#include <cstdarg>
#endif // HAVE_CSTDARG

#ifdef HAVE_CSTDBOOL
#include <cstdbool>
#endif // HAVE_CSTDBOOL

#ifdef HAVE_CSTDDEF
#include <cstddef>
#endif // HAVE_CSTDDEF

#ifdef HAVE_CSTRING
#include <cstring>
#endif // HAVE_CSTRING

#ifdef HAVE_CTIME
#include <ctime>
#endif // HAVE_CTIME

#ifdef HAVE_DIRENT_H
#include <dirent.h>
#endif // HAVE_DIRENT_H

#ifdef HAVE_DLFCN_H
#include <dlfcn.h>
#endif // HAVE_DLFCN_H

#ifdef HAVE_FCNTL_H
#include <fcntl.h>
#endif // HAVE_FCNTL_H

#ifdef HAVE_FILESYSTEM
#include <filesystem>
#endif // HAVE_FILESYSTEM

#ifdef HAVE_FSTREAM
#include <fstream>
#endif // HAVE_FSTREAM

#ifdef HAVE_FUNCTIONAL
#include <functional>
#endif // HAVE_FUNCTIONAL

#ifdef HAVE_IOMANIP
#include <iomanip>
#endif // HAVE_IOMANIP

#ifdef HAVE_IOSTREAM
#include <iostream>
#endif // HAVE_IOSTREAM

#ifdef HAVE_ITERATOR
#include <iterator>
#endif // HAVE_ITERATOR

#ifdef HAVE_LIMITS
#include <limits>
#endif // HAVE_LIMITS

#ifdef HAVE_LIST
#include <list>
#endif // HAVE_LIST

#ifdef HAVE_MAP
#include <map>
#endif // HAVE_MAP

#ifdef HAVE_MEMORY
#include <memory>
#endif // HAVE_MEMORY

#ifdef HAVE_NETDB_H
#include <netdb.h>
#endif // HAVE_NETDB_H

#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif // HAVE_NETINET_IN_H

#ifdef HAVE_OPTIONAL
#include <optional>
#endif // HAVE_OPTIONAL

#ifdef HAVE_REGEX
#include <regex>
#endif // HAVE_REGEX

#ifdef HAVE_SET
#include <set>
#endif // HAVE_SET

#ifdef HAVE_STDEXCEPT
#include <stdexcept>
#endif // HAVE_STDEXCEPT

#ifdef HAVE_SSTREAM
#include <sstream>
#endif // HAVE_SSTREAM

#ifdef HAVE_STRING
#include <string>
#endif // HAVE_STRING

#ifdef HAVE_STRING_VIEW
#include <string_view>
#endif // HAVE_STRING_VIEW

#ifdef HAVE_SYS_SOCKET_H
#include <sys/socket.h>
#endif // HAVE_SYS_SOCKET_H

#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif // HAVE_SYS_TIME_H

#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif // HAVE_SYS_TYPES_H

#ifdef HAVE_THREAD
#include <thread>
#endif // HAVE_THREAD

#ifdef HAVE_TIME_H
#include <time.h>
#endif // HAVE_TIME_H

#ifdef HAVE_TYPE_TRAITS
#include <type_traits>
#endif // HAVE_TYPE_TRAITS

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif // HAVE_UNISTD_H

#ifdef HAVE_UTILITY
#include <utility>
#endif // HAVE_UTILITY

#ifdef HAVE_VARIANT
#include <variant>
#endif // HAVE_VARIANT

#ifdef HAVE_VECTOR
#include <vector>
#endif // HAVE_VECTOR

#ifdef HAVE_WINDOWS_H
#include <windows.h>
#endif // HAVE_WINDOWS_H

// Windows doesn't have strcasecmp.
#if defined(_WIN32) && !defined(__MINGW32__)
#define strcasecmp _stricmp
#define strncasecmp _strnicmp
#endif // _WIN32, __MINGW32__

//! The maximum length of a static buffer.
#define MAXLEN_STRING		(8192)

#endif // _BOOSTECHO_BOOSTECHO_HXX_
