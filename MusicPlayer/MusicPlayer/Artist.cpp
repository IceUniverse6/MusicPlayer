#include"Artist.h"

Artist::Artist() {
	this->number_of_albums = 0;
	this->number_of_released_songs = 0;
}
Artist::Artist(std::string artist_name, int number_of_albums, int number_of_released_songs) {
	this->artist_name = artist_name;
	this->number_of_albums = number_of_albums;
	this->number_of_released_songs = number_of_released_songs;
}
Artist::~Artist() {

}

void Artist::set_artist_name(std::string artist_name) {
	this->artist_name = artist_name;
}
void Artist::set_number_of_albums(int number_of_albums) {
	this->number_of_albums = number_of_albums;
}
void Artist::set_number_of_released_songs(int number_of_released_songs) {
	this->number_of_released_songs = number_of_released_songs;
}

void Artist::add_song(std::shared_ptr<Music> music) {
	this->released_songs_list.push_back(music);
}
void Artist::remove_song(int index) {
	this->released_songs_list.erase(this->released_songs_list.begin() + index);
}

void Artist::add_play_list(std::shared_ptr<PlayList> play_list) {
	this->artist_play_lists.push_back(play_list);
}
void Artist::remove_play_list(int index) {
	this->artist_play_lists.erase(this->artist_play_lists.begin() + index);

}

std::string Artist::get_artist_name()const {
	return this->artist_name;
}
int Artist::get_number_of_albums()const {
	return this->number_of_albums;
}
int Artist::get_number_of_released_songs()const {
	return this->number_of_released_songs;
}
std::vector<std::shared_ptr<Music>> Artist::get_all_songs()const {
	return this->released_songs_list;
}

void Artist::show_artist_info()const {
	std::cout << "artist name: " << this->artist_name << std::endl;
	std::cout << "number of albums: " << this->number_of_albums << std::endl;
	std::cout << "number of released songs: " << this->number_of_released_songs << std::endl;
}