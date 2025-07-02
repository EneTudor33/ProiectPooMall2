#include "functii_data.h"

const DataCalendaristica azi{ 2, 7, 2025 };

long AnInZi(DataCalendaristica d)
{
	int lungimi_luni[13] = {0,31,28,31,30,31,30,31,31,30,31,30,3};
	long zile = 365L * d.an;
	for (int i = 1;i < d.luna;i++)
	{
		zile = zile + lungimi_luni[i];
	}
	zile = zile+d.zi;
	return zile;
}
bool Sub60Zile(DataCalendaristica d)
{
	long diferenta = AnInZi(azi) - AnInZi(d);
	return (diferenta >= 0 && diferenta <= 60);
}