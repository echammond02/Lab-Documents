# Digital Forensics Lab Reports

This folder contains documentation for various digital forensics lab exercises. The labs focus on different aspects of forensic analysis, including file recovery, metadata analysis, data concealment methods, and investigation of system files using advanced forensic tools.

## Lab Summaries

### 1. **Concealment Methods**
   - **Objective**: Investigate different methods of concealing data within files and folders and use forensic tools to uncover hidden information.
   - **Tools Used**: Autopsy, WinHex, OpenStego, LADS (via Windows CMD).
   - **Key Techniques**:
     - Recovering hidden data using ADS (Alternate Data Streams).
     - Uncovering keys using steganography and brute-force password recovery.
     - Investigating hidden files using hex editors and forensic tools like Autopsy.

### 2. **File Headers and Hive**
   - **Objective**: Analyze file headers and metadata to retrieve important forensic information about user activities and system data.
   - **Tools Used**: WinHex, OSForensics, FTK Imager.
   - **Key Techniques**:
     - Examining Master File Tables (MFT) to extract file timestamps and modification details.
     - Analyzing user accounts and passwords stored in system files like SAM.dat.
     - Extracting and examining Windows registry files to track user login details and password changes.

### 3. **Live Drive Recovery**
   - **Objective**: Perform live recovery from a USB drive and compare different drive imaging techniques.
   - **Tools Used**: Windows PowerShell, FTK Imager, Autopsy.
   - **Key Techniques**:
     - Creating RAW (`.dd`) and E01 disk images using forensic tools.
     - Hash comparison to verify the integrity of image files.
     - Using Autopsy to inspect metadata and analyze files on the drive.

## Key Concepts

- Recovering hidden data from files using forensic tools.
- Analyzing file signatures and timestamps using hex editors.
- Extracting and investigating system files like the Windows registry and user account data.
- Drive imaging techniques for preserving evidence and ensuring data integrity.
- Using hashing algorithms to verify the authenticity of forensic images.
- Exploring metadata to uncover file origins and user activities.

Each lab includes detailed procedures, tool configurations, results, and troubleshooting steps, providing a comprehensive approach to digital forensic investigations.
