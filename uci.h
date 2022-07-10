#ifndef __UCI_H__
#define __UCI_H__

#include <cstdint>
#include <string>

constexpr uint64_t DEFAULT_HASH_SIZE = 16;
constexpr uint64_t MIN_HASH_SIZE = 1;
constexpr uint64_t MAX_HASH_SIZE = 1024 * 1024;
constexpr int DEFAULT_MULTI_PV = 1;
constexpr int MIN_MULTI_PV = 1;
constexpr int MAX_MULTI_PV = 256;
constexpr int DEFAULT_THREADS = 1;
constexpr int MIN_THREADS = 1;
constexpr int MAX_THREADS = 128;
constexpr int DEFAULT_BUFFER_TIME = 300;
constexpr int MIN_BUFFER_TIME = 0;
constexpr int MAX_BUFFER_TIME = 5000;
constexpr int DEFAULT_EVAL_SCALE = 100;
constexpr int MIN_EVAL_SCALE = 0;
constexpr int MAX_EVAL_SCALE = 500;

Board fenToBoard(std::string s);
std::string boardToFEN(Board &board);

#endif
