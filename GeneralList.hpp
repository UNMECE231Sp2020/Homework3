#include <iostream>

template <class T>
class List {
	private:
		struct _list {
			T value;
			struct _list *next;
			struct _list *prev;
		};
		typedef struct _list Dlist;

		size_t _size;
		Dlist *_front;
		Dlist *_back;

		void reccopy(const Dlist *ptr) {
			if(ptr) { 
			// We can also use:
			// if(ptr != nullptr) {
				reccopy(ptr->next);
				push_front(ptr->value);
			}
		}
	public:
		List() : _size{0}, _front{nullptr}, _back{nullptr} {
			
		}

		List(const List &list) : _size{0}, _front{nullptr}, _back{nullptr} {
			reccopy(list._front);
		}

		~List() {
			while(!empty()) {
			//while(_size > 0) {
				pop_front();
			}
		}

		T front() const {
			return _front->value;
		}

		T back() const {
			return _back->value;
		}

		size_t size() const {
			return _size;
		}

		size_t length() const {
			return _size;
		}

		void push_front(T data) {
			Dlist *newNode = new Dlist;
			newNode->value = data;

			if(_front==nullptr) {
				newNode->next=nullptr;
			}
			else {
				newNode->next=_front;
			}

			_front=newNode;
			_size++;
		}

		void push_back(T data) {
			Dlist *newNode = new Dlist;
			newNode->value = data;
			newNode->next=nullptr;

			if(_back!=nullptr) {
				_back->next=newNode;
				newNode->prev = _back;
			}

			if(_front==nullptr) {
				_front=newNode;
				newNode->prev = nullptr;
			}

			_back=newNode;
			_size+=1;
		}

		void pop_front() {
			Dlist *front_to_delete = _front;
			_front = _front->next;

			if(_front==nullptr) {
				_back = nullptr;
			}
			else {
				_front->prev = nullptr;
			}

			delete front_to_delete;
			_size -= 1;
		}

		//CONVERT THIS FUNCTION
		void pop_back() {
			Llist *back_to_remove = _back;

			if(_front->next!=nullptr) {
				Llist *new_back = _front;
				while(new_back->next!=_back) {
					new_back=new_back->next;
				}
				new_back->next=nullptr;
				_back=new_back;
			}
			else {
				_front=nullptr;
				_back=nullptr;
			}

			delete back_to_remove;
			_size-=1;
		}

		// leave this alone
		bool empty() const {
			return ((_front==nullptr) && (_back==nullptr));
		}

		//Modify this
		void print() {
			Llist *temp;
			for(temp=_front; temp!=nullptr; temp=temp->next) {
				std::cout << temp->value << " ";
			}
			std::cout << std::endl;
		}
};
