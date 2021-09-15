#include <jsonutil.h>

inline string json_str(const json * j, const char * path) {
    auto k = j->find(path);
    return k != j->end() && !k->is_null() && k->is_string() ? k->get<string>() : "";
}

size_t json_num(const json * j, const char * path) {
    auto k = j->find(path);
    return k != j->end() && !k->is_null() && k->is_number_integer() ? k->get<size_t>() : 0;
}

inline bool json_bool(const json * j, const char * path) {
    auto k = j->find(path);
    return k != j->end() && !k->is_null() && k->is_boolean() ? k->get<bool>() : false;
}

vector<string> json_str_arr(const json * j, const char * path) {
    vector<string> output;
    
    auto k = j->find(path);
    if (k == j->end() || k->is_null() || k->is_array())
        return output;
    
    for (json::iterator it = k->begin(); it != k->end(); ++it) {
        output.push_back((*it).get<string>());
    }
    
    return output;
}