# UDP Communication Projects

## Overview

The projects consist of two Qt-based C++ applications designed for UDP communication: a sender and a receiver. These applications work together to send and receive UDP datagrams, demonstrating basic networking capabilities using Qt.

## Technologies Used

- **Qt Framework**: A C++ framework for developing cross-platform applications with a graphical user interface (GUI).
- **Qt Network Module**: Provides classes for network programming, including `QUdpSocket` for UDP communication.
- **Qt Widgets**: Used for creating the user interface elements such as buttons, labels, and text fields.

## Sender Application

### Description

The sender application allows users to specify a target IP address and port number to send data to a receiver. It includes features for connecting and sending data via UDP.

### Key Components

- **QUdpSocket**: Used for sending UDP datagrams.
- **QPushButton**: Triggers sending of data.
- **QLabel**: Displays the connection status.
- **QTextEdit**: Input field for the data to be sent.

## Receiver Application

### Description

The receiver application listens for incoming UDP datagrams on a specified port and displays the received data. It provides visual feedback on the connection status and displays incoming data in real-time.

### Key Components

- **QUdpSocket**: Used for receiving UDP datagrams.
- **QPushButton**: Triggers the connection to the specified port.
- **QLabel**: Displays the connection status.
- **QTextEdit**: Shows the received data.

## How They Connect

### Sender Setup

- The sender application sets up a `QUdpSocket` to send datagrams.
- It allows the user to enter the IP address and port number of the receiver.
- When the user clicks the "Send" button, it sends data to the specified IP address and port.

### Receiver Setup

- The receiver application sets up a `QUdpSocket` to receive datagrams.
- It allows the user to specify the port number to listen on.
- Once connected, it continuously listens for incoming datagrams and processes them as they arrive.

### Communication

- The sender uses `QUdpSocket::writeDatagram` to send data to the receiver.
- The receiver uses `QUdpSocket::readDatagram` to receive and process incoming data.

## Conclusion

These two projects demonstrate a simple UDP communication setup using the Qt framework. The sender application sends data to a specified IP address and port, while the receiver application listens on a specified port and displays the received data. This setup showcases the fundamental principles of UDP communication, including sending and receiving datagrams, and provides a practical example of network programming with Qt.

---

## Running the Project

### Using the Application Directly

If you only want to use the application without making any modifications, follow these steps:

1. **Check the `build` Folder**:
   - Ensure that the `build` folder exists in the cloned repository.

2. **Execute the Sender Application**:
   - Navigate to the following path in the terminal or file explorer for the Sender application:

     ```plaintext
     UDPSender/build-UDPsender-Desktop_Qt_6_5_3_MinGW_64_bit-Debug/debug/UDPsender.exe
     ```

   - Double-click `SenderApp.exe` to launch the sender application.

3. **Execute the Receiver Application**:
   - Navigate to the following path in the terminal or file explorer for the Receiver application:

     ```plaintext
     UDPReceiver/build-UDPreceiver-Desktop_Qt_6_5_3_MinGW_64_bit-Debug/debug/UDPreceiver.exe
     ```

   - Double-click `ReceiverApp.exe` to launch the receiver application.

---

<div align="center">

### Contact Information

[![Email](https://img.shields.io/badge/Email-sivasaiyarlagadda2001@gmail.com-green?style=flat-square&logo=gmail)](mailto:sivasaiyarlagadda2001@gmail.com)

[![LinkedIn](https://img.shields.io/badge/LinkedIn-Sivasai_Yarlagadda-blue?style=flat-square&logo=linkedin)](https://www.linkedin.com/in/sivasai-yarlagadda)

</div>
