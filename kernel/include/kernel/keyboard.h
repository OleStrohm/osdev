#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

extern "C" unsigned char inb(unsigned char);

enum class Key {
	Q, W, E, R, T, Y, U, I, O, P,
	A = 30, S, D, F, G, H, J, K, L,
	Z, X, C, V, B, N, M
};

bool isDown(enum Key key);
void keyboard_interrupt();
