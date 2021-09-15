#include <http.h>

using dbl::Http;

void Http::handle_ratelimit(const bool & bot) {
    const time_t current = time(nullptr);

    if (this->next_global_request && this->global_request_count == 100 && current < this->next_global_request) {
        const struct dbl::http_exception_t exc = { 429, dbl::ratelimit_type_t::BOT, 1 };
        throw exc;
    } else {
        if (this->global_request_count == 100)
            this->global_request_count = 0;
        else
            this->global_request_count++;
        
        this->next_global_request = current + 1;
    }
    if (bot) {
        if (this->next_bot_request && this->global_bot_request_count == 60 && current < this->next_bot_request) {
            const struct dbl::http_exception_t exc = { 429, dbl::ratelimit_type::BOT, this->next_bot_request - current };
            throw exc;
        } else {
            if (this->global_bot_request_count == 100)
                this->global_bot_request_count = 0;
            else
                this->global_bot_request_count++;
            this->next_bot_request = current + 60;
        }
    }
}

void Http::set_token(const std::string & tk) noexcept {
    this->cli = httplib::Client("https://top.gg");
    this->cli.enable_server_certificate_verification(false);
    this->cli.set_default_headers({
        { "Authorization", tk },
        { "Content-Type", "application/json" }
    });
}

nlohmann::basic_json request(const std::string & path, const bool bot) {
    this->handle_ratelimit(bot);
    const httplib::Result res = this->cli.Get(path);
    if (res->status >= 400) {
        const struct dbl::http_exception_t exc = { res->status, dbl::ratelimit_type_t::NONE, 0 };
        throw exc;
    }

    return nlohmann::basic_json::parse(res->body);
}