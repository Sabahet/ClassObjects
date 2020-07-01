
#include <iostream>
#include "Header.h"
#include <cstring>
#include <string>


//Print the count returned by the function and the contents of the bag after the function executes using the displayBagContents member function that you added to the Bag class.

int main() {
    
    Bag <string> Fragile;
    Bag <string> Norm;
    
    cout << "Normal Bag contents" << endl;
    Norm.add("Milk");
     Norm.add("Cookies");
     Norm.add("Cookies");
     Norm.add("Eggs");
     Norm.add("Bread");
     Norm.add("Water");
    Norm.displayBagContents();
    
    cout << endl;
    cout << "The frequency of cookies is " << Norm.getFrequency("Cookies");
       cout << endl << endl;



    
    for (int i = 0; i < Norm.getCurrentSize()+1; i++){
        if(Norm.fragile(i) == "Eggs"){
            Fragile.add("Eggs");
            Norm.remove("Eggs");

        }
         if(Norm.fragile(i)  == "Bread"){
                  Fragile.add("Bread");
                  Norm.remove("Bread");
             
    }
    }
    
    
    cout << "Fragile Bag Contents" << endl;
    Fragile.displayBagContents();
    cout << endl;
    
    cout << "After Destroy Cookies was called:" << endl;
    cout << Norm.destroy("Cookies") << " Of the selected item was deleted";
    cout << endl << endl;
    
    
    cout << "End result of normal bag" << endl;
    
    Norm.displayBagContents();
    cout << endl;
}

    template<class ItemType>
    Bag<ItemType>::Bag() : itemCount(0), maxItems(DEFAULT_BAG_SIZE)
    {
    }

    template<class ItemType>
    int Bag<ItemType>::getCurrentSize() const
    {
        return itemCount;
    }

    template<class ItemType>
    bool Bag<ItemType>::isEmpty() const
    {
        return itemCount == 0;
    }

// ADD FUNCTION


    template <class ItemType>
    bool Bag<ItemType>:: add(const ItemType &newEntry){
        bool canAddItem = itemCount <=5;
        if(canAddItem){
            items[itemCount]= newEntry;
            itemCount++;

            
        }
        return canAddItem;
}


    template<class ItemType>
    bool Bag<ItemType>::remove(const ItemType& anEntry)
    {
       int locatedIndex = getIndexOf(anEntry);
        bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
        if (canRemoveItem)
        {
            itemCount--;
            items[locatedIndex] = items[itemCount];
        }
        
        return canRemoveItem;
    }

    template<class ItemType>
    void Bag<ItemType>::clear()
    {
        itemCount = 0;
    }



    template<class ItemType>
    bool Bag<ItemType>::contains(const ItemType& anEntry) const
    {
        return getIndexOf(anEntry) > -1;
    }


    template<class ItemType>
    std::vector<ItemType> Bag<ItemType>::toVector() const
    {
        std::vector<ItemType> bagContents;
        for (int i = 0; i < itemCount; i++)
            bagContents.push_back(items[i]);
       return bagContents;
    }

    
    template<class ItemType>
    int Bag<ItemType>::getIndexOf(const ItemType& target) const
    {
        bool found = false;
       int result = -1;
       int searchIndex = 0;
       // if the bag is empty, itemCount is zero, so loop is skipped
       while (!found && (searchIndex < itemCount))
       {
          if (items[searchIndex] == target)
          {
             found = true;
             result = searchIndex;
          }
          else
          {
             searchIndex++;
          }
       }
       return result;
    }
template<class ItemType>
void Bag<ItemType> ::displayBagContents()const{
   
    for (int i =0; i<= itemCount-1; i++){
        cout << items[i] << endl;
    }
}
template<class ItemType>
int Bag<ItemType> :: getFrequency(ItemType x)const{
    
    int fre = 0;
    for (int i = 0; i < 1; i++){
        for (int j = 0; j < itemCount; j++)
        if(x == items[j]){
            fre++;

        }
        }
            return(fre);
}

template<class ItemType>
 string Bag<ItemType> :: fragile(int x){
     
     return(items[x]);
    
    
}

template<class ItemType>
int Bag<ItemType> :: destroy(string x){
    int z= getFrequency(x);
        for (int j = 0; j < itemCount; j++)
        if(x == items[j]){
            remove(x);

        }
    
    
    return(z);

}


