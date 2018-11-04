// ****************************************************************************
// trace/src/boost_assert.cpp
//
// Adapters for using boost assert within daily
//
// Chris Glover (c.d.glover@gmail.com)
//
// Oct 21th, 2012
//
// ****************************************************************************

#include "daily/trace/debugbreak.hpp"
#include "daily/trace/log.hpp"
#include <boost/stacktrace/stacktrace.hpp>
#include <stdexcept>

// ----------------------------------------------------------------------------
// Required when linking against a boost with boost assert enabled.
namespace boost {
void assertion_failed_msg(
    char const* expr,
    char const* msg,
    char const* function,
    char const* /*file*/,
    long /*line*/) {
  daily::trace::LOG() << "Expression '" << expr << "' is false in function '"
                      << function << "': " << (msg ? msg : "<...>") << ".\n"
                      << "Backtrace:\n"
                      << ::boost::stacktrace::stacktrace() << '\n';
  DEBUG_BREAK();
}

void assertion_failed(
    char const* expr, char const* function, char const* file, long line) {
  ::boost::assertion_failed_msg(expr, 0 /*nullptr*/, function, file, line);
}

} // namespace boost