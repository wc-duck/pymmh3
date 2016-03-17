# PYMMH3 - a pure python MurmurHash3 implementation.

[![Build Status](https://travis-ci.org/swapniel99/pymmh3.svg?branch=master)](https://travis-ci.org/swapniel99/pymmh3)

## About:
This is a pure python implementation of the murmur3 hash algorithm <https://code.google.com/p/smhasher/wiki/MurmurHash3>
written for the times when you do not want to muck about building and installing c-modules etc.

As this is pure python performance is FAR from optimal in CPython and if that is required a real c-module such as the
one found here at <https://pypi.python.org/pypi/mmh3/2.3.1> is absolutely suggested!

However this module performs extremely well in case of pypy(<http://pypy.org>), an alternative JIT version of python.

## Performance:
Bad... we need not say more ;)

But with pypy it is blazing fast compared to mmh3 :D

## Testing:
Tested by hashing all lines in Jane Eyre by Charlotte Bronte in both c and with pymmh3.

## Usage:
```python
try:
    # try with a fast c-implementation ...
    import mmh3 as mmh3
except ImportError:
    # ... otherwise fallback to this code!
    import pymmh3 as mmh3
    
print mmh3.hash( 'my string of doom!', seed = 1234 )
print mmh3.hash64( 'my string of doom!', seed = 1234 )
print mmh3.hash128( 'my string of doom!', seed = 1234 )
print mmh3.hash_bytes( 'my string of doom!', seed = 1234 )
```

## License:
Murmur3 hash was originally created by Austin Appleby.

* http://code.google.com/p/smhasher/

pymmh3 was written by Fredrik Kihlander and enhanced by Swapnil Gusani, and is placed in the public
domain. The authors hereby disclaim copyright to this source code.
