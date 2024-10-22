
# Wireless Networking & Security Lab Reports

This folder contains documentation of hands-on labs that focus on the configuration, management, and security of wireless networks. The labs explore different aspects of wireless networking, including access point setup, secure authentication methods, VLAN segmentation, and enterprise wireless management with controllers and virtualized infrastructure.

## Lab Summaries

### 1. Secure Architecture Configuration
This lab focuses on building a secure wireless architecture using **Cisco APs**, a **Cisco 9800 WLC**, and **pfSense**. It explores creating multiple wireless networks with distinct authentication methods, such as **WPA2-Enterprise**, WPA-PSK, and open guest networks. A **Windows Server** VM is deployed to provide **Active Directory** and **RADIUS** authentication.

Key Components:
- Virtualized environment using **ESXi**.
- **WPA2-Enterprise authentication** with RADIUS and AD.
- Network segmentation with VLANs and firewall rules.
- FTP server setup for departmental resource access.

### 2. Virtualization and Authentication Lab
This lab demonstrates the configuration of **Meraki** and **Unifi** wireless access points, as well as network management through **ESXi virtualization**. The lab focuses on segmenting the network with VLANs and ensuring secure user access via RADIUS.

Key Components:
- Deploying **Unifi controllers** and Meraki devices.
- Configuring SSIDs and VLANs for segmented access.
- Implementing **RADIUS authentication** for secure connections.
- Testing policies to block certain sites and devices.

### 3. Switch and AP Configuration Lab
This lab covers the foundational setup of Cisco APs and switches, including **SSID creation, encryption configurations**, and radio setup for both **2.4 GHz and 5 GHz** bands. It also explores the use of **WPA, WEP, and ACLs** to manage access to the network.

Key Components:
- SSID and encryption setup (WPA2, WEP).
- **Radio configuration** for 2.4 GHz and 5 GHz bands.
- Creating **ACLs** for access control and network security.
- Observing roaming behavior with Wireshark.

### 4. Architecture Configuration Lab
This lab outlines the procedures to connect Cisco APs, switches, and servers to create a working wireless network. Emphasis is placed on addressing vulnerabilities such as **WPA-PSK weaknesses** through **Wireshark analysis** and **MAC spoofing**.

Key Components:
- Factory resetting APs and configuring DHCP.
- Testing WPA-PSK vulnerabilities using Wireshark and spoofing tools.
- Implementing **RADIUS-backed WPA2-Enterprise networks**.
- Troubleshooting common AP and switch issues.

## Key Takeaways
- **Enterprise Wireless Management**: Using Meraki, Unifi, and Cisco controllers for AP management.
- **Secure Authentication**: Implementing WPA2-Enterprise with RADIUS and Active Directory.
- **Segmentation**: Using VLANs and SSIDs for network isolation.
- **Wireless Security**: Testing WPA-PSK vulnerabilities and using ACLs to control network access.
- **Virtualization**: Deploying virtualized controllers and servers for wireless network operations.

These labs provide a comprehensive understanding of wireless network setup, management, and security, with practical insights into real-world deployment and troubleshooting.
