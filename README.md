# Filesystem Adaptor

The Standard C++ library's greatest asset is that it's available with every
C++ compiler. Unfortunately, for a lot of Object Oriented designers, however,
the Standard library is a bit of a nuisance. Standard Library functions create
cross-cutting concerns, which make it difficult to create mock interfaces and
perform unit tests on code that relies on them.

This project presents an interface for manipulating the filesystem in useful
ways. The library includes some standard functionality already present in the
Standard C++ library (simply extending it), but also provides some useful
functionality *not* available in the C++ Standard Library (for example, `walk`,
which is available in the Python standard library as `os.walk`).

The ideal way to use this library is to expose its components as dependencies
in the constructors of your classes under test (Constructor
Dependency-Injection). The class `StandardFilesystemAdaptor` implements the
functionality needed by your classes and relies on the C++ Standard Library to
perform those functions. Then, use a mock framework (like Google Mock) to mock
the interface `IFilesystemAdaptor` and inject your mock class into the class
under test during Unit Testing. Example:

```
class UnderTest
{
public:
  UnderTest(const IFilesystemAdaptor& fsadaptor = StandardFilesystemAdaptor{});
};

...

int uses_UnderTest()
{
  UnderTest ut;
  // Use ut, which is hooked up to the Standard Library
}

...

int test_UnderTest()
{
  UnderTest ut{YourMockFilesystemAdaptor{}};
  // Test ut to make sure it does the right thing!
}
```