//
// detail/pipe_select_interrupter.hpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2010 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef ASIO_DETAIL_PIPE_SELECT_INTERRUPTER_HPP
#define ASIO_DETAIL_PIPE_SELECT_INTERRUPTER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "asio/detail/push_options.hpp"

#include "asio/detail/config.hpp"

#if !defined(BOOST_WINDOWS) && !defined(__CYGWIN__)

namespace asio {
namespace detail {

class pipe_select_interrupter
{
public:
  // Constructor.
  ASIO_DECL pipe_select_interrupter();

  // Destructor.
  ASIO_DECL ~pipe_select_interrupter();

  // Interrupt the select call.
  ASIO_DECL void interrupt();

  // Reset the select interrupt. Returns true if the call was interrupted.
  ASIO_DECL bool reset();

  // Get the read descriptor to be passed to select.
  int read_descriptor() const;

private:
  // The read end of a connection used to interrupt the select call. This file
  // descriptor is passed to select such that when it is time to stop, a single
  // byte will be written on the other end of the connection and this
  // descriptor will become readable.
  int read_descriptor_;

  // The write end of a connection used to interrupt the select call. A single
  // byte may be written to this to wake up the select which is waiting for the
  // other end to become readable.
  int write_descriptor_;
};

} // namespace detail
} // namespace asio

#endif // !defined(BOOST_WINDOWS) && !defined(__CYGWIN__)

#include "asio/detail/pop_options.hpp"

#include "asio/detail/impl/pipe_select_interrupter.hpp"
#if defined(ASIO_HEADER_ONLY)
# include "asio/detail/impl/pipe_select_interrupter.ipp"
#endif // defined(ASIO_HEADER_ONLY)

#endif // ASIO_DETAIL_PIPE_SELECT_INTERRUPTER_HPP
