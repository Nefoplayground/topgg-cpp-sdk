#include <user.h>
#include <jsonutil.h>

using dbl::User;

User::User(const json * js) {
    this->id = json_str(js, "id");
    this->username = json_str(js, "username");
    this->discriminator = json_str(js, "discriminator");
    this->def_avatar = json_str(js, "defAvatar");
    this->supporter = json_bool(js, "supporter");
    this->certified_dev = json_bool(js, "certifiedDev");
    this->mod = json_bool(js, "mod");
    this->web_mod = json_bool(js, "webMod");
    this->admin = json_bool(js, "admin");
    
    this->avatar = json_str(js, "avatar");
    this->bio = json_str(js, "bio");
    this->banner = json_str(js, "banner");
    this->color = json_str(js, "color");
    
    json s;
    const bool has_social = ((s = js->find("social")) != js->end());
    
    this->social.youtube = has_social ? json_str(s, "youtube") : "";
    this->social.reddit = has_social ? json_str(s, "reddit") : "";
    this->social.twitter = has_social ? json_str(s, "twitter") : "";
    this->social.instagram = has_social ? json_str(s, "instagram") : "";
    this->social.github = has_social ? json_str(s, "github") : "";
}

inline bool User::operator==(const User & other) const {
    return this->id == other.id;
}