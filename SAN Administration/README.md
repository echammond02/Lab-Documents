
# Storage Area Networking (SAN) Lab Report

This folder contains documentation of a hands-on lab focused on the deployment and configuration of a **Storage Area Network (SAN)**. The lab explores various technologies such as **iSCSI**, **CHAP authentication**, **PXE booting**, and **TrueNAS** to simulate a storage infrastructure for enterprise environments.

## Lab Summary

### Storage Setup with TrueNAS and iSCSI
The lab covers the installation and configuration of **TrueNAS** as the SAN solution. Using iSCSI, storage targets were created to allow multiple clients to access block-level storage.

Key Components:
- **TrueNAS Installation and Configuration**: Creating Zvols for clients and setting up management interfaces.
- **iSCSI Configuration**: Establishing iSCSI targets and extents for Windows, Linux, and ESXi clients.
- **RAID Configuration**: Setting up RAID 1 to ensure redundancy across the SAN storage.

### Authentication with CHAP (Challenge-Handshake Authentication Protocol)
This section focuses on securing the SAN using **one-way and mutual CHAP** authentication to control access between initiators and targets.

Key Components:
- Configuring **discovery authentication** with one-way CHAP.
- Implementing **mutual CHAP** for enhanced security between SAN clients and the TrueNAS target.
- Managing initiator groups to limit access based on IP addresses and IQNs.

### PXE Booting with DHCP and TFTP
PXE (Preboot Execution Environment) booting was implemented to allow networked machines to boot without local operating systems. This was achieved through the use of **TFTP and DHCP**.

Key Components:
- **TFTP Server Setup**: Configuring the server to distribute PXE boot files.
- **DHCP Configuration**: Setting up static IP reservations for clients.
- **BIOS Configuration**: Modifying boot sequences to enable PXE boot on client devices.
- Troubleshooting **PXE boot failures** and resolving DHCP conflicts.

## Key Takeaways
- **SAN Configuration**: Setting up storage environments with TrueNAS, iSCSI, and RAID.
- **Authentication**: Using CHAP for secure access to SAN targets.
- **Network Booting**: Implementing PXE boot to streamline device management.
- **Problem Solving**: Addressing issues related to DHCP, PXE, and CHAP authentication.

These labs provide valuable insights into configuring and managing storage networks, with a focus on security, redundancy, and efficiency.
