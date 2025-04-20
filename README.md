# Minitalk

A simple client-server communication program using UNIX signals.

![Minitalk Demo](Ekran%20Resmi%202023-09-17%20ÖS%206.36.56.png)

## Table of Contents

- [Minitalk](#minitalk)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Features](#features)
  - [How It Works](#how-it-works)
  - [Requirements](#requirements)
  - [Installation](#installation)
  - [Usage](#usage)
    - [Starting the Server](#starting-the-server)
    - [Sending Messages with the Client](#sending-messages-with-the-client)
  - [Implementation Details](#implementation-details)
    - [Server](#server)
    - [Client](#client)
  - [References](#references)

## Overview

Minitalk is a small data exchange program that uses UNIX signals for communication between a client and server. The server displays the string sent by the client through binary transmission, demonstrating inter-process communication via signals.

## Features

- Server-client architecture using UNIX signals (SIGUSR1 and SIGUSR2)
- Binary communication protocol
- Lightweight and efficient message transmission
- Built using only allowed functions from the project requirements
- Error handling for invalid inputs
- Small memory footprint

## How It Works

1. The server starts and displays its PID (Process ID).
2. The client takes the server PID and a string to send as arguments.
3. The client converts each character of the string to binary and sends it bit by bit:
   - SIGUSR1 signal for binary 1
   - SIGUSR2 signal for binary 0
4. The server receives these signals, reconstructs each character, and displays the message.

## Requirements

- Unix-based operating system (Linux/macOS)
- GCC compiler
- Make

## Installation

1. Clone this repository or download the source code.
2. Compile the project using make:

```bash
make
```

This will compile both the client and server executables, as well as the necessary libft library.

## Usage

### Starting the Server

Run the server first to get its PID:

```bash
./server
```

The server will display its PID, which you'll need for the client.

### Sending Messages with the Client

Use the client to send messages to the server:

```bash
./client [server_pid] [message]
```

Example:

```bash
./client 4321 "Hello, Minitalk!"
```

The server will then receive and display the message "Hello, Minitalk!"

## Implementation Details

### Server

The server initializes by:
1. Displaying its PID
2. Setting up signal handlers for SIGUSR1 and SIGUSR2
3. Waiting indefinitely for signals

When signals are received, the `handler` function:
- Interprets SIGUSR1 as binary 1 and SIGUSR2 as binary 0
- Reconstructs characters bit by bit using a power-of-2 approach
- Outputs each complete character to stdout

### Client

The client performs these steps:
1. Validates input arguments and server PID
2. For each character in the message:
   - Converts the character to its binary representation
   - Sends SIGUSR1 for each bit that is 1
   - Sends SIGUSR2 for each bit that is 0
   - Waits briefly between signals to prevent signal loss

## References

- [UNIX Signals Documentation](signals.pdf)
- [Turkish Signals Reference](signals%20tr.pdf)

---

*This project is part of the 42 School curriculum.*