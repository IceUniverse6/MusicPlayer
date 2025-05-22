#include "DataBase.h"

DataBase::DataBase() {

}
DataBase::~DataBase() {

}

void DataBase::add_music(std::shared_ptr<Music> music) {
	this->all_musics.push_back(music);
}
void DataBase::remove_music(std::shared_ptr<Music> music) {
	for (size_t i = 0; i < this->all_musics.size(); i++) {
		if ((this->all_musics.at(i)->get_music_name() == music->get_music_name()) && (this->all_musics.at(i)->get_artist_name() == music->get_artist_name())) {
			this->all_musics.erase(this->all_musics.begin() + i);
			break;
		}
	}
}

void DataBase::add_play_list(std::shared_ptr<PlayList> play_list) {
	this->all_play_lists.push_back(play_list);
}
void DataBase::remove_play_list(std::shared_ptr<PlayList> play_list) {
	for (size_t i = 0; i < this->all_play_lists.size(); i++) {
		if (this->all_play_lists.at(i)->get_play_list_name() == play_list->get_play_list_name()) {
			this->all_play_lists.erase(this->all_play_lists.begin() + i);
			break;
		}
	}
}

void DataBase::add_artist(std::shared_ptr<Artist> artist) {
	this->all_Artists.push_back(artist);
}
void DataBase::remove_artist(std::shared_ptr<Artist> artist) {
	for (size_t i = 0; i < this->all_Artists.size(); i++) {
		if (this->all_Artists.at(i)->get_artist_name() == artist->get_artist_name()) {
			this->all_Artists.erase(this->all_Artists.begin() + i);
			break;
		}
	}
}

std::shared_ptr<Music> DataBase::find_music(std::string music_name) {
	for (size_t i = 0; i < this->all_musics.size(); i++) {
		if (this->all_musics.at(i)->get_music_name() == music_name) {
			return this->all_musics.at(i);
		}
	}
	return nullptr;
}
std::shared_ptr<PlayList> DataBase::find_play_list(std::string play_list_name) {
	for (size_t i = 0; i < this->all_play_lists.size(); i++) {
		if (this->all_play_lists.at(i)->get_play_list_name() == play_list_name) {
			return this->all_play_lists.at(i);
		}
	}
	return nullptr;
}
std::shared_ptr<Artist> DataBase::find_artist(std::string artist_name) {
	for (size_t i = 0; i < this->all_Artists.size(); i++) {
		if (this->all_Artists.at(i)->get_artist_name() == artist_name) {
			return this->all_Artists.at(i);
		}
	}
	return nullptr;
}

void DataBase::show_all_musics()const {
	if (this->all_musics.size() == 0) {
		std::cout << "database is empty" << std::endl;
		return;
	}
	for (size_t i = 0; i < this->all_musics.size(); i++) {
		//this->all_musics.at(i)->showinfo();
	}
}
void DataBase::show_all_play_lists()const {
	if (this->all_play_lists.size() == 0) {
		std::cout << "database is empty" << std::endl;
		return;
	}
	for (size_t i = 0; i < this->all_play_lists.size(); i++) {
		this->all_play_lists.at(i)->show_play_list_info();
	}
}
void DataBase::show_all_artists()const {
	if (this->all_Artists.size() == 0) {
		std::cout << "database is empty" << std::endl;
		return;
	}
	for (size_t i = 0; i < this->all_Artists.size(); i++) {
		this->all_Artists.at(i)->show_artist_info();
	}
}

int DataBase::get_number_of_all_musics()const {
	return this->all_musics.size();
}
int DataBase::get_number_of_all_play_lists()const {
	return this->all_play_lists.size();
}
int DataBase::get_number_of_all_artists()const {
	return this->all_Artists.size();
}