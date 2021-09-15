#ifndef DBL_API_H
#define DBL_API_H

#include <string>
#include <http.h>
#include <user.h>
#include <bot.h>

using json = nlohmann::basic_json;
using std::string;

namespace dbl {
    class Api: private dbl::Http {
        public:
            Api(const string & tkn);
            dbl::User get_user(const string &);
            dbl::Bot get_bot(const string &);
            BotSearch Api::search_bot(const string & query)
            std::vector<bot_vote_t> get_last_1000_votes(const string botId);
            bool has_user_voted(const string botId, const string userId);

    };
};

#endif