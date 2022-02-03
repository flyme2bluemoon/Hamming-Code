# A Simple Case Study of Hamming Codes

Was amazed by hamming codes discuss in [this video](https://www.youtube.com/watch?v=X8jsijhllIA) by @3b1b.

## Implementation details

Some notes:
* This implementation was created using C since that is the objectively bestest language :)
* I will be working with 256-bit blocks which requires 5 parity bits at index 2, 4, 8, 16, 32
* Coming soon: Allow recover to detect more errors

## Test it yourself

First compile the code:
```
make
```

* `bin/sender` will generate `messages.txt`
* `bin/corrupt` will take `messages.txt` and flip one bit in each of the messages and save the result to `corrupted.txt`
* `bin/recover` will recover `messages.txt` using `corrupted.txt` and save the results to `recovered.txt`

To run all three steps:
```
./bin/sender && ./bin/corrupt && ./bin/recover
```

Verify the results
```
diff messages.txt recovered.txt
```
Success if there is no output