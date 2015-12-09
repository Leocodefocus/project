/** @file PlainBoxT.h*/

#ifndef _PLAIN_BOX_T
#define _PLAIN_BOX_T

template<class ItemType>  //Indicates this is a templatedefinition

//Declaration for the class PlainBoxT
class PlainBox{
	private:
		//Data field
		ItemType item;
	
	public:
		//Default constructor
		PlainBox();
		
		//Parameterized constructor
		PlainBox(const ItemType& theItem);

		//Mutator method that can change the value of the data field
		void setItem(const ItemType& theItem);

		//Accessor method to get the value of the data field
		ItemType getItem() const;
};//end PlainBox
#include "PlainBoxT.cpp"
#endif
