#!/bin/sh
./config.sh
./clean.sh && ./headers.sh && ./iso.sh && ./qemu.sh
