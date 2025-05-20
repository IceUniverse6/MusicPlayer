#pragma once
#include<iostream>
#include<vector>
#include"Music.h"
class PlayList
{
private:
	std::string play_list_name;
	std::vector<Music> music_list;
public:
	PlayList();
	PlayList(std::string);
	~PlayList();

	void set_play_list_name(std::string);
	void add_music(Music);
	void remove_music(int);

	std::string get_play_list_name()const;
	int get_number_of_songs()const;
	std::vector<Music> get_all_songs()const;

	void show_songs()const;
};

