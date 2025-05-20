#pragma once
#include<iostream>
#include<vector>
#include"Music.h"
class Artist
{
private:
	std::string artist_name;
	int number_of_albums;
	int number_of_released_songs;
	std::vector<Music> released_songs_list;
public:
	Artist();
	Artist(std::string, int , int);
	~Artist();

	void set_artist_name(std::string);
	void set_number_of_albums(int);
	void set_number_of_released_songs(int);

	void add_song();
	void remove_song();

	std::string get_artist_name()const;
	int get_number_of_albums()const;
	int get_number_of_released_songs()const;
	std::vector<Music> get_all_songs()const;
};

