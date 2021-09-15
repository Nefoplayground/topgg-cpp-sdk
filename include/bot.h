#ifndef DBL_BOT_H
#define DBL_BOT_H

#include <deps/json.hpp>
#include <string>
#include <vector>

using json = nlohmann::basic_json;
using std::string;
using std::vector;
using std::size_t;

namespace dbl {
    struct bot_stats_t {
        size_t server_count;
        vector<string> shards;
        size_t shard_count;
    };
    
    struct bot_vote_t {
        string username;
        string id;
        string avatar;
    };
    
    class Bot {
        public:
            string id;
            string username;
            string discriminator;
            string def_avatar;
            // string lib;
            string prefix;
            string shortdesc;
            vector<string> tags;
            vector<string> owners;
            string date;
            bool certified;
            size_t upvotes;
            size_t monthly_upvotes;
            string donatebot_guild_id;
    
            string avatar;
            string longdesc;
            string website;
            string support;
            string github;
            string invite;
            size_t server_count;
            size_t shard_count;
            string vanity;
        
            Bot(const json *);
            inline bool operator==(const dbl::Bot other) const;
    };
    
    struct bot_search_t {
        vector<struct dbl::bot_t> bots;
        
    };
    
    class BotSearch {
        dbl::Bot * bots = nullptr;
        
        public:
            size_t limit;
            size_t offset;
            size_t count;
            size_t total;
        
            BotSearch(const json *);
            inline dbl::Bot * operator[](const size_t) const;
            ~BotSearch();
    };

    struct dbl::bot_stats_t dbl::create_bot_stats(json &);
    struct dbl::bot_vote_t dbl::create_bot_vote(json &);
};

#endif