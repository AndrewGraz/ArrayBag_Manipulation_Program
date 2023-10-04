#include "ArrayBag.h"
#include <iostream>
#include <cstddef>
using namespace std;


template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor

template<class ItemType>
void ArrayBag<ItemType>::bubbleSort()
{
   int nextIndex;
   bool isSorted = false;
   //loops while it is unsorted
   while(isSorted == false)
   {
      isSorted = true;
      //goes through each index to and compares how big they are
      for (int index = 0; index < itemCount - 1; index++)
      {
         nextIndex = index +1;
         if (items[index] > items[nextIndex])
         {
            std::swap(items[index], items[nextIndex]);
            isSorted = false;
         }//end if 
      }//end For Loop
   } //end while loop
}  // end bubbleSort


template<class ItemType>
int ArrayBag<ItemType>::binarySearchIterative(const ItemType& inputer)
{
   bool ifFound = false; 
   //gets the index
   int index;
   //gets the first index
   int firstHalf = 0, 
       //gets last index
      lastHalf = itemCount - 1, 
      //finds the midpoint
      midPoint = firstHalf + (lastHalf - firstHalf) / 2; 
   
   //repats while the index and the loop does not go past the boggest index
   while ((ifFound == false) && (lastHalf >= firstHalf))
   {
      //if input is midpoint index is input 
      if(inputer == items[midPoint])
      {     
         ifFound = true;
         index = midPoint;
      }
      //if input is not the midpoint repeats until the index is found
      else if(inputer < items[midPoint])
      {
         midPoint--;
      }
      else if (inputer > items[midPoint])
      {
         midPoint++;
      }//end if
   }//end while loop
   return index;
}  // end binarySearchIterative

template<class ItemType>
int ArrayBag<ItemType>::binarySearchRecursive(const ItemType& inputer)
{
    int firstHalf = 0; // gets the first index
    int lastHalf = itemCount - 1; // gets the last index

    // Use the helper function to perform the binary search
    return binarySearchRecursiveHelper(firstHalf, lastHalf, inputer);
} // end binarySearchRecursive


template<class ItemType>
int ArrayBag<ItemType>::binarySearchRecursiveHelper(int firstHalf, int lastHalf, ItemType inputer)
{
    if (lastHalf < firstHalf)
    {
        // The item was not found in the bag
        return -1;
    }
    
    int midPoint = firstHalf + (lastHalf - firstHalf) / 2;

    if (inputer == items[midPoint])
    {
        // Item found, return the index
        return midPoint;
    }
    else if (inputer < items[midPoint])
    {
        // Item may be in the left half
        return binarySearchRecursiveHelper(firstHalf, midPoint - 1, inputer);
    }
    else
    {
        // Item may be in the right half
        return binarySearchRecursiveHelper(midPoint + 1, lastHalf, inputer);
    }
} // end binarySearchRecursiveHelper


template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
    bool hasRoomToAdd = (itemCount < maxItems);
    if (hasRoomToAdd)
    {
        items[itemCount] = newEntry;
        itemCount++;
    }  // end if
    
    return hasRoomToAdd;
}  // end add


template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
   int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if
    
	return canRemoveItem;
}  // end remove

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}  // end clear

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int curIndex = 0;       // Current array index
   while (curIndex < itemCount)
   {
      if (items[curIndex] == anEntry)
      {
         frequency++;
      }  // end if
      
      curIndex++;          // Increment to next entry
   }  // end while
   
   return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains

template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
   std::vector<ItemType> bagContents;
	for (int i = 0; i < itemCount; i++)
		bagContents.push_back(items[i]);
      
   return bagContents;
}  // end toVector

// private
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
	bool found = false;
   int result = -1;
   int searchIndex = 0;
   
   // If the bag is empty, itemCount is zero, so loop is skipped
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
      }  // end if
   }  // end while
   
   return result;
}  // end getIndexOf

/******************************************************************************/
/* Function:   void bagAdder
/  Inputs:     an ArrayBag object 
/  Outputs:    void, no outputs, but adds numbers to bag
/             
/  Purpose:    a method to add numbers to the bag
/             
/******************************************************************************/
void bagAdder(ArrayBag<int>& bag)
{ 
   //used to ge the number to add to bag
	int adder; 
    cout << "Enter value to add: \n";
    cin >> adder;
    //if the bag does not contain the added number, it will add number
    if(!(bag.contains(adder)))
    {
    	bag.add(adder);
    }
   //else the number does not get added sinc it was in bag 
    else
    {
       cout << "Value entered was in bag. \n";
    }// end if
	bag.bubbleSort();//resort

}// end bagAdder

