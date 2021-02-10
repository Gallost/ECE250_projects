#include "deque.h"
#include <iostream>

deque::deque()
{
	list = new linked_list;
	size = 0;
}

deque::~deque()
{
	this->clear_deque();
	delete list;
	list = nullptr;
	size = 0;
}

void deque::push_front(const std::string& url_name_in, const std::string& url_val_in)
{
	url* new_url = new url(url_name_in, url_val_in);
	url* first_url = this->list->get_head();

	if (this->is_empty()) {
		//set list head and tail to the new url
		this->list->set_head(new_url);
		this->list->set_tail(new_url);

		//set new_url's next and prev to nullptr
		new_url->set_next(nullptr);
		new_url->set_prev(nullptr);

		//increment size of list and output "success"
		this->size += 1;
		std::cout << "success" << std::endl;
	}
	else {
		//set new_url's next to first url, prev to nullptr
		new_url->set_next(first_url);
		new_url->set_prev(nullptr);

		//set first url's prev to new_url
		first_url->set_prev(new_url);

		//set the list head to new_url
		this->list->set_head(new_url);

		//increment size of list and output "success"
		this->size += 1;
		std::cout << "success" << std::endl;
	}

	new_url = nullptr;
	first_url = nullptr;
}

void deque::push_back(const std::string& url_name_in, const std::string& url_val_in)
{
	url* new_url = new url(url_name_in, url_val_in);
	url* last_url = this->list->get_tail();

	if (this->is_empty()) {
		//set list head and tail to the new url
		this->list->set_head(new_url);
		this->list->set_tail(new_url);

		//set new_url's next and prev to nullptr
		new_url->set_next(nullptr);
		new_url->set_prev(nullptr);

		//increment size of list and output "success"
		this->size += 1;
		std::cout << "success" << std::endl;
	}
	else {
		//set new_url's next to nullptr, prev to last url
		new_url->set_prev(last_url);
		new_url->set_next(nullptr);

		//set last url's next to new_url
		last_url->set_next(new_url);

		//set the list tail to new_url
		this->list->set_tail(new_url);

		//increment size of list and output "success"
		this->size += 1;
		std::cout << "success" << std::endl;
	}

	new_url = nullptr;
	last_url = nullptr;
}

void deque::pop_front()
{
	if (this->is_empty()) {
		std::cout << "failure" << std::endl;
	}
	else {
		url* old_first_url = this->list->get_head();
		url* new_first_url = old_first_url->get_next();

		//set list head to the new first url
		this->list->set_head(new_first_url);

		//set the prev of new first url to nullptr if new first url isn't nullptr
		if (new_first_url != nullptr)
			new_first_url->set_prev(nullptr);
		else //if new first url is nullptr ==> list is empty ==> set tail to nullptr
			this->list->set_tail(nullptr);

		//delete the old first url
		delete old_first_url;

		//set temp pointers to nullptr
		old_first_url = nullptr;
		new_first_url = nullptr;

		//decrement size of list and output "success"
		this->size -= 1;
		std::cout << "success" << std::endl;
	}
}

void deque::pop_back()
{
	if (this->is_empty()) {
		std::cout << "failure" << std::endl;
	}
	else {
		url* old_last_url = this->list->get_tail();
		url* new_last_url = old_last_url->get_prev();

		//set list tail to the new last url
		this->list->set_tail(new_last_url);

		//set the next of new last url to nullptr if new last url it isn'a nullptr
		if (new_last_url != nullptr)
			new_last_url->set_next(nullptr);
		else
			this->list->set_head(nullptr);

		//delete the old last url
		delete old_last_url;

		//set temp pointers to nullptr
		old_last_url = nullptr;
		new_last_url = nullptr;

		//decrement size of list and output "success"
		this->size -= 1;
		std::cout << "success" << std::endl;
	}
}

void deque::clear_deque()
{
	if (!this->is_empty()) {
		url* current_cursor = this->list->get_head();
		url* next_cursor = current_cursor->get_next();

		while (current_cursor != next_cursor) {
			delete current_cursor;
			current_cursor = next_cursor;
			if (next_cursor != nullptr)
				next_cursor = next_cursor->get_next();
		}
	}
	this->size = 0;
	this->list->set_head(nullptr);
	this->list->set_tail(nullptr);
	//std::cout << "success" << std::endl;
}

void deque::print_deque() const
{
	url* cursor = this->list->get_tail();
	while (cursor != nullptr) {
		std::cout << cursor->get_data() << std::endl;
		cursor = cursor->get_prev();
	}
}

void deque::find_url(const std::string& url_name) const
{
	std::string name_to_find = url_name;
	std::string cursor_name{ "\0" };

	url* cursor = this->list->get_head();
	while (cursor != nullptr) {
		cursor_name = cursor->get_name();
		if (same_name(name_to_find, cursor_name)) {
			std::cout << "found " << cursor->get_data() << std::endl;
			return;
		}
		cursor = cursor->get_next();
	}
	std::cout << "not found " << name_to_find << std::endl;
}

std::string deque::get_front() const
{
	if (this->is_empty()) {
		return "failure";
	}
	else {
		url* first_url = this->list->get_head();
		std::string res = "front is " + first_url->get_data();
		first_url = nullptr;
		return res;
	}
}

std::string deque::get_back() const
{
	if (this->is_empty()) {
		return "failure";
	}
	else {
		url* last_url = this->list->get_tail();
		std::string res = "back is " + last_url->get_data();
		last_url = nullptr;
		return res;
	}
}

int deque::get_size() const
{
	return this->size;
}

bool deque::is_empty() const
{
	return (get_size() == 0);
}

bool deque::same_name(const std::string& name_1, const std::string& name_2) const
{
	std::string s1 = name_1;
	std::string s2 = name_2;

	//check if they are the same length
	if (s1.size() != s2.size()) return false;

	// convert s1 and s2 to lowercase
	for (std::size_t i{ 0 }; i < s1.size(); i++) {
		if (('A' <= s1[i]) && (s1[i] <= 'Z'))
			s1[i] += 32;
	}
	for (std::size_t i{ 0 }; i < s2.size(); i++) {
		if (('A' <= s2[i]) && (s2[i] <= 'Z'))
			s2[i] += 32;
	}

	//compare s1 and s2
	for (std::size_t i{ 0 }; i < s1.size(); i++) {
		if (s1[i] != s2[i]) return false;
	}

	return true;
}