# Huffman-Encryption
## Overview
This project implements the Huffman coding algorithm in C++ to compress text files. Huffman coding is a popular method of lossless data compression. It uses variable-length codes to represent characters based on their frequencies in the input data.

## Features
Compressing text files using Huffman coding.

## Implementation
The program begins by reading the input text and calculating the frequency of each character. It then constructs a Huffman tree through an iterative process of merging the two least frequent characters until a singular tree is formed. The Huffman codes for each character are derived by traversing the tree from the root to the corresponding leaf node.

The resulting compressed output comprises a serialized representation of the Huffman tree, followed by the encoded text. This Huffman tree is essential for decompressing the text during the decoding process.

## Getting Started
### Prerequisites
Make sure you have the following installed:

C++ compiler (Visual Studio)
## Output
### Before Encryption

### After Encryption

