#include <iostream>

using namespace std;

template <typename T>
class List {
private:
  
  // Items:
  
  class Item {
  public:
    T value;
    Item *next;
    Item *prev;
  };

  // Data:
  
  int _size;
  Item iteminf,itemsup;

  // Helper functions:
  void insertItem(Item *pitemprev, Item *pitem) {
    pitem->next = pitemprev->next;
    pitem->next->prev = pitem;
    pitem->prev = pitemprev;
    pitemprev->next = pitem;
    _size++;
  }
  
  void insertItem(Item *pitemprev, const T &value) {
    Item *pitem = new Item();
    pitem->value = value;
    insertItem(pitemprev, pitem);
  }

  void removeItem(Item *pitem) {
    pitem->next->prev = pitem->prev;
    pitem->prev->next = pitem->next;
    delete pitem;
    _size--;
  }
  
  void removeItems() {
    while (_size > 0)
      removeItem(iteminf.next);
  }
  
public:

  // Constructors/Destructors:
  
  List() {
    _size = 0;
    iteminf.next = &itemsup;
    itemsup.prev = &iteminf;
  }

  List(List &l) {
    for (Item *pitem = l.itemsup.prev; pitem != &l.iteminf; pitem = pitem->prev)
      insertItem(&iteminf, pitem->value);
  }

  ~List() {
    removeItems();
  }

  // Assignment:
  
  List &operator=(const List &l) {
    if (this != &l) {
      removeItems();
      for (Item *pitem = l.itemsup.prev; pitem != &l.iteminf; pitem = pitem->prev)
	insertItem(&iteminf, pitem->value);
    }
    return *this;
  }

  // Standard operations:
  
  int size() {
    return _size;
  }

  void push_back(const T &value) {
    insertItem(itemsup.prev, value);
  }
  
  void push_front(const T &value) {
    insertItem(&iteminf, value);
  }

  void pop_back() {
    if (_size == 0) {
      cerr << "Error: pop_back on empty list" << endl;
      exit(1);
    }
    removeItem(itemsup.prev);
  }

  void pop_front() {
    if (_size == 0) {
      cerr << "Error: pop_front on empty list" << endl;
      exit(1);
    }
    removeItem(iteminf.next);
  }


  // Read and write:
  
  template <typename U> friend istream &operator>>(istream &is, List<U> &l);

  template <typename U> friend ostream &operator<<(ostream &os, List<U> &l);


  // Iterators:
  
  class iterator {
    friend class List;
  private:
    List *plist;
    Item *pitem;
  public:
    
    void operator++()
    {
      if (pitem == &(plist->itemsup)) {
	cerr << "Error: ++iterator at the end of list" << endl;
	exit(1);
      }
      pitem = pitem->next;
    }
    
    void operator++(int)
    {
      if (pitem == &(plist->itemsup)) {
	cerr << "Error: iterator++ at the end of list" << endl;
	exit(1);
      }
      pitem = pitem->next;
    }

    void operator--()
    {
      if (pitem == plist->iteminf.next) {
	cerr << "Error: --iterator at the beginning of list" << endl;
	exit(1);
      }
      pitem = pitem->prev;
    }

    void operator--(int)
    {
      if (pitem == plist->iteminf.next) {
	cerr << "Error: iterator-- at the beginning of list" << endl;
	exit(1);
      }
      pitem = pitem->prev;
    }

    T &operator*()
    {
      return pitem->value;
    }

    bool operator==(iterator &it) {
      return plist == it.plist and pitem == it.pitem;
    }

  };

  // Operations with iterators:
  
  iterator begin()
  {
    iterator it;
    it.plist = this;
    it.pitem = iteminf.next;
    return it;
  }
    
  iterator end()
  {
    iterator it;
    it.plist = this;
    it.pitem = &itemsup;
    return it;
  }

  iterator insert(iterator it, T value) {
    if (it.plist != this) {
      cout << "Error: insert with an iterator not on this list" << endl;
      exit(1);
    }
    insertItem(it.pitem->prev, value);
    it.pitem = it.pitem->prev;
    return it;
  }

  iterator erase(iterator it) {
    if (it.plist != this) {
      cout << "Error: erase with an iterator not on this list" << endl;
      exit(1);
    }
    if (it.pitem == &itemsup) {
      cout << "Error: erase with an iterator pointing to the end of the list" << endl;
      exit(1);
    }
    it.pitem = it.pitem->next;
    removeItem(it.pitem->prev);
    return it;
  }
    
  // Pre:  it1,it2 apunten a elements de la llista implícita.
  // Post: it1,it2 continuen apuntant als mateixos elements,
  //       i *it1, *it2 continuen valent el mateix que abans.
  //       però *it1 ocupa la posició que ocupava abans *it2,
  //       i *it2 ocupa la posició que ocupava abans *it1.
  //       A part d'això, res més ha canviat.
  // Descomenteu les següents dues linies i implementeu el mètode:
    void swapPositionsOfItems(iterator &it1, iterator &it2) {
        Item* pItem1 = it1.pitem;
        Item* pItem1Prev = pItem1->prev;
        Item* pItem1Next = pItem1->next;
        Item* pItem2 = it2.pitem;
        Item* pItem2Prev = pItem2->prev;
        Item* pItem2Next = pItem2->next;

        if (pItem1Next == pItem2) {
            pItem1->next = pItem2->next;
            pItem1->next->prev = pItem1;
            pItem2->prev = pItem1->prev;
            pItem2->prev->next = pItem2;
            pItem1->prev = pItem2;
            pItem2->next = pItem1;
        }
        else if (pItem1Prev ==  pItem2) {
            pItem1->prev = pItem2->prev;
            pItem1->prev->next = pItem1;
            pItem2->next = pItem1->next;
            pItem2->next->prev = pItem2;
            pItem1->next = pItem2;
            pItem2->prev = pItem1;
        }
        else {
            pItem1->next->prev = pItem2;
            pItem1->prev->next = pItem2;
            pItem2->next->prev = pItem1;
            pItem2->prev->next = pItem1;
            pItem1->prev = pItem2Prev;
            pItem1->next = pItem2Next;
            pItem2->prev = pItem1Prev;
            pItem2->next = pItem1Next;
        }
    }
};

// Implementation of read and write lists.

template <typename T> istream &operator>>(istream &is, List<T> &l)
{
  l.removeItems();
  int size;
  cin >> size;
  for (int i = 0; i < size; ++i) {
    T value;
    cin >> value;
    l.insertItem(l.itemsup.prev, value);
  }
  return is;
}

template<typename T> ostream &operator<<(ostream &os, List<T> &l)
{
  os << l._size;
  for (typename List<T>::Item* pitem = l.iteminf.next; pitem != &l.itemsup; pitem = pitem->next)
    cout << " " << pitem->value;
  return os;
}

