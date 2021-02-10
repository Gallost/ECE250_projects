#pragma once
#include "url.h"

class linked_list
{
private:
	url* head;
	url* tail;

public:
	linked_list();
	~linked_list();

	void set_head(url* head_url);
	void set_tail(url* tail_url);
	url* get_head() const;
	url* get_tail() const;
};