import base64
import itertools

# The raw encrypted byte string
enc = b"\x0e,\x082 ,\x17%\x1b/!%\x18\x15*+ \x01\x00w'\x15v%\x18,\x1b%$\x16s\x0b\x11p{,\x17q2\x05's\x0c\n\x17\x052+!\x15ws\x18+\x001!,%%!,\x14,\x0b\n\x08t\x0b\x05&+&\x01\x00-\x1b/5% \n.w /\x04p\x175\x7f\x7f"

# Define the operations
def xor(data): return bytes([b ^ 0x42 for b in data])
def rot13(data): return bytes([((b - 97 + 13) % 26 + 97) if 97 <= b <= 122 else ((b - 65 + 13) % 26 + 65) if 65 <= b <= 90 else b for b in data])
def reverse(data): return data[::-1]
def b64decode(data):
    try:
        return base64.b64decode(data)
    except Exception:
        return b''

# Map operation names to functions
operations = {
    'xor': xor,
    'rot13': rot13,
    'reverse': reverse,
    'base64': b64decode
}

# Try all permutations
for ops in itertools.permutations(['xor', 'rot13', 'reverse', 'base64']):
    data = enc
    try:
        for op in ops:
            data = operations[op](data)
        if b'flag{' in data:
            print(f"[+] Success with order {ops}:\n{data.decode(errors='ignore')}")
    except Exception:
        continue
