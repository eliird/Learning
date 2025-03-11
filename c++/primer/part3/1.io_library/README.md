# IO in C++

C++ does not deal with IO directly. It is handled by family of types defined in the standard library. These types support IO to and from devices such as files and console windows.

This part will have some fundamentals of io here, in later parts we will look at how we can write our own custom input and  output operators. We will also cover how to control formatting and perform random access on files.

In programs up to this point we have seen
- istream
- ostream
- cin(istream object), cout (ostream object), cerr(ostream object)
- `>>` and << `operators`
- `getline` function

## Available IO headers

* `iostream` read and write to stream
* `fstream` read and write to file
* `sstream` reand and write from strings

C++ has w variant of most of stream objects like `wcin` and `wcout` to handle wide characters.

## Characteristics of io objects

We cannot copy or assign objects of iotypes, since we cant copy them we cant have those as function return types or parameters, they are always passed around by references.

```c++
ofstream out1, out2;
out1 = out2; //error
ofstream print(ofstream); //error cannot initialize the ofstream parameter
out2 = print(out2) //error cannot copy stream objects
```

When doing IO, errors can occur and some errors are recoverable and some not. IO class defines functions and flags that let us access the state of stream.

```c++
while(cin >> word)
    //ok: read operation successfull
    // condition checks the state of the stream returned from >> operation
    //but this tells us only that some problem in stream not what 
```

- `strm::iostate`  iostate is a machine-dependent integral type that represents the condition state of a stream.
- `strm::badbit`  strm::iostate value used to indicate that a stream is corrupted.
- `strm::failbit`  strm::iostate value used to indicate that an IO operation failed.
- `strm::eofbit` strm::iostate value used to indicate that a stream hit end-of-file.
- `strm::goodbit` strm::iostate value used to indicate that a stream is not in an error state. This value is guaranteed to be zero.
- `s.eof()` true if eofbit in the stream s is set.
- `s.fail()` true if failbit or badbit in the stream s is set.
- `s.bad()` true if badbit in the stream s is set.
- `s.good()` true if the stream s is in a valid state.
- `s.clear()` Reset all condition values in the stream s to validstate. Returns void.
- `s.clear(flags)` Reset the condition of s to flags. Type of flags is strm::iostate. Returns void.
- `s.setstate(flags)` Adds specified condition(s) to s. Type of flags is strm::iostate. Returns void.
`s.rdstate()` Returns current condition of s as a strm::iostate value.

### Managing Bad Conditions
```C++
auto old_state = cin.rdstate(); //remember old state of cin
cin.clear(); // make cin valid
process_input(cin); // use cin
cin.setstate(old_state); // now reset cin to old state
```

### Managing Output Buffer

Each output stream uses a buffer to hold the data program reads or writes.

```C++
os << "pleas enter a value: ";
```
This might be printed immediately or os migh store data in buffer to be printed later. This allows os to combine several outputs from a program to a system write call. There are certain conditions that can cause buffer to be flushed --(weritten on actual io devices)
- program finishes. All buffers are fulushed as part of return from main
- if buffer becomes full.
- explicit call to flush the buffer. (`std::endl`)
- when streams are tied to one another, one stream can flush other. By default `cin` and `cerr` are tied to `cout` therefore readinf cin or writing cerr flushes cout;

```c++
cout << "hi!" << endl; // writes hi and a newline, then flushes the buffer
cout << "hi!" << flush; // writes hi, then flushes the buffer; adds no data
cout << "hi!" << ends; // writes hi and a null, then flushes the buffer
```

### uintbuf manipulator.

if we want to flush every output we can use `uintbuf`.
```c++
cout << unitbuf; // all writes will be flushed immediately
// any output is flushed immediately, no buffering
cout << nounitbuf; // returns to normal buffering
```

**Buffers are not flushed if the program crashes**

### Tying CIN and COUT
```c++
cin.tie(&cout); // illustration only: the library ties cin and cout for us
// old_tie points to the stream (if any) currently tied to cin
ostream *old_tie = cin.tie(nullptr); // cin is no longer tied
// ties cin and cerr; not a good idea because cin should be tied to cout
cin.tie(&cerr); // reading cin flushes cerr, not cout
cin.tie(old_tie); // reestablish normal tie between cin and cout
```

## File Streams
- `fstream fstrm;` Creates an unbound file stream. fstream is one of the typesdefined in the fstream header.
- `fstream fstrm(s);` Creates an fstream and opens the file named s. s can have type string or can be a pointer to a C-style character string.
- `fstream fstrm(s, mode);` Like the previous constructor, but opens s in the given mode.

- `fstrm.open(s)`
- `fstrm.open(s, mode)` Opens the file named by the s and binds that file to fstrm. s can be a string or a pointer to a C-style character string. The default file mode depends on the type of fstream. Returns void.
- `fstrm.close()` Closes the file to which fstrm is bound. Returns void.
- `fstrm.is_open()` Returns a bool indicating whether the file associated with fstrm was successfully opened and has not been closed.