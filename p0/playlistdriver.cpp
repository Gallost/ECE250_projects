#include <iostream>
#include <string>
#include "playlistdriver.h"


///////////////////
//helper function//
///////////////////

bool same_song(const song& song_1, const song& song_2)
{
    std::string s1 = song_1.get_data();
    std::string s2 = song_2.get_data();

    //check if they are the same length
    if (s1.size() != s2.size()) return false;

    // convert s1 and s2 to lowercase
    for (std::size_t i{ 0 }; i < s1.size(); i++) {
        if (('A' <= s1[i]) && (s1[i] <= 'Z'))
            s1[i] += 32;
    }
    for (std::size_t i{ 0 }; i < s2.size(); i++) {
        if (('A' <= s2[i]) && (s2[i] <= 'Z'))
            s2[i] += 32;
    }

    //compare s1 and s2
    for (std::size_t i{ 0 }; i < s1.size(); i++) {
        if (s1[i] != s2[i]) return false;
    }

    return true;
}



/////////////////
//main function//
/////////////////

int main()
{
    std::string line;
    playlist* my_list = nullptr;
    bool list_created{ false };

    while (true)
    {
        if (std::cin.eof())
            break;

        std::getline(std::cin, line);

        if (line == "exit") {
            std::cout << "exiting" << std::endl;
            break;
        }

        int pos = line.find(" ");
        std::string cmd = line.substr(0, pos);
        std::string obj = line.substr(pos + 1);

        if (list_created == false) {
            if (cmd == "m") {
                bool valid_size{ false };
                int size_of_list{ 0 };
                try {
                    size_of_list = std::stoi(obj);
                    valid_size = true;
                }
                catch (std::invalid_argument& e) {
                    valid_size = false;
                    //std::cout << "invalid argument" << std::endl;
                }

                if (valid_size) {
                    my_list = new playlist(size_of_list);
                    list_created = true;
                }
            }
        }
        else {
            if (cmd == "i") {
                song new_song(obj);
                my_list->insert(new_song);
            }

            if (cmd == "p") {
                try {
                    int index_of_song = std::stoi(obj);
                    my_list->play(index_of_song);
                }
                catch (std::invalid_argument& e) {
                    std::cout << "invalid argument" << std::endl;
                }
            }

            if (cmd == "e") {
                int index_of_song = std::stoi(obj);
                if (index_of_song < 1)
                    std::cout << "can not erase " << index_of_song << std::endl;
                else
                    my_list->erase(index_of_song);
            }
        }
    }

    return 0;
}
