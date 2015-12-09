/** @file PlainBox.cpp*/
#include"PlainBox.h"

PlainBox::PlainBox(){
	
}//end fault constructor

PlainBox::PlainBox(const ItemType& theItem){
	item=theItem;
}// end constructor

void PlainBox::setItem(cnost ItemType& theItem){
	item=theItem;
}//end setItem

ItemType PlainBox::getItem() const{
	return item;
}//end getItem
