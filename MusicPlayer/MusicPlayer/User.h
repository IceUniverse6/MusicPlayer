#pragma once
#include<vector>
#include<memory>
#include"BaseUser.h"
#include"PlayList.h"
#include"Music.h"
class User :public BaseUser
{
private:
	std::vector<std::shared_ptr<Music>> favourit_songs;
	std::vector<std::shared_ptr<Music>> saved_songs;
	std::vector<std::shared_ptr<PlayList>> play_lists;
	std::vector<std::shared_ptr<PlayList>> favourite_play_lists;

public:

	User(std::string, std::string);
	~User();

	void add_favourite_song(std::shared_ptr<Music>);
	void save_song(std::shared_ptr<Music>);
	void remove_favourite_song(int);
	void remove_saved_song(int);
	void make_play_list();
	void add_favourite_play_list(std::shared_ptr<PlayList>);
	void remove_play_list(int);
	void remove_favourite_play_list(int);



	void view_list_of_saved_songs()const;
	void view_list_of_favourite_songs()const;
	void view_list_of_play_lists()const;
	void view_list_of_favourite_play_lists()const;
	void view_other_users_play_lists()const;
};

