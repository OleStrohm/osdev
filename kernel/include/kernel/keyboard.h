#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

enum Key {
	Q, W, E, R, T, Y, U, I, O, P,
	A = 30, S, D, F, G, H, J, K, L,
	Z, X, C, V, B, N, M
};

bool isDown(enum Key key);
void keyboard_interrupt();
