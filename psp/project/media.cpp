#include "media.hpp"

media::media(std::string _creator, std::string _name, int _duration, std::string _genre)
{
    creator = _creator;
    name = _name;
    duration = _duration;
    genre = _genre;
}