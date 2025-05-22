#pragma once
#include<vector>
#include<memory>
#include"Music.h"
#include"PlayList.h"
#include"Artist.h"
class DataBase
{
private:
	std::vector<std::shared_ptr<Music>> all_musics;
	std::vector<std::shared_ptr<PlayList>> all_play_lists;
	std::vector<std::shared_ptr<Artist>> all_Artists;
public:
	DataBase();
	~DataBase();
	void add_music(std::shared_ptr<Music>);
	void remove_music(std::shared_ptr<Music>);

	void add_play_list(std::shared_ptr<PlayList>);
	void remove_play_list(std::shared_ptr<PlayList>);

	void add_artist(std::shared_ptr<Artist>);
	void remove_artist(std::shared_ptr<Artist>);

	std::shared_ptr<Music> find_music(std::string);
	std::shared_ptr<PlayList> find_play_list(std::string);
	std::shared_ptr<Artist> find_artist(std::string);

	void show_all_musics()const;
	void show_all_play_lists()const;
	void show_all_artists()const;

	int get_number_of_all_musics()const;
	int get_number_of_all_play_lists()const;
	int get_number_of_all_artists()const;

};

