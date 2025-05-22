#pragma once
#include<iostream>
#include<vector>
#include<memory>
#include"Music.h"
#include"PlayList.h"
class Artist
{
private:
	std::string artist_name;
	int number_of_albums;
	int number_of_released_songs;
	std::vector<std::shared_ptr<Music>> released_songs_list;
	std::vector<std::shared_ptr<PlayList>> artist_play_lists;
public:
	Artist();
	Artist(std::string, int , int);
	~Artist();

	void set_artist_name(std::string);
	void set_number_of_albums(int);
	void set_number_of_released_songs(int);

	void add_song(std::shared_ptr<Music>);
	void remove_song(int);

	void add_play_list(std::shared_ptr<PlayList>);
	void remove_play_list(int);

	std::string get_artist_name()const;
	int get_number_of_albums()const;
	int get_number_of_released_songs()const;
	std::vector<std::shared_ptr<Music>> get_all_songs()const;

	void show_artist_info()const;
};

