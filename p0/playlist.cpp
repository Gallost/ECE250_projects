#include <iostream>
#include <string>
#include "playlistdriver.h"

playlist::playlist(const int& list_size)
{
    //std::cout << "playlist object created" << std::endl;
    size = list_size;
    number_of_songs = 0;
    list = new song[size];
    std::cout << "success" << std::endl;
}

playlist::playlist()
{
    //std::cout << "playlist object created - no parameter" << std::endl;
    size = 0;
    number_of_songs = 0;
    list = nullptr;
}

playlist::~playlist()
{
    //std::cout << "playlist object destructed" << std::endl;
    size = 0;
    number_of_songs = 0;
    delete[] list;
    list = nullptr;
}

void playlist::insert(const song& song_to_insert)
{
    std::string song_data_to_insert = song_to_insert.get_data();

    if (list == nullptr) {
        std::cout << "list does not exist" << std::endl;
    }
    else {
        // check if list is full
        if (number_of_songs == size)
            std::cout << "can not insert " << song_data_to_insert << std::endl;
        //check if song is already in list
        else {
            for (int i{ 0 }; i < number_of_songs; i++) {
                if (same_song(song_to_insert, list[i])) {
                    std::cout << "can not insert " << song_data_to_insert << std::endl;
                    return;
                }
            }
            list[number_of_songs] = song_to_insert;
            number_of_songs += 1;
            std::cout << "success" << std::endl;
        }
    }
}

void playlist::play(const int& index_to_play)
{
    std::string res;
    if ((1 <= index_to_play) && (index_to_play <= number_of_songs)) {
        int actual_index = index_to_play - 1;
        std::string data = list[actual_index].get_data();
        std::cout << "played " << index_to_play << ' ' << data << std::endl;
        return;
    }

    std::cout << "can not play " << index_to_play << std::endl;
    return;
}

int playlist::get_number_of_songs()
{
    return this->number_of_songs;
}

void playlist::erase(const int& index_to_erase)
{
    song empty_song("\0");
    int actual_index = index_to_erase - 1;

    if (index_to_erase > number_of_songs)
        std::cout << "can not erase " << index_to_erase << std::endl;
    else {
        list[actual_index] = empty_song;
        if (index_to_erase == number_of_songs) {
            std::cout << "success" << std::endl;
        }
        else {
            for (int i{ actual_index + 1 }; i < number_of_songs; i++) {
                list[i - 1] = list[i];
                list[i] = empty_song;
            }
            std::cout << "success" << std::endl;
        }
        number_of_songs -= 1;
    }
}