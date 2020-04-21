#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

enum Key {
	A = 30, S, D, F
};

bool isDown(enum Key key);
