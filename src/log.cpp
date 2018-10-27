// ****************************************************************************
// daily/trace/log.cpp
//
// Basic logging facility for daily.
//
// Chris Glover (c.d.glover@gmail.com)
//
// Oct 21th, 2012
//
// ****************************************************************************

#include "daily/trace/log.hpp"

namespace daily { namespace trace {

unsigned int g_log_level = 0;
std::ostream* g_log_sink = &std::clog;

void set_verbosity(unsigned int v) {
  g_log_level = v;
}

void use_sink(std::ostream& out) {
  g_log_sink = &out;
}

}} // namespace daily::trace