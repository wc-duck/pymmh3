# PYMMH3 - a pure python MurmurHash3 implementation.

[![Build Status](https://travis-ci.org/wc-duck/pymmh3.svg?branch=master)](https://travis-ci.org/wc-duck/pymmh3)

## About:
This is a pure python implementation of the murmur3 hash algorithm <https://code.google.com/p/smhasher/wiki/MurmurHash3>
written for the times when you do not want to muck about building and installing c-modules etc.

As this is pure python performance is FAR from optimal and if that is required a real c-module such as the
one found here at <https://pypi.python.org/pypi/mmh3/2.0> is absolutely suggested!

## Performance:
Bad... we need not say more ;)

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
```

## License:
pymmh3 was written by Fredrik Kihlander, and is placed in the public
domain. The author hereby disclaims copyright to this source code.
