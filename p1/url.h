#pragma once
#include <string>

class url
{
private:
	std::string url_name;
	std::string url_val;
	url* next;
	url* prev;

public:
	url(const std::string& name_in, const std::string& val_in);
	~url();

	void set_next(url* next_url);
	void set_prev(url* prev_url);
	url* get_next() const;
	url* get_prev() const;
	std::string get_data() const;
	std::string get_name() const;
};