# from nacl.signing import SigningKey
# import binascii

# priv_hex = "6814da007c7e65362cea3c014b7bb17dbc0d3af1abebd0c9236bed4b38d48b41d96bf731106ac3ed2c061dec72b6c68b27dc78c50fe6c7b96e975eb737be3a83"
# priv_bytes = binascii.unhexlify(priv_hex)

# signing_key = SigningKey(priv_bytes[:32])  # Ed25519 приватный ключ — первые 32 байта
# pub_key = signing_key.verify_key.encode().hex()

# print("Вычисленный публичный ключ:", pub_key)
# print("Совпадает:", pub_key == "cdc3b3b40985a7c8ba3ee3ed9618db9a862cf91a714cdaeb681fb19320fa81bd")

from nacl.signing import SigningKey
import binascii
import hashlib


seed = bytes.fromhex("cf87c2284d27bd81ea77523ee9547752b7865f5c5fc95d657c31c16028f2f8cb")

# Генерируем приватный ключ так же, как C-код (SHA-512(seed)[:32])
hashed_seed = hashlib.sha512(seed).digest()[:32]

signing_key = SigningKey(hashed_seed)  # Используем обработанный seed
pub_key = signing_key.verify_key.encode().hex()

print("Вычисленный публичный ключ:", pub_key)

seed = bytes.fromhex("cf87c2284d27bd81ea77523ee9547752b7865f5c5fc95d657c31c16028f2f8cb")

# Генерация приватного ключа
hashed_seed = hashlib.sha512(seed).digest()
private_key = bytearray(hashed_seed[:32])  # Берем первые 32 байта
private_key[0] &= 248  # Применяем маскирование
private_key[31] &= 63
private_key[31] |= 64

# Генерация ключей с использованием nacl.signing
signing_key = SigningKey(bytes(private_key))  # Преобразуем bytearray в bytes
pub_key = signing_key.verify_key.encode().hex()

print("Вычисленный публичный ключ:", pub_key)