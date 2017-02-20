#include <gtest/gtest.h>
#include "GildedRose.h"

TEST(GildedRoseTest, QuailtyNeverNegative)
{
	vector<Item> items;
	items.push_back(Item("NeverNegativeItem", 10, 10));
	GildedRose app(items);
	app.updateQuality();
	EXPECT_FALSE(app.items[0].quality < 0);
}

TEST(GildedRoseTest, QualityDegradeIncreasePastSellDate)
{
	vector<Item> items;
	items.push_back(Item("DegradeItem", 6, 18));
	GildedRose app(items);
	for (int day = 0; day <= 10; day++)
	{
		app.updateQuality();
	}

	EXPECT_EQ(2, app.items[0].quality);
}

void example()
{
    vector<Item> items;
    items.push_back(Item("+5 Dexterity Vest", 10, 20));
    items.push_back(Item("Aged Brie", 2, 0));
    items.push_back(Item("Elixir of the Mongoose", 5, 7));
    items.push_back(Item("Sulfuras, Hand of Ragnaros", 0, 80));
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 15, 20));
    items.push_back(Item("Conjured Mana Cake", 3, 6));
    GildedRose app(items);
    app.updateQuality();
}
