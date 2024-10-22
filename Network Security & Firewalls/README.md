
# Network Security & Firewalls Lab Reports

This folder contains documentation of labs focused on securing networks, deploying firewalls, configuring VPNs, and implementing central authentication. These labs explore practical security configurations, including VPNs for secure communication, RADIUS authentication, and setting up firewalls with robust rulesets.

## Lab Summaries

### 1. Reconnaissance Lab
This lab focuses on network reconnaissance and penetration testing techniques. It involves setting up virtual machines, including **Metasploitable** and **UltimateLAMP**, to simulate vulnerable systems. Using **Kali Linux**, various tools like **Nmap**, **Nessus**, and **Snort** were employed to identify open ports and vulnerabilities.

Key Components:
- Scanning and identifying vulnerable services using Nmap.
- Configuring IDS/IPS solutions (Suricata and Snort) for network monitoring.
- Launching SYN flood attacks to test system defenses and monitor IDS alerts.

### 2. VPN Configuration Lab
This lab explores the configuration of multiple **VPN types** to secure communication across remote sites and clients. The focus is on setting up **IPsec, OpenVPN, and L2TP VPNs** using both pfSense and VyOS.

Key Components:
- IPsec Site-to-Site VPNs for secure inter-site communication.
- OpenVPN client-access VPNs for remote user connectivity.
- Configuring LDAP-based Active Directory authentication for VPN access.
- Troubleshooting VPN connectivity and encryption issues.

### 3. Basic Network Configuration Lab
This lab involves the deployment of firewalls and DMZs to create a secure network architecture. Multiple **virtual machines** were provisioned, and **pfSense** and **VyOS** firewalls were configured to manage traffic and enforce security policies.

Key Components:
- Setting up **firewall rules** for inbound and outbound traffic control.
- Configuring NAT (SNAT, DNAT) for network translation.
- Deploying HTTP, FTP, and TFTP servers for testing firewall rules.
- Implementing DMZs to separate public and private network segments.

### 4. RADIUS and Central Authentication Lab
This lab explores **centralized authentication** using **RADIUS servers** and **Active Directory**. It also includes setting up **enterprise certificates** for secure VPN access and configuring a **captive portal** for guest users via pfSense.

Key Components:
- Configuring RADIUS authentication for Windows and Linux machines.
- Implementing LDAP authentication on pfSense and VyOS firewalls.
- Setting up a captive portal for controlled guest network access.
- Generating and deploying enterprise certificates for VPN connections.

## Key Takeaways
- **Network Security**: Configuring firewalls and intrusion detection/prevention systems.
- **VPN Management**: Establishing secure remote access with multiple VPN types.
- **Central Authentication**: Using RADIUS and Active Directory for user authentication.
- **Firewall Rules**: Enforcing security policies with NAT and DMZ configurations.

These labs provide comprehensive insights into securing networks through effective configurations, monitoring, and management of firewalls, VPNs, and authentication systems.
