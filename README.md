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
## Before Encryption
<img width="1271" alt="original" src="https://github.com/user-attachments/assets/42344dae-4bc5-427e-93e3-eadffe3716a2">

### File Size
<img width="682" alt="original_1" src="https://github.com/user-attachments/assets/dfe1afb7-6440-42f7-9539-de28c55494fe">

## After Encryption
### Huffman Tree
<img width="850" alt="Output" src="https://github.com/user-attachments/assets/a7f56280-9533-4b32-b0c0-9ea2fa28116a">

### File Encrypted
<img width="1163" alt="encryption" src="https://github.com/user-attachments/assets/8105a2bb-76fe-4faf-b8a5-064faaea2ad5">

### File Size
<img width="677" alt="encryption_1" src="https://github.com/user-attachments/assets/b00ead1e-3252-4dae-b81b-c046fe276b29">

