/** @file PlainBoxT.cpp */

template<class ItemType>
PlainBox<ItemType>::PlainBox(){
	
}// end default constructor

template<class ItemType>
PlainBox<ItemType>::PlainBox(const ItemType& theItem){
	item=theItem;
}//end constructor

template<class ItemType>
void PlainBox<ItemType>::setItem(const ItemType& theItem){
	item=theItem;
}//end setItem

template<class ItemType>
ItemType PlainBox<ItemType>::getItem(){
	return item;
}//end getItem
