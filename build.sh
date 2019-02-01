gcc $(pkg-config --cflags --libs libsodium) passgen.c -o passgen
chmod +X passgen
