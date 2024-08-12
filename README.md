# TOR-from-scratch

![TOR Logo](https://static1.xdaimages.com/wordpress/wp-content/uploads/2018/09/tor-logo.jpeg)

## Table of Contents

- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [Example](#example)
- [Directory Structure](#directory-structure)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Introduction

**TOR-from-scratch** is a comprehensive project that demonstrates the underlying principles of the Tor network. This project is designed for educational purposes, showcasing how to build the Tor network from the ground up, understanding the complexities of anonymous communication, and enhancing privacy on the internet.

## Installation

To set up the project on your local machine, follow these steps:

1. **Clone the Repository:**

    ```bash
    git clone https://github.com/trevorsaudi/TOR-from-scratch.git
    cd TOR-from-scratch
    ```

2. **Install Dependencies:**

    Ensure you have the required dependencies installed. For a typical Kali Linux environment, you may need:

    ```bash
    sudo apt-get update
    sudo apt-get install tor
    ```

3. **Configuration:**

    Configure the Tor service to listen on port 9050 by editing the `torrc` file:

    ```bash
    sudo nano /etc/tor/torrc
    ```

    Ensure the following line is present:

    ```bash
    SocksPort 9050
    ```

4. **Start the Tor Service:**

    ```bash
    sudo systemctl start tor
    ```

## Usage

To use the Tor network as configured in this project, run the `main` application with the host and port as command-line arguments.

### Basic Usage

```bash
./main <host> <port>
