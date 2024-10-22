
# Penetration Testing Lab Reports

This folder contains documentation for labs focused on penetration testing techniques, including vulnerability scanning, service exploitation, and automation using bash scripting. These labs provide practical experience in offensive security practices, leveraging tools like Metasploit, Nmap, and Docker for testing and exploitation purposes.

## Lab Summaries

### 1. Vulnerability Scanning Lab
This lab explores the use of **Nessus** to perform vulnerability scans on a **Metasploitable** virtual machine. The focus is on identifying and exploiting discovered vulnerabilities to gain unauthorized access.

Key Components:
- Scanning for vulnerabilities using Nessus.
- Exploiting identified vulnerabilities, including **VNC Server** and **SSL flaws**.
- Practical use of **Metasploit** to gain remote access.
- Documenting findings and recommendations for hardening systems.

### 2. Auxiliary and Nmap Exploitation Lab
This lab covers the exploitation of outdated services, such as **VNC Viewer** and **Samba**, to demonstrate the importance of patch management. Additionally, **firewall configuration** is tested to highlight its impact on network visibility and security.

Key Components:
- Exploiting vulnerabilities in VNC Viewer and Samba using Metasploit.
- Patching software to prevent successful exploitation.
- Demonstrating how **firewalls block port scanning** and limit attacker visibility.
- Utilizing Nmap for network scanning and service enumeration.

### 3. Docker Bash Scripting Lab
This lab focuses on **automation** for offensive security using **bash scripts**. It covers Docker container management and automated scanning of Docker environments to simulate real-world penetration testing scenarios.

Key Components:
- Writing bash scripts to **start, stop, and manage Docker containers**.
- Extracting **IP addresses** from containers and automating Nmap scans.
- Separating active and inactive containers for efficient targeting.
- Automating **TCP and UDP port scanning** across all active containers.

## Key Takeaways
- **Vulnerability Identification and Exploitation**: Using tools like Nessus and Metasploit to discover and exploit vulnerabilities.
- **Patch Management**: Understanding the importance of timely patching to prevent exploitation.
- **Firewall Configuration**: Observing how firewalls impact port scanning and network security.
- **Bash Scripting for Automation**: Automating tasks to streamline penetration testing efforts.

These labs provide comprehensive insights into penetration testing techniques, including practical experience with vulnerability scanning, service exploitation, and automation for more effective security testing.
