#include"User.h"

User::User(std::string user_name, std::string password)
	:BaseUser(user_name, password) {}
User::~User() {

}
void User::add_favourite_song(std::shared_ptr<Music> song) {
	this->favourit_songs.push_back(song);
}
void User::save_song(std::shared_ptr<Music> song) {
	this->saved_songs.push_back(song);
}
void User::remove_favourite_song(int index) {
	this->favourit_songs.erase(this->favourit_songs.begin() + index);
}
void User::remove_saved_song(int index) {
	this->saved_songs.erase(this->saved_songs.begin() + index);
}
void User::make_play_list() {
	std::string name;
	std::cout << "play list name: ";
	std::getline(std::cin, name);

	std::shared_ptr<PlayList> new_play_list = std::make_shared<PlayList>(name);
	this->play_lists.push_back(new_play_list);
}
void User::add_favourite_play_list(std::shared_ptr<PlayList> play_list) {
	this->favourite_play_lists.push_back(play_list);
}
void User::remove_play_list(int index) {
	this->play_lists.erase(this->play_lists.begin() + index);
}
void User::remove_favourite_play_list(int index) {
	this->favourite_play_lists.erase(this->favourite_play_lists.begin() + index);
}



void User::view_list_of_saved_songs()const {
	for (size_t i = 0; i < this->saved_songs.size(); i++) {
		//this->saved_songs.at(i).show_info();
	}
}
void User::view_list_of_favourite_songs()const {
	for (size_t i = 0; i < this->favourit_songs.size(); i++) {
		//this->favourit_songs.at(i).show_info();
	}
}
void User::view_list_of_play_lists()const {
	for (size_t i = 0; i < this->play_lists.size(); i++) {
		//this->play_lists.at(i).show_info();
	}
}
void User::view_list_of_favourite_play_lists()const {
	for (size_t i = 0; i < this->favourite_play_lists.size(); i++) {
		//this->favourite_play_lists.at(i).show_info();
	}
}
void User::view_other_users_play_lists()const {

}