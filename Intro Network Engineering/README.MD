# Intro Network Engineering Lab Reports

This folder contains documentation of labs focused on fundamental networking concepts. These labs explore essential topics such as VLAN configuration, NAT, routing protocols, physical network connections, and spanning tree protocols using Cisco and HP equipment. The objective is to develop hands-on networking skills applicable in enterprise environments.

## Lab Summaries

### 1. Physical Connections
This lab focuses on establishing physical network connections between multiple devices using Cisco 3750 switches. It includes:
- Configuring physical connections and terminal access through **CAT 5e/6 cables**.
- Resetting and configuring switches to enable network connectivity.
- Setting up **file sharing**, network adapter configurations, and duplex speed changes.
- Implementing **Wireshark** packet captures and **SPAN** sessions for network monitoring.

### 2. Intro to ACL and RIPv2
This lab involves the setup of **Routing Information Protocol (RIP)** and the implementation of **Access Control Lists (ACLs)** to manage traffic between devices:
- Removing **MSTP** from switches to enable PPP configurations.
- Configuring RIP for dynamic routing between multiple networks.
- Implementing **NAT and PAT** on routers for network address translation.
- Setting up a **TFTP server** for backup configurations and **ACLs** to control access.

### 3. Cisco Routing and MSTP
This lab explores the implementation of **Multiple Spanning Tree Protocol (MSTP)** to prevent loops in the network:
- Configuring routers and switches to establish root bridges and prevent broadcast storms.
- Setting up **DNS, DHCP, and VLANs** across Cisco and HP equipment.
- Using **SPAN sessions** and **Wireshark** to monitor network traffic.
- Shutting down unused ports to enhance security and ease network management.

### 4. VLANs and NAT
This lab focuses on VLAN and NAT configurations for traffic management and dynamic IP distribution:
- Configuring **VyOS wireless routers** with VLANs and DHCP for dynamic addressing.
- Setting up **NAT rules** to translate multiple IP addresses to a single external IP.
- Enabling **SSH** for secure remote access on Cisco switches.
- Configuring trunks to allow VLAN traffic across multiple switches.

## Key Takeaways
These labs provide hands-on experience with:
- **Network connectivity setup** through physical wiring and switch configurations.
- **Routing protocols** like RIP and dynamic IP management with DHCP.
- **VLANs and NAT** for traffic segmentation and efficient routing.
- **MSTP** implementation to prevent network loops and optimize path selection.
- **Network monitoring tools** like Wireshark for traffic analysis.
- **Security practices** through SSH access, ACLs, and port management.

These labs are designed to build foundational knowledge in network engineering, preparing learners to manage and troubleshoot networks in enterprise environments effectively.
