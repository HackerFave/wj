/**
 * @file log.h
 * @author lujiefeng
 * @brief
 * @version 0.1
 * @date 2018-11-28
 *
 * @copyright Copyright () 2018
 *
 */
#ifndef LOG_H
#define LOG_H

#include <boost/asio.hpp>
#include <boost/format.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/attributes/attribute.hpp>
#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/expressions/keyword.hpp>
#include <boost/log/keywords/format.hpp>
#include <boost/log/keywords/target_file_name.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/sources/channel_feature.hpp>
#include <boost/log/sources/channel_logger.hpp>
#include <boost/log/sources/severity_channel_logger.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/manipulators/dump.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/from_stream.hpp>
#include <fstream>
#include <string>

namespace logging = boost::log;
namespace sinks = boost::log::sinks;
namespace attrs = boost::log::attributes;
namespace keyword = boost::log::keywords;
namespace expr = boost::log::expressions;
namespace src = boost::log::sources;

static inline void initLogFromConf(const char *confFileName) {
  logging::register_simple_formatter_factory<logging::trivial::severity_level,
                                             char>("Severity");
  logging::register_simple_filter_factory<logging::trivial::severity_level,
                                          char>("Severity");

  auto core = logging::core::get();
  logging::add_common_attributes();
  std::ifstream conffile(confFileName);
  logging::init_from_stream(conffile);

  //  logging::add_console_log(
  //      std::cout, boost::log::keywords::format = "[%TimeStamp%]: %Message%");
}

#define LOG_INIT_FROM_CONF(fileName) initLogFromConf(fileName)
#ifndef _WIN32
#define MY_BOOST_LOG(severity) \
  BOOST_LOG_TRIVIAL(severity) << "[" << __BASE_FILE__ << ":" << __LINE__ << "]:"
#else
#define MY_BOOST_LOG(severity) \
  BOOST_LOG_TRIVIAL(severity) << "[" << __FILE__ << ":" << __LINE__ << "]:"
#endif

#define LOG_Trace() MY_BOOST_LOG(trace)
#define LOG_Debug() MY_BOOST_LOG(debug)
#define LOG_Warn() MY_BOOST_LOG(warning)
#define LOG_Info() MY_BOOST_LOG(info)
#define LOG_Error() MY_BOOST_LOG(error)

#define LOG_DEBUG_HEX(data, len, text)                          \
  MY_BOOST_LOG(debug) << text << " DataLen:" << len << " Data[" \
                      << logging::dump(data, len) << "]"

// channel log
using loggerChannelType =
    src::severity_channel_logger_mt<logging::trivial::severity_level, std::string>;
const loggerChannelType channelLogger;

#ifndef _WIN32
#define MY_CHANNEL_LOG(channelName, severity)                           \
  BOOST_LOG_CHANNEL_SEV(const_cast<loggerChannelType &>(channelLogger), \
                        channelName, severity)                          \
      << "[" << __BASE_FILE__ << ":" << __LINE__ << "]:"
#else
#define MY_CHANNEL_LOG(channelName, severity)                           \
  BOOST_LOG_CHANNEL_SEV(const_cast<loggerChannelType &>(channelLogger), \
                        channelName, severity)                          \
      << "[" << __FILE__ << ":" << __LINE__ << "]:"
#endif

#define LOG_Channel_Trace(channelName) \
  MY_CHANNEL_LOG(channelName, logging::trivial::trace)

#define LOG_Channel_Debug(channelName) \
  MY_CHANNEL_LOG(channelName, logging::trivial::debug)

#define LOG_Channel_Info(channelName) \
  MY_CHANNEL_LOG(channelName, logging::trivial::info)

#define LOG_Channel_Warn(channelName) \
  MY_CHANNEL_LOG(channelName, logging::trivial::warning)

#define LOG_Channel_Error(channelName) \
  MY_CHANNEL_LOG(channelName, logging::trivial::error)

#define LOG_Channel_DEBUG_HEX(channelName, data, len, text)                \
  LOG_Channel_Debug(channelName) << text << " DataLen:" << len << " Data[" \
                                 << logging::dump(data, len) << "]"

#endif
