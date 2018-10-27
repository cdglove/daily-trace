// ****************************************************************************
// log.h
//
// Basic logging facility for daily.
//
// Chris Glover (c.d.glover@gmail.com)
//
// Oct 21th, 2012
//
// ****************************************************************************
#ifndef DAILY_TRACE_LOG_HPP
#define DAILY_TRACE_LOG_HPP
#pragma once

#include <boost/test/utils/nullstream.hpp>
#include <iostream>

#ifndef DAILY_ENABLE_LOGGING
#  define DAILY_ENABLE_LOGGING 1
#endif

#ifndef DAILY_ENABLE_FAST_LOG
#  define DAILY_ENABLE_FAST_LOG 0
#endif

#if DAILY_ENABLE_FAST_LOG
#  include <daily/fast_iostream/fast_ostream.h>
#endif
// ----------------------------------------------------------------------------
//
namespace daily { namespace trace {
class logger {
 public:
#if DAILY_ENABLE_FAST_LOG
  typedef daily::fast_ostream<std::ostream> sink_impl;
#else
  typedef std::ostream sink_impl;
#endif

  logger(std::ostream& sink)
      : sink_(sink) {
  }

  template <typename T>
  logger& operator<<(T&& t) {
#if DAILY_ENABLE_LOGGING
    sink_ << std::forward<T>(t);
#endif
    return *this;
  }

  // Allow io-maniplulators.
  logger& operator<<(std::ostream& (*f)(std::ostream&)) {
#if DAILY_ENABLE_LOGGING
#  if DAILY_ENABLE_FAST_LOG
    sink_.stream() << f;
#  else
    sink_ << f;
#  endif
#endif
    return *this;
  }

  sink_impl& sink() {
    return sink_;
  }

 private:
  sink_impl& sink_;
};

void set_verbosity(unsigned int v);
void use_buffered_output(bool buffer);

// ----------------------------------------------------------------------------
//
inline logger LOG(unsigned int verbosity = 0) {
  extern unsigned int g_log_level;
  extern bool g_use_buffered_log;

  if(g_log_level >= verbosity) {
    return g_use_buffered_log ? logger(std::clog) : logger(std::cerr);
  }
  else {
    static boost::onullstream cnull;
    return logger(cnull);
  }
}

}} // namespace daily::trace

#if !DAILY_NO_GLOBAL_LOG
using daily::trace::LOG;
#endif

#endif // DAILY_TRACE_LOG_HPP