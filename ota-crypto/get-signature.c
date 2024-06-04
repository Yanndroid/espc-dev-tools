#include <sodium.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <filepath> <private-key>\n", argv[0]);
    return 1;
  }

  const char *filename = argv[1];
  const char *hex_private_key = argv[2];

  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  if (sodium_init() == -1) {
    fprintf(stderr, "Failed to initialize libsodium\n");
    fclose(file);
    return 1;
  }

  unsigned char private_key[crypto_sign_SECRETKEYBYTES];
  sodium_hex2bin(private_key, sizeof(private_key), hex_private_key,
                 strlen(hex_private_key), NULL, NULL, NULL);

  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  fseek(file, 0, SEEK_SET);
  unsigned char *file_contents = malloc(file_size);
  if (file_contents == NULL) {
    fprintf(stderr, "Memory allocation error\n");
    fclose(file);
    return 1;
  }
  fread(file_contents, 1, file_size, file);
  fclose(file);

  crypto_sign_state state;
  crypto_sign_init(&state);
  crypto_sign_update(&state, file_contents, file_size);

  unsigned char signature[crypto_sign_BYTES];
  crypto_sign_final_create(&state, signature, NULL, private_key);

  char hex_signature[crypto_sign_BYTES * 2 + 1];
  sodium_bin2hex(hex_signature, sizeof(hex_signature), signature,
                 sizeof(signature));

  printf("Signature: %s\n", hex_signature);

  free(file_contents);
  sodium_memzero(private_key, sizeof(private_key));

  return 0;
}
