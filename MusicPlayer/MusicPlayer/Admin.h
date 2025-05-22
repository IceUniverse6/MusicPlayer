#pragma once
#include<vector>
#include<memory>
#include"BaseUser.h"
#include"Music.h"
#include"Artist.h"
#include"PlayList.h"
class Admin :public BaseUser
{
private:
	std::vector<std::shared_ptr<Music>> added_songs;
	std::vector<std::shared_ptr<Artist>> added_artists;
	std::vector<std::shared_ptr<PlayList>> added_play_lists;

public:
	Admin(std::string, std::string);
	~Admin();

	void add_song();
	void remove_song();

	void add_play_list();
	void remove_play_list();

	void add_song_to_play_list(std::shared_ptr<Music>);
	void remove_song_from_play_list();

	void add_artist_page();
	void remove_artist_page();

	void add_song_for_artist();
	void add_song_for_artist(std::shared_ptr<Artist>);
	void remove_song_for_artist();

	void add_play_list_for_artist();
	void add_play_list_for_artist(std::shared_ptr<Artist>);
	void remove_play_list_for_artist();

	void show_added_songs()const;
	void show_play_lists()const;
	void show_added_artists()const;

};

