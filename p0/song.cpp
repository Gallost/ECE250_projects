#include <iostream>
#include <string>
#include "playlistdriver.h"

song::song(const std::string& song_to_create)
{
    //std::cout << "song object created" << std::endl;
    song_data = song_to_create;
}

song::song()
{
    //std::cout << "song object created - no parameter" << std::endl;
    song_data = "\0";
}

song::~song()
{
    song_data = "\0";
    //std::cout << "song object destructed" << std::endl;
}

std::string song::get_data() const
{
    return this->song_data;
}