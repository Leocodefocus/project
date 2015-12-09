/*@file ToyBox.h*/
#ifndef _TOY_BOX
#define _TOY_BOX
#include "PlainBoxT.h"
enum Color {BLACK,RED,BLUE,GREEN,YELLOW,WHITE};

template<class ItemType>
class ToyBox:public PlainBox<ItemType>{
	private:
		Color boxColor;
	public:
		ToyBox();
		ToyBox(const Color& theColor);
		ToyBox(const ItemType& theItem,const Color& theColor);
		Color getColor() const;
};
#include"ToyBox.cpp" 
#endif
