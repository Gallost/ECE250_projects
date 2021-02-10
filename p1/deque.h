#pragma once
#include "url.h"
#include "linked_list.h"

class deque
{
private:
	linked_list* list;
	int size;

public:
	deque();
	~deque();

	void push_front(const std::string& url_name_in, const std::string& url_val_in);
	void push_back(const std::string& url_name_in, const std::string& url_val_in);
	void pop_front();
	void pop_back();
	void clear_deque();

	void print_deque() const;
	void find_url(const std::string& url_name) const;
	std::string get_front() const;
	std::string get_back() const;
	int get_size() const;
	bool is_empty() const;

	//helper function
	bool same_name(const std::string& name_1, const std::string& name_2) const;
};