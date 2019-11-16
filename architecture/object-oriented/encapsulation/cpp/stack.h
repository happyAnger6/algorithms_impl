#ifndef _STACK_H
#define _STACK_h

class Item{
public:
	Item();
};

class Stack{
public:
	Stack();
	Item Pop();

private:
	vector<Item> datas;	
};

#endif
