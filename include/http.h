#ifndef DBL_HTTP_H
#define DBL_HTTP_H

#ifndef CPPHTTPLIB_OPENSSL_SUPPORT
#define CPPHTTPLIB_OPENSSL_SUPPORT
#endif

#include <deps/httplib.h>
#include <deps/json.hpp>
#include <string>
#include <ctime>

using json = nlohmann::basic_json;
using httplib::Client;
using std::string;

namespace dbl {
    enum ratelimit_type_t { NONE, GLOBAL, BOT };

    struct http_exception_t {
        const unsigned short status_code;
        const enum dbl::ratelimit_type_t type;
        const unsigned char retry_after;
    };

    class Http {
        Client cli;

        time_t next_global_request = 0;
        time_t next_bot_request = 0;

        unsigned char global_request_count = 0;
        unsigned char global_bot_request_count = 0;

        void handle_ratelimit(const bool &);

        protected:
            void set_token(const string &) noexcept;
            json request(const string &, const bool);
    };
};

#endif
