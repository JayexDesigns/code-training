#include <iostream>

using namespace std;

template <typename T>
class Queue {

private:
  struct Item {
    T value;
    Item *next;
  };

  Item *first;
  Item *last;
  int _size;

  void copyItems(const Item *item, Item *(&first), Item *(&last), int &_size)
  {
    if (item == NULL) {
      first = NULL;
      last = NULL;
      _size = 0;
      return;
    }
    first = new Item();
    first->value = item->value;
    last = first;
    _size = 1;
    while (item->next != NULL) {
      last->next = new Item();
      last = last->next;
      item = item->next;
      last->value = item->value;
      _size++;
    }
    last->next = NULL;
  }


  void deleteItems(Item *item) {
    while (item != NULL) {
      Item *aux = item;
      item = item->next;
      delete aux;
    }
  }
  
public:

  Queue() {
    first = last = NULL;
    _size = 0;
  }

  Queue(Queue &q)
  {
    copyItems(q.first, first, last, _size);
  }

  ~Queue() {
    deleteItems(first);
    _size = 0;
  }

  Queue &operator=(const Queue &q) {
    if (this != &q) {
      deleteItems(first);
      copyItems(q.first, first, last, _size);
    }
    return *this;
  }

  T front() {
    if (first == NULL) {
      cerr << "Error: front on empty queue" << endl;
      exit(0);
    }
    return first->value;
  }

  void pop() {
    if (first == NULL) {
      cerr << "Error: pop on empty queue" << endl;
      exit(0);
    }
    Item *aux = first;
    first = first-> next;
    delete aux;
    _size--;
    if (first == NULL) last = NULL;
  }

  void push(T value) {
    if (first == NULL) {
      first = new Item();
      first->value = value;
      first->next = NULL;
      last = first;
      _size = 1;
      return;
    }
    last->next = new Item();
    last = last->next;
    last->value = value;
    _size++;
  }

  int size() {
    return _size;
  }

  template<typename U> friend ostream &operator<<(ostream &os, Queue<U> &q);

  template<typename U> friend istream &operator>>(istream &is, Queue<U> &q);
 
  // Pre:
  // Post: Al primer element de la cua implícita se li ha sumat
  //       el primer element de q,
  //       al segon element de la cua implícita se li ha sumat
  //       el segon element de q, i així successivament.
  //       Si la cua implícita era més llarga que q,
  //       llavors aquells elements extres no han canviat.
  //       Si q era més llarga que la cua implícita, llavors aquells elements
  //       extres de q han estat afegits al final de la cua implícita
  //       en el mateix ordre.
  // Descomenteu les següents dues linies i implementeu la funció:
    void operator+=(const Queue<T> &q) {
        Item *pitem1 = first;
        Item *pitem2;
        Item *qlast;
        int _qsize;
        copyItems(q.first, pitem2, qlast, _qsize);

        while (pitem1 != NULL && pitem2 != NULL) {
            pitem1->value += pitem2->value;
            pitem1 = pitem1->next;
            pitem2 = pitem2->next;
        }

        while (pitem2 != NULL) {
            push(pitem2->value);
            pitem2 = pitem2->next;
        }
    }
};


template<typename U>
ostream &operator<<(ostream &os, Queue<U> &q)
{
  os << q._size;
  for (typename Queue<U>::Item *item = q.first; item != NULL; item = item->next)
    os << " " << item->value;
  return os;
}

template<typename U>
istream &operator>>(istream &is, Queue<U> &q)
{
  int size;
  is >> size;
  if (size == 0) {
    q = Queue<U> ();
    return is;
  }
  for (int i = 0; i < size; ++i) {
    U x;
    cin >> x;
    q.push(x);
  }
  return is;
}
