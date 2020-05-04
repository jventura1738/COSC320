# Justin Ventura, Florent Dondjeu, Ryan Kern
# Project for COSC370 Algorithm.

import time
import os
from math import sqrt
from base64 import b64encode, b64decode
import hashlib
from Cryptodome.Cipher import AES
from Cryptodome.Random import get_random_bytes
import numpy as np
import random
import string

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
    # Base cases for low primes.
	if n == 1: return 2
	elif n == 2: return 3
	elif n == 3: return 5

	curr = 3
	val = 7
    # Algorithm to find the Nth prime.
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
    # Base case.
	if n % 2 == 0:
		return False

    # This is a buffer to reduce unecessary
    # computations increasing performance.
	buffer = int(sqrt(n))
	buffer += 1

    # This terminates if any extra factor
    # is found.
	for i in range(3, buffer, 2):
		if n % i == 0: return False
	return True

# Generates a random key for testing purposes.
# For the sake of simplicity, we will just make
# an integer key which will then be hashed.
def generateKey():
    # Find a random prime.
    key = np.random.randint(low=0, high=999999999)
    while not isPrime(key):
        key += 1

    # Random primes I generated.
    P1 = 15486013
    P2 = 10007
    return hex((key * P2) % P1)

# Generate a random string of random length,
# 16 is the default if none specified.
def randomString(stringLength=16):
    letters = string.ascii_lowercase
    return ''.join(random.choice(letters) for i in range(stringLength))

# This encryption function uses the AES cipher
# to encrypt data using a given key.
def encrypt(origData, key):
    # Generate random salt for unique key.
    salt = get_random_bytes(AES.block_size)
    # Here we create a private key.
    privateKey = hashlib.scrypt(key.encode(), salt=salt, n=2**14, r=8, p=1, dklen=32)

    # Configure the AES cipher.
    cipher_config = AES.new(privateKey, AES.MODE_GCM)

    # Here we return a dictionary with the encrypted
    # data.
    cipherMsg, tag = cipher_config.encrypt_and_digest(bytes(origData, 'utf-8'))
    return {
        'cipherText': b64encode(cipherMsg).decode('utf-8'),
        'salt': b64encode(salt).decode('utf-8'),
        'nonce': b64encode(cipher_config.nonce).decode('utf-8'),
        'ctag': b64encode(tag).decode('utf-8')
    }

# This function uses a given key to decrypt data.
def decrypt(encryptedData, key):
    # Decode the dictionary entries from base64.
    salt = b64decode(encryptedData['salt'])
    cipherText = b64decode(encryptedData['cipherText'])
    nonce = b64decode(encryptedData['nonce'])
    ctag = b64decode(encryptedData['ctag'])
    
    # Generate the private key from the key and salt
    # which were created during encryption. Note both
    # the key and salt are unique which allows for 
    # better security. This decryption is worthless
    # with out them.
    private_key = hashlib.scrypt(key.encode(), salt=salt, n=2**14, r=8, p=1, dklen=32)

    # Configure the AES cipher.
    cipher = AES.new(private_key, AES.MODE_GCM, nonce=nonce)

    # Decrypt the cipher text then return it.
    decrypted = cipher.decrypt_and_verify(cipherText, ctag)
    return decrypted

# Delay print for simulation purposes.
def VPN_delay(sleeptime):
    time.sleep(sleeptime)
    print('. . .')

# This function simulates a very basic tunnel, thus
# is also a very weak one. 
def VPN_miniTunnel(dataString, passwordIdx):
    # Here we will create a bunch of random data which
    # will be shoved in with the message.
    lengths = list(np.random.normal(loc=len(dataString), scale=4, size=14))

    # Now create the data pack list for 'encapsulation.'
    dataPack = []
    for i in range(0, len(lengths) + 1):
        if i == passwordIdx:
            dataPack.append(dataString)
        else:
            if lengths[-1] < 0:
                lengths[-1] *= -1
            elif lengths[-1] == 0:
                lengths += len(dataString)
            dataPack.append(randomString(int(lengths[-1])))
            lengths.pop()
    print('[log: data encapsulated...]')
    return dataPack

# This is a function which assists in VPN simulation.
# Function receives data, then proceeds to send data.
def VPN_initData():
    dataString = input('--> ')
    print('[log: data received...]')
    passwordIdx = np.random.randint(low=0, high=15)
    return [passwordIdx, dataString]

# This is a function which simulates the prepping of
# data by encrypting the data then preparing to send.
def VPN_prepData(dataPack):
    print('[log: encrypting data...]')
    VPN_delay(3)
    encryptedData = []
    key = generateKey()
    for dataString in dataPack:
        encryptedData.append(encrypt(dataString, key))
    return [key, encryptedData]

# This function prints the data being sent, then sends
# it to be received by recipient.
def VPN_sendData(encryptedData, tunnelPass, key):
    print('[log: sending data...]')
    VPN_delay(3)
    VPN_recvData(encryptedData, tunnelPass, key)

# This function simulates the data being receieved and
# decrypted then displayed to the user.
def VPN_recvData(encryptedData, tunnelPass, key):
    decryptedMessage = decrypt(encryptedData[tunnelPass], key)
    print('[log: data received...]')
    print('Original data: ', bytes.decode(decryptedMessage))

# This function simulates the VPN encrypting, sending,
# receiving, then decrypting the message.
def VPN_simulation():
    print('Enter some data to be sent...')
    tunnelPass, dataString = VPN_initData()
    dataPack = VPN_miniTunnel(dataString, tunnelPass)
    key, encrypted = VPN_prepData(dataPack)
    print('\nGiven key...', key)
    print('Encrypted data packet: ', end=' ')
    for elem in encrypted:
        print(elem['cipherText'], end=' ')
    print('\n')
    VPN_sendData(encrypted, tunnelPass, key)

# This is the main program where the encryption and
# decryption are demonstrated in the form of a basic
# 'VPN Simulation.'
if __name__ == '__main__':
    print('This is a VPN simulation!')
    VPN_simulation()
    print('Thanks for watching this simulation!')

else:
    print('your code is broken buddy.')