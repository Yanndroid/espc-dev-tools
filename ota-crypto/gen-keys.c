#include <sodium.h>

int main() {
  if (sodium_init() == -1) {
    fprintf(stderr, "Failed to initialize libsodium\n");
    return 1;
  }

  unsigned char public_key[crypto_sign_PUBLICKEYBYTES];
  unsigned char private_key[crypto_sign_SECRETKEYBYTES];

  crypto_sign_keypair(public_key, private_key);

  char hex_public_key[crypto_sign_PUBLICKEYBYTES * 2 + 1];
  char hex_private_key[crypto_sign_SECRETKEYBYTES * 2 + 1];

  sodium_bin2hex(hex_public_key, sizeof(hex_private_key), public_key,
                 sizeof(public_key));
  sodium_bin2hex(hex_private_key, sizeof(hex_private_key), private_key,
                 sizeof(private_key));

  printf("Public Key: %s\n", hex_public_key);
  printf("Private Key: %s\n", hex_private_key);

  sodium_memzero(private_key, sizeof(private_key));
  return 0;
}
