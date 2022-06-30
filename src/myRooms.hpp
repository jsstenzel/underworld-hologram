#pragma once
#include "core/include.hpp"

class roomField : public CRoom {
public:
  roomField() : CRoom("field", "You stand amongst waist-high grains and weeds.") {}
};

class roomMountain : public CRoom {
public:
  roomMountain() : CRoom("mountain", "You stand at the peak of all the world has to offer.") {}
};