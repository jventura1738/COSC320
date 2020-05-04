# Justin Ventura, Florent Dondjeu, Ryan Kern
# Project for COSC370 Algorithm.

import os
from math import sqrt
from base64 import b64encode, b64decode
import hashlib
import random
from Cryptodome.Cipher import AES
from Cryptodome.Random import get_random_bytes

# In order for VPNs to keep your data private,
# there are two measures used to do so.  The
# first one is tunneling.  Tunneling is when
# whatever data you want to be sent (for ex: 
# your bank login info or credit card cred-
# entials) is stuffed with other data making 
# it much harder for hackers and trackers to
# to find.  Think of it like an envelope on
# your mail.  However, it is obvious that this
# only provides so much protection as anyone
# can simply snoop through the envelope or
# search through the data in this case. So,
# the next level in encrypting and decrypting
# your information.  This way, even if any
# malicious intruders find your sensitive
# data, they will have to decrypt it using
# a key that only you and the VPN company
# servers have.  Below will be an algorithm
# to both encrypt and decrypt a given string
# of data.

# Generates the Nth prime passed as a parameter.
# This was taken from my Gullcode2019 Repo.
def NthPrime(n):
	if n == 1: return 2
	elif n == 2: return 3
	elif n == 3: return 5

	curr = 3
	val = 7
	while (curr <= n):
		if isPrime(val):
			curr += 1
		if curr == n:
			return val
		else:
			val += 2

# Determines if a number is prime or not.
# Also from my Gullcode2019 Repo.
def isPrime(n):
	if n % 2 == 0:
		return False
	buffer = int(sqrt(n))
	buffer += 1

	for i in range(3, buffer, 2):
		if n % i == 0: return False
	return True

# Generates a random key for testing purposes.
# For the sake of simplicity, we will just make
# an integer key which will then be hashed.
def generateKey():
    key = random.randint(0, 99999999)
    while not isPrime(key):
        key += 1
    # Random primes I generated.
    P1 = 1299709
    P2 = 10007
    return hex((key * P2) % P1

def encrypt(data, key):
    # Generate a random salt.  These are used for
    # making the encryption more secure.
    salt = get_random_bytes(AES.block_size)

    # Here we make the private key.
    privateKey = hashlib.scrypt(key.encode(), salt=salt, n=2**14, r=8, p=1, dklen=32)
    # Configure the cipher (using AES cipher).
    cipherConfig = AES.new(privateKey, AES.MODE_GCM)

    # Returns dictionary with the encrypted data.
    cipherData, tag = cipherConfig.encrypt_and_digest(bytes(data, 'utf-8'))
    return {
        'cipherData': b64encode(cipherData).decode('utf-8'),
        'salt': b64encode(salt).decode('utf-8'),
        'nonce': b64encode(cipherConfig.nonce).decode('utf-8'),
        'ctag': b64encode(tag).decode('utf-8')
    }

def decrypt(encryptedData, key):
    # Decode the dictionary entries of the encrypted data.
    # Using b64 for base 64 decoding.
    salt = b64decode(encryptedData['salt'])
    cipherData = b64decode(encryptedData['cipherData'])
    nonce = b64decode(encryptedData['nonce'])
    tag = b64decode(encryptedData['ctag'])
    
    # Generate the private key from the key and salt.
    private_key = hashlib.scrypt(
        key.encode(), salt=salt, n=2**14, r=8, p=1, dklen=32)

     # Configure the cipher (using AES cipher).
    cipher = AES.new(private_key, AES.MODE_GCM, nonce=nonce)

    # Decrypt the data from the cipher object.
    decryptedData = cipher.decrypt_and_verify(cipherData, tag)

    return decryptedData


if __name__ == '__main__':
    print('hi')
    encryption_key = generateKey()
    message = 'This is a test.'
    encryption = encrypt(message, encryption_key)
    print(encryption)
    decryption = decrypt(message, encryption_key)
    print(decryption)
else:
    print('buddy your code is broken')
