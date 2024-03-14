#include <string>

template <typename V>
class Mapnode{
public:
	string key;
	V val;
	Mapnode<V> *next;

	Mapnode(string key,V val){
		this->key = key;
		this->val = val;
		next = NULL;
	}
	~Mapnode(){
		delete next;
	}
};

template <typename V>
class MyMap{
private:
	int hash_key(string key){
		int hashedcode = 0;
		int coff = 1;
		for(int i=0;i<key.length();i++){
			hashedcode += coff * key[i];
			hashedcode = hashedcode % capacity;
			coff*= 19;
			coff= coff % capacity;
		}
		return hashedcode % capacity;
	}

	void rehash(){
		Mapnode<V>** temp = bucket;
		bucket = new Mapnode<V>*[2*capacity];
		int old_capacity = capacity;
		capacity*=2;
		size=0;
		for(int i=0;i<capacity;i++){
			bucket[i]= NULL;
		}
		for(int i=0; i<old_capacity;i++){
			Mapnode<V> *head = temp[i];
			while(head!=NULL){
				insert(head->key,head->val);
				head=head->next;
			}
		}
		for(int i=0;i<old_capacity;i++){
			delete temp[i];
		}
		delete [] temp;
	}

public:
	int capacity;
	int size;
	Mapnode<V>** bucket;
	MyMap(){
		capacity= 5;
		size= 0;
		bucket = new Mapnode<V>*[capacity];
		for(int i=0; i<capacity; i++){
			bucket[i] = NULL;
		}
	}
	~MyMap(){
		for(int i=0; i<capacity; i++){
			delete bucket[i];
		}
	}

	void insert(string key,V val){
		int hashedcode = hash_key(key);
		Mapnode<V>* head = bucket[hashedcode];
		while(head!=NULL){
			if(key==head->key){
				head->val = val;
				return;
			}
			head=head->next;
		}
		head = bucket[hashedcode];
		Mapnode<V> *newnode = new Mapnode<V>(key,val);
		newnode->next = head;
		bucket[hashedcode] = newnode;
		size++;
		if((1.0*size)/capacity>0.7) rehash();
	}

	V remove(string key){
		int hashedcode = hash_key(key);
		Mapnode<V>* head = bucket[hashedcode];
		Mapnode<V>* prev = NULL;
		while(head!=NULL){
			if(head->key == key){
				if(prev==NULL) bucket[hashedcode]= head->next;
				else prev->next= head->next;
				head->next= NULL;
				V value= head->val;
				delete head;
				size--;
				return value;
			}
			prev=head;
			head=head->next;
		}
		return 0;
	}

	V get_value(string key){
		int hashedcode = hash_key(key);
		Mapnode<V>* head = bucket[hashedcode];
		while(head!=NULL){
			if(head->key == key){
				return head->val;
			}
			head=head->next;
		}
		return -1;
	}

};