/******************************************************************************/
/* Function:   bagRemover
/  Inputs:     an ArrayBag object 
/  Outputs:    void, no outputs, but removes numbers from bag
/             
/  Purpose:    a method to remove numbers from the bag
/             
/******************************************************************************/
void bagRemover(ArrayBag<int>& bag)
{
   //used to get the number to remove from the bag
	int remover; 
    cout << "Enter value to remove: \n";
    cin >> remover;
   //if the bag contains the added number, it will remove number
    if(bag.contains(remover))
    {
    	bag.remove(remover);
    }
    //else the number does not get removed from  bag 
    else
    {
       cout << "Value entered was not in bag. \n";
    }// end if
	bag.bubbleSort();//resort
}// end bagRemover

/******************************************************************************/
/* Function:   FindIterative
/  Inputs:     an ArrayBag object, and didSort which checks to see if
/                     bag was sorted
/  Outputs:    void, no outputs, but displays the index of a number
/             
/  Purpose:    a method to display numbers inside of a bag using the 
/                 binarySearchIterative
/             
/******************************************************************************/
void FindIterative(ArrayBag<int>& bag,  int& didSort)
{
   //used to identify what number clientNum wants to find index of 
	int clientNum;
   //checks to see if numbers are sorted
	if (didSort >= 1)
	{
      //if sorted and is inside of bag gets number user wnats to get  index of and displays 
		cout << "Enter the value to find: \n";
		cin >> clientNum; 
		if(bag.contains(clientNum))
		{
			cout << "The value found: " << bag.binarySearchIterative(clientNum) << "\n";	
		}
      //if number does not exit in bag, lets user know
		else if(!(bag.contains(clientNum)))
		{
			cout<< "That value does not exist. \n";
		}// end if
	}
   //tells user they did not sort
	else
	{
		cout << "You did not sort. \n";
	}// end if
}// end FindIterative

/******************************************************************************/
/* Function:   FindRecursive
/  Inputs:     an ArrayBag object, and didSort which checks to see if
/                     bag was sorted
/  Outputs:    void, no outputs, but displays the index of a number 
/             
/  Purpose:    a method to display numbers inside of a bag using the 
/                 binarySearchRecursive   
/******************************************************************************/
void FindRecursive(ArrayBag<int>& bag,  int& didSort)
{
   //used to identify what number clientNum wants to find index of
	int clientNum;
   //checks to see if numbers are sorted
	if (didSort >= 1)
	{
      //if sorted and is inside of bag gets number user wnats to get  index of and displays 
		cout << "Enter the value to find: \n";
		cin >> clientNum; 
		if(bag.contains(clientNum))
		{
			cout << "The value found: " << bag.binarySearchRecursive(clientNum)<< "\n";
		}
      //if number does not exit in bag, lets user know
		else if(!(bag.contains(clientNum)))
		{
			cout<< "That value does not exist. \n";
		}// end if
	}
   //tells user they did not sort
	else
	{
		cout << "You did not sort. \n";
	}// end if
}// end FindRecursive

/******************************************************************************/
/* Function:   displaylist
/  Inputs:     an ArrayBag object
/  Outputs:    displays whats inside of the bag 
/             
/  Purpose:    displays whats inside of the bag so the client knows whats there
/             
/******************************************************************************/
void displaylist(ArrayBag<int>& bag)
{
   //allows for the numbers to be contained
	vector<int> bagList;
	bagList = bag.toVector();
   //displays everything inside of bag
	for(int i = 0; i < bagList.size(); i++)
	{
		cout << bagList[i] << " ";
	}//end For Loop
	
}// end displaylist

/******************************************************************************/
/* Function:   bagSort
/  Inputs:     an ArrayBag object, and didSort which checks to see if
/                     bag was sorted
/  Outputs:    no outputs but sorts the bag and changes didSort
/             
/  Purpose:    a method to sort the array in ascending order using the bubble sort
/                       and makes certain that the bag is sorted
/             
/******************************************************************************/
void bagSort(ArrayBag<int>& bag, int& didSort)
{
	bag.bubbleSort();
	didSort++ ; 
}
