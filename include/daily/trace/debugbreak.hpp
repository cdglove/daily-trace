// ****************************************************************************
// daily/trace/debugbreak.hpp
//
// Macros to perform a debug break on various platforms.
//
// Chris Glover (c.d.glover@gmail.com)
//
// Oct 21th, 2012
//
// ****************************************************************************
#ifndef DAILY_TRACE_DEBUGBREAK_HPP
#define DAILY_TRACE_DEBUGBREAK_HPP
#pragma once

#if _MSC_VER
#  define DEBUG_BREAK() __debugbreak()
#elif defined(SIGTRAP)
#  include <signal.h>
#  define DEBUG_BREAK() raise(SIGTRAP)
#elif WIN32
#  include <windows.h>
#  define DEBUG_BREAK() DebugBreak()
#else
#  include <cassert>
#  define DEBUG_BREAK() assert(false)
#endif

#endif // DAILY_TRACE_DEBUGBREAK_HPP