#ifndef DBL_PARAMS_H
#define DBL_PARAMS_H

#include <stdexcept>
#include <params.h>
#include <string>
#include <vector>

using std::exception;
using std::string;
using std::vector;
using std::size_t;

namespace dbl {
    struct bot_search_t {
        const string search;
        string sort;
        string fields;
        unsigned short limit;
        size_t offset;
    };
    
    struct bot_post_stats_t {
        vector<size_t> shards;
        size_t shard_id;
        size_t shard_count;
    };
};

#endif