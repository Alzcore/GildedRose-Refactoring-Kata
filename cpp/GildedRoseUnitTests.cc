#include <gtest/gtest.h>
#include "GildedRose.h"

TEST(GildedRoseTest, QualityNeverNegative)
{
	vector<Item> items;
	items.push_back(Item("NewItem", 10, 10));
	GildedRose app(items);
	app.updateQuality();
	EXPECT_FALSE(app.items[0].quality < 0);
}

TEST(GildedRoseTest, QualityNeverExceedsFifty)
{
	vector<Item> items;
	items.push_back(Item("Aged Brie", 30, 45));
	GildedRose app(items);
	for (int day = 0; day <= 30; day++)
	{
		app.updateQuality();
	}
	EXPECT_FALSE(app.items[0].quality > 50);
}

TEST(GildedRoseTest, QualityDegradeRateIncreasePastSellDate)
{
	vector<Item> items;
	items.push_back(Item("NewItem", 6, 18));
	GildedRose app(items);
	for (int day = 0; day <= 10; day++)
	{
		app.updateQuality();
	}

	EXPECT_EQ(2, app.items[0].quality);
}

TEST(GildedRoseTest, SellInValueDecreases)
{
	vector<Item> items;
	items.push_back(Item("NewItem", 6, 18));
	GildedRose app(items);
	app.updateQuality();
	EXPECT_EQ(5, app.items[0].sellIn);
}

TEST(GildedRoseTest, QualityRateIncreasesCloserToSellInDate)
{
	vector<Item> items;
	items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 20, 0));
	GildedRose app(items);
	for (int day = 0; day <= 20; day++)
	{
		app.updateQuality();
		if (day == 10)
		{
			EXPECT_EQ(12, app.items[0].quality);
		}
		else if (day == 15)
		{
			EXPECT_EQ(23, app.items[0].quality);
		}
	}
}

TEST(GildedRoseTest, QualityChangesToZeroAfterSellInDate)
{
	vector<Item> items;
	items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 20, 0));
	GildedRose app(items);
	for (int day = 0; day <= 21; day++)
	{
		app.updateQuality();
	}

	EXPECT_EQ(0, app.items[0].quality);
}

TEST(GildedRoseTest, SulfurasDoesNotDecreaseInQuality)
{
	vector<Item> items;
	items.push_back(Item("Sulfuras, Hand of Ragnaros", 0, 80));
	GildedRose app(items);
	app.updateQuality();

	EXPECT_EQ(80, app.items[0].quality);
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
