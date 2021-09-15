#include <sstream>
#include <iomanip>
#include <cctype>
#include <api.h>

using std::ostringstream;
using std::nouppercase;
using std::uppercase;
using std::setw;
using std::hex;

using namespace dbl;

static string encode_uri(const string & value) {
    std::ostringstream escaped;
    escaped.fill('0');
    escaped << hex;

    for (string::const_iterator i = value.begin(), n = value.end(); i != n; ++i) {
        string::value_type c = (*i);

        if (isalnum(c) || c == 45 || c == 95 || c == 46 || c == 126) {
            escaped << c;
            continue;
        }

        escaped << uppercase << '%' << setw(2) << int((unsigned char) c) << nouppercase;
    }

    return escaped.str();
}

Api::Api(const string & tkn) {
    this->set_token(tkn);
}

User Api::get_user(const string & snowflake) {
    const json res = this->request("/user/" + snowflake, false);
    return User(&res);
}

Bot Api::get_bot(const string & snowflake) {
    const json res = this->request("/bots/" + snowflake);
    return Bot(&res);
}

BotSearch Api::search_bot(const string & query) {
    const json res = this->request("/bots?search=" + encode_uri(query));
    return BotSearch(&res);
}

std::vector<bot_vote_t> Api::get_last_1000_votes(const string snowflake){
    const json res = this->request("/bots/" + snowflake + "/votes");
    
    return res;
};

bool Api::has_user_voted(const string botId, const string userId){
    const json res = this->request("/bots/" + botId  + "/check" + userId);

    return res.voted == 1 ? true : false;
}

