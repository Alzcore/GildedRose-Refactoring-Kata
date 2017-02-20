#include "GildedRose.h"
#include <iostream>

using namespace std;

GildedRose::GildedRose(vector<Item> & items) : items(items)
{}
    
void GildedRose::updateQuality() 
{
	for (int i = 0; i < items.size(); i++)
	{
		if (items[i].name == "Backstage passes to a TAFKAL80ETC concert")
		{
			if (items[i].sellIn == -1)
			{
				ChangeItemQuality(0, true, items[i]);
			}
			else if (items[i].sellIn >= 0)
			{
				ChangeItemQuality(GetQualityIncreaseRateBasedOffSellInDay(items[i].sellIn), false, items[i]);
			}
		}
		else if (items[i].name == "Aged Brie")
		{
			ChangeItemQuality(1, false, items[i]);
		}
		else if (items[i].name != "Sulfuras, Hand of Ragnaros")
		{
			if (items[i].name == "Conjured Mana Cake")
			{
				ChangeItemQuality(GetQualityDecreaseRateBasedOffSellInDay(items[i].sellIn, 2), false, items[i]);
			}
			else
			{
				ChangeItemQuality(GetQualityDecreaseRateBasedOffSellInDay(items[i].sellIn, 1), false, items[i]);
			}			
		}

		items[i].sellIn -= 1;
	}
}

void GildedRose::ChangeItemQuality(int ChangeAmount, bool ResetToZero, Item& Item)
{
	if (ResetToZero || (Item.quality + ChangeAmount) < 0)
	{
		Item.quality = 0;
		return;
	}

	if ((Item.quality + ChangeAmount) > 50)
	{
		Item.quality = 50;
		return;
	}

	Item.quality += ChangeAmount;
}

int GildedRose::GetQualityIncreaseRateBasedOffSellInDay(int SellInDay)
{
	if (SellInDay <= 5)
	{
		return 3;
	}
	else if (SellInDay <= 10)
	{
		return 2;
	}

	return 1;
}

int GildedRose::GetQualityDecreaseRateBasedOffSellInDay(int SellInDay, int DecreaseMultiplier)
{
	if (SellInDay < 0)
	{
		return -2 * DecreaseMultiplier;
	}

	return -1 * DecreaseMultiplier;
}

