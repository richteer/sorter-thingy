# Sorter-thingy

## Overview

A multithreaded program that sorts lines of text from files, for CS444: Operating Systems.
The specifications for this lab can be found [here](http://web2.clarkson.edu/class/cs444/cs444.sp2015/assignments/thread/).

## Usage

`sorter` takes in the following arguments:

- `-i <name>`: specify a directory containing files to be sorted
- `-o <name>`: specify a directory to write sorted files to
- `-t <num>`: specify the number of threads to spawn

Note: `-i` and `-o` are required, and must not be the same directory.
`-t` is optional, and defaults to `1` if not set.
