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
bool g_use_buffered_log  = true;

void set_verbosity(unsigned int v) {
  g_log_level = v;
}

void use_buffered_output(bool buffer) {
  g_use_buffered_log = buffer;
}

}} // namespace daily::trace