#include <iostream>
#include <ctime>

struct msg {
	msg() {
		prev = nullptr;
	}
	//char* currency_name_fst;
	double currency_amt_fst;
	//char* currency_name_scd;
	double currency_amt_scd;
	msg* prev;
};


msg* glob_top(nullptr);


msg* create_msg(), *pop();
void init_msg(msg*), push(msg*);
bool is_empty();
void del(msg*), fill_stack(int), read(int);


void main() {
	int size;
	std::cin >> size;
	fill_stack(size);
	read(size);

	std::cin.get(); std::cin.get();
}


msg* create_msg() {
	return new msg();
}


void init_msg(msg* msg_ptr) {
	srand(time(0));
	double randy = (double)(rand()) / RAND_MAX * 10000;
	msg_ptr->currency_amt_fst = randy;
	randy = (double)(rand()) / RAND_MAX * 10000;
	msg_ptr->currency_amt_scd = randy;
}



void push(msg* msg_ptr) {
	if (!is_empty()) {
		msg_ptr->prev = glob_top;
	}
	glob_top = msg_ptr;
}


msg* pop() {
	if (!is_empty()) {
		msg* top = glob_top;
		glob_top = glob_top->prev;
		return top;
	}
	std::cout << "stack is empty";
	return NULL;
}


bool is_empty() {
	return glob_top == nullptr;
}


void del(msg* msg_ptr) {
	delete msg_ptr;
}


void fill_stack(int size) {
	for (size_t i = 0; i < size; ++i) {
		msg* msg_ptr = create_msg();
		init_msg(msg_ptr);
		push(msg_ptr);
	}
}


void read(int size) {
	for (size_t i = 0; i < size; ++i) {
		msg* el = pop();
		std::cout << el->currency_amt_fst << ' ' << el->currency_amt_scd << '\n';
		del(el);
	}
}