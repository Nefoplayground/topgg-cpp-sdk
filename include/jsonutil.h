#ifndef DBL_JSONUTIL_H
#define DBL_JSONUTIL_H

#include <vector>
#include <string>
#include <deps/json.hpp>

using json = nlohmann::basic_json;
using std::string;
using std::vector;

inline string json_str(const json *, const char *);
bool json_bool(const json *, const char *);
inline size_t json_num(const json *, const char *);
vector<string> json_str_arr(const json *, const char *);

#endif
