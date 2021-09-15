#ifndef DBL_USER_H
#define DBL_USER_H

#include <string>
#include <deps/json.hpp>

using json = nlohmann::base_json;
using std::string;

namespace dbl {
    struct social_t {
        string youtube;
        string reddit;
        string twitter;
        string instagram;
        string github;
    };
    
    class User {
        public:
            string id;
            string username;
            string discriminator;
            string def_avatar;
            bool supporter;
            bool certified_dev;
            bool mod;
            bool web_mod;
            bool admin;
            
            string avatar;
            string bio;
            string banner;
            struct dbl::social_t social;
            string color;
        
            User(const json *);
            inline bool operator==(const dbl::User &) const;
    };
};

#endif
