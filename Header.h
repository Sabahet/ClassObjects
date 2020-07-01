//
//  Header.h
//  LAB 1 326
//
//  Created by Sabahet Alovic on 1/28/20.
//  Copyright © 2020 Sabahet Alovic. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include <iostream>
#include <vector>
using namespace std;


template<class ItemType>
class Bag
{
private:
    static const int DEFAULT_BAG_SIZE = 6;
    ItemType items[DEFAULT_BAG_SIZE]; // array of bag items
       int itemCount;                    // current count of bag items
      int maxItems;                     // max capacity of the bag
   
       // Returns either the index of the element in the array items that
       // contains the given target or -1, if the array does not contain
       // the target.
       int getIndexOf(const ItemType& target) const;

public:
    Bag();
    int getCurrentSize() const;
    bool isEmpty() const;
    bool add(const ItemType& newEntry);
    bool remove(const ItemType& anEntry);
    void clear();
    bool contains(const ItemType& anEntry) const;
    int getFrequencyOf(const ItemType& anEntry) const;
    void displayBagContents()const;
    int getFrequency(ItemType x)const;
        std::vector<ItemType> toVector() const;
    string fragile(int x);
    int destroy(string x);

};  // end Bag



#endif
