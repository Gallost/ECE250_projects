#pragma once
#include <iostream>

class song
{
	private:
		std::string song_data;

	public:
		song(const std::string& song_to_create);

		song();

		~song();

		std::string get_data() const;

};


class playlist
{
	private:
		int size;
		int number_of_songs;
		song* list;

	public:
		playlist(const int& list_size);

		playlist();

		~playlist();

		void insert(const song& song_to_insert);

		void play(const int& index_to_play);

		void erase(const int& index_to_erase);

		int get_number_of_songs();
};


//additional helper function
bool same_song(const song& song_1, const song& song_2);