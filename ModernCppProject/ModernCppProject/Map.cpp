#include "Map.h"

void Map::setWidth(size_t width) {
	kWidth = width;
}

void Map::setHeight(size_t height) {
	kHeight = height;
}

Map::Map(uint8_t nrPlayers) {

	switch (nrPlayers) {

	case 2:
		setWidth(3);
		setHeight(3);
		break;
	case 3:
		setWidth(5);
		setHeight(3);
		break;
	case 4:
		setWidth(6);
		setHeight(4);
		break;
}