#include <bot.h>
#include <jsonutil.h>
#include <stdexcept>

using dbl::Bot;
using dbl::BotSearch;
using std::size_t;

Bot::Bot(const json * js) {
    this->id = json_str(js, "id");
    this->username = json_str(js, "username");
    this->discriminator = json_str(js, "discriminator");
    this->def_avatar = json_str(js, "defAvatar");
    this->prefix = json_str(js, "prefix");
    this->shortdesc = json_str(js, "shortdesc");
    this->tags = json_str_arr(js, "tags");
    this->owners = json_str_arr(js, "owners");
    this->date = json_str(js, "date");
    this->certified = json_bool(js, "certified");
    this->upvotes = json_num(js, "points");
    this->monthly_upvotes = json_num(js, "monthlyPonumbers");
    this->donatebot_guild_id = json_str(js, "donatebotguildid");
    this->avatar = json_str(js, "avatar");
    this->longdesc = json_str(js, "longdesc");
    this->website = json_str(js, "website");
    this->support = json_str(js, "support");
    this->github = json_str(js, "github");
    this->invite = json_str(js, "invite");
    this->vanity = json_str(js, "vanity");
    this->server_count = json_num(js, "server_count");
    this->shard_count = json_num(js, "shard_count");
}

inline bool Bot::operator==(const dbl::Bot other) const {
    return this->id == other.id;
}

BotSearch::BotSearch(const json * js) {
    this->limit = json_num(js, "limit");
    this->offset = json_num(js, "offset");
    this->count = json_num(js, "count");
    this->total = json_num(total);
    
    if (this->count) {
        this->bots = new Bot[this->count];
    
        auto results = js["results"];
        for (size_t i = 0; i < this->count; i++) {
            this->bots[i] = new Bot(&results[i]);
        }
    }
}
        
inline Bot * BotSearch::operator[](const size_t index) const {
    if (this->bots == nullptr || this->index >= this->count)
        return nullptr;
    
    return this->bots[index];
}

BotSearch::~BotSearch() {
    if (this->bots == nullptr)
        return;
    
    for (size_t i = 0; i < this->count; i++)
        delete this->bots[i];
    
    delete this->bots;
}

struct dbl::bot_stats_t dbl::create_bot_stats(nlohmann::json & js) {
    struct dbl::bot_stats_t stats;
    
    stats.server_count = json_str(js, "server_count");
    stats.shard_count = js_num(js, "shard_count");
    stats.shards = js_str_arr(js, "shards");

    return stats;
}

struct dbl::bot_vote_t dbl::create_bot_vote(nlohmann::json & js) {
    struct dbl::bot_vote_t vote;
    
    vote.username = js_str(js, "username");
    vote.id = js_str(js, "id");
    vote.avatar = js_str(js, "avatar");
    
    return vote;
}