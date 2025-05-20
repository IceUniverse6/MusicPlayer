#include "BaseUser.h"

BaseUser::BaseUser() {

}
BaseUser::BaseUser(std::string user_name, std::string password) {
	this->user_name = user_name;
	this->password = password;
}
BaseUser::~BaseUser() {

}
void BaseUser::set_user_name(std::string user_name) {
	this->user_name = user_name;
}
void BaseUser::set_password(std::string password) {
	this->password = password;
}
std::string BaseUser::get_user_name()const {
	return this->user_name;
}
std::string BaseUser::get_password()const {
	return this->password;
}